#ifndef DRV_API_H_
#define DRV_API_H_

#include <stdint.h>
#include <stddef.h>

#define DRV_SUCCESS 0
#define DRV_ERROR   -1

#define DRV_MAX_FRAME_SIZE      (255)
#define DRV_MAX_FRAME_READ      (8)
#define DRV_UDP_10MS_FRAME_SIZE (14)
#define DRV_UDP_20MS_FRAME_SIZE (9)

typedef struct {
    uint32_t serNum;                    /* Numéro de série physique */
    uint8_t frame[DRV_MAX_FRAME_SIZE];  /* Trame reçue/à écrire */
    size_t frameSize;                   /* Taille de la trame reçue */
} lns_frame_t;

// Déclaration des fonctions
int32_t drv_open(const char *ip_address, int port);  // Ouvre une connexion au driver

int32_t drv_read_udp_10ms(int32_t drvFd, uint8_t udpFrame[DRV_UDP_10MS_FRAME_SIZE]);
int32_t drv_write_udp_20ms(int32_t drvFd, uint8_t udpFrame[DRV_UDP_20MS_FRAME_SIZE]);

int32_t drv_read_lns(int32_t drvFd, lns_frame_t lnsData[DRV_MAX_FRAME_READ], uint32_t lnsDataLen);
int32_t drv_write_lns(int32_t drvFd, lns_frame_t* lnsData, uint32_t lnsDataLen);

int32_t drv_close(int32_t drvFd);  // Ferme la connexion avec le driver

#endif  // DRV_API_H_
