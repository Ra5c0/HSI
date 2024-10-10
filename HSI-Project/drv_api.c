#include "drv_api.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>  // Pour close()
#include <arpa/inet.h>  // Pour inet_pton(), htons()
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

// Fonction pour ouvrir une connexion au driver
int32_t drv_open(const char *ip_address, int port) {
    int sockfd;
    struct sockaddr_in serv_addr;

    // Crée une socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);  // Utilisation de TCP, ou SOCK_DGRAM pour UDP
    if (sockfd < 0) {
        perror("Erreur lors de la création de la socket");
        return DRV_ERROR;
    }

    // Configurer l'adresse du serveur
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);  // Convertir le port en format réseau
    if (inet_pton(AF_INET, ip_address, &serv_addr.sin_addr) <= 0) {
        perror("Adresse IP invalide");
        close(sockfd);
        return DRV_ERROR;
    }

    // Tente de se connecter au serveur
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Échec de la connexion au driver");
        close(sockfd);
        return DRV_ERROR;
    }

    // Retourne le descripteur de socket (fd)
    return sockfd;
}

// Fonction pour lire une trame UDP de 10ms
int32_t drv_read_udp_10ms(int32_t sockfd, uint8_t udpFrame[DRV_UDP_10MS_FRAME_SIZE]) {
    int bytes_read;

    // Attente de la trame UDP (ici une lecture simulée)
    bytes_read = recv(sockfd, udpFrame, DRV_UDP_10MS_FRAME_SIZE, 0);
    if (bytes_read < 0) {
        perror("Erreur lors de la lecture de la trame UDP");
        return DRV_ERROR;
    }

    return DRV_SUCCESS;
}

// Fonction pour écrire une trame UDP de 20ms
int32_t drv_write_udp_20ms(int32_t sockfd, uint8_t udpFrame[DRV_UDP_20MS_FRAME_SIZE]) {
    int bytes_written;

    // Envoi de la trame UDP
    bytes_written = send(sockfd, udpFrame, DRV_UDP_20MS_FRAME_SIZE, 0);
    if (bytes_written < 0) {
        perror("Erreur lors de l'envoi de la trame UDP");
        return DRV_ERROR;
    }

    return DRV_SUCCESS;
}

// Fonction pour lire une trame LNS
int32_t drv_read_lns(int32_t sockfd, lns_frame_t lnsData[DRV_MAX_FRAME_READ], uint32_t lnsDataLen) {
    int bytes_read;

    // Lecture de la trame LNS avec la taille lnsDataLen
    bytes_read = recv(sockfd, lnsData, sizeof(lns_frame_t) * lnsDataLen, 0);
    if (bytes_read < 0) {
        perror("Erreur lors de la lecture de la trame LNS");
        return DRV_ERROR;
    }

    return DRV_SUCCESS;
}

// Fonction pour écrire une trame LNS
int32_t drv_write_lns(int32_t sockfd, lns_frame_t* lnsData, uint32_t lnsDataLen) {
    int bytes_written;

    // Envoi de la trame LNS avec la taille lnsDataLen
    bytes_written = send(sockfd, lnsData, sizeof(lns_frame_t) * lnsDataLen, 0);
    if (bytes_written < 0) {
        perror("Erreur lors de l'envoi de la trame LNS");
        return DRV_ERROR;
    }

    return DRV_SUCCESS;
}

// Fonction pour fermer la connexion avec le driver
int32_t drv_close(int32_t sockfd) {
    if (close(sockfd) < 0) {
        perror("Erreur lors de la fermeture de la connexion");
        return DRV_ERROR;
    }
    return DRV_SUCCESS;
}
