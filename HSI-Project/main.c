#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "drv_api.h"

#define UDP_FRAME_SIZE 14
#define LNS_FRAME_DISPLAY_SIZE 8 // Nombre d'octets à afficher pour les trames LNS

typedef struct {
    uint8_t data[UDP_FRAME_SIZE];
} udp_frame_t;

int main() {
    int32_t fd = drv_open("127.0.0.1", 9002);
    if (fd < 0) {
        printf("Erreur lors de la connexion au driver.\n");
        return -1;
    }
    printf("Connexion au driver réussie, descripteur de fichier : %d\n", fd);

    // Gestion des trames UDP
    udp_frame_t udpFrame;
    memcpy(udpFrame.data, "\x00\x00\x00\x00\x01\x00\x00\x67\xa6\x00\x00\x00\x22\x00", UDP_FRAME_SIZE);
    
    printf("Trame UDP reçue : ");
    for (size_t i = 0; i < UDP_FRAME_SIZE; ++i) {
        printf("%02x ", udpFrame.data[i]);
    }
    printf("\n");

    // Écrire la trame UDP
    int sendResult = drv_write_udp_20ms(fd, udpFrame.data);
    if (sendResult != DRV_SUCCESS) {
        printf("Erreur lors de l'envoi de la trame UDP. Code erreur : %d\n", sendResult);
    } else {
        printf("Trame UDP de 20ms envoyée avec succès.\n");
    }

    // Initialisation des données LNS
    lns_frame_t lnsData[DRV_MAX_FRAME_READ];
    memset(lnsData, 0, sizeof(lnsData));

    // Lecture des trames LNS
    int result = drv_read_lns(fd, lnsData, DRV_MAX_FRAME_READ);

    if (result != DRV_SUCCESS) {
        printf("Erreur lors de la lecture des trames LNS. Code erreur : %d\n", result);
    } else {
        printf("Trames LNS reçues :\n");
        for (size_t i = 0; i < DRV_MAX_FRAME_READ; ++i) {
            printf("LNS Frame %zu: frameSize = %zu\n", i, lnsData[i].frameSize);
            printf("Contenu brut de la trame LNS %zu : ", i);
            // Affichage abrégé
            for (size_t j = 0; j < LNS_FRAME_DISPLAY_SIZE && j < lnsData[i].frameSize; ++j) {
                printf("%02x ", lnsData[i].frame[j]);
            }
            printf("\n");

            if (lnsData[i].frameSize > 0 && lnsData[i].frameSize <= DRV_MAX_FRAME_SIZE) {
                printf("Trame LNS %zu : Taille : %zu, Contenu : ", i, lnsData[i].frameSize);
                for (size_t j = 0; j < lnsData[i].frameSize; ++j) {
                    printf("%02x ", lnsData[i].frame[j]);
                }
                printf("\n");
            } else {
                printf("Taille de la trame LNS %zu invalide: %zu\n", i, lnsData[i].frameSize);
            }
        }
    }

    drv_close(fd);
    printf("Connexion fermée avec succès.\n");

    return 0;
}
