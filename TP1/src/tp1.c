/**
 * @file tp1.c
 * @brief Programme de démonstration pour les fonctions de manipulation.
 * @author Oscar Gigon
 * @date 21/09/2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/**
 * @brief Effectue un échange de valeurs sans utiliser de variable temporaire.
 *
 * @param x Pointeur vers la première valeur.
 * @param y Pointeur vers la deuxième valeur.
 */
void inplace_swap(int *x, int *y) {
    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
}

/**
 * @brief Inverse les éléments d'un tableau d'entiers.
 *
 * @param a Tableau d'entiers.
 * @param cnt Nombre d'éléments dans le tableau.
 */
void reverse_array(int a[], int cnt) {
    int first, last;
    for (first = 0, last = cnt - 1; first < last; first++, last--) {
        inplace_swap(&a[first], &a[last]);
    }
}

/**
 * @brief Affiche le résultat d'un opérateur de masque binaire sur deux entiers.
 *
 * @param x Premier entier.
 * @param y Deuxième entier.
 */
void returnLSB(int32_t x, int32_t y) {
    int32_t z = 0x000000FF; 
    printf("  %x \n", (z & x) | (~z & y));
}

/**
 * @brief Vérifie si au moins un bit de l'entier est égal à 1.
 *
 * @param x Entier à vérifier.
 * @return 1 si au moins un bit de x est égal à 1, sinon 0.
 */
int bitone(unsigned x)
{
    return (x != 0);
}

/**
 * @brief Vérifie si au moins un bit de l'entier est égal à 0.
 *
 * @param x Entier à vérifier.
 * @return 1 si au moins un bit de x est égal à 0, sinon 0.
 */
int bitzero(unsigned x)
{
    return (~x != 0);
}

/**
 * @brief Extrait l'octet le moins significatif de l'entier.
 *
 * @param x Entier dont on souhaite extraire l'octet le moins significatif.
 * @return Octet le moins significatif de x.
 */
int fn_lsb(unsigned x)
{
    return (x & 0x0000FFFF);
}

/**
 * @brief Extrait l'octet le plus significatif de l'entier.
 *
 * @param x Entier dont on souhaite extraire l'octet le plus significatif.
 * @return Octet le plus significatif de x.
 */
int fn_msb(unsigned x)
{
    return (x & 0xFFFF0000);
}

/**
 * @brief Effectue une rotation vers la gauche de n bits sur un entier non signé.
 *
 * @param x Entier à faire tourner.
 * @param n Nombre de bits à décaler.
 * @return Entier avec la rotation appliquée.
 */
unsigned rotate_left(unsigned x, int n) {
    int a = sizeof(unsigned) << 3;
    unsigned b = x >> (a - n);
    unsigned c = x << n;
    return c | b;
}

/**
 * @brief Affiche un menu et demande à l'utilisateur de choisir une option.
 *
 * @return Choix de l'utilisateur.
 */
int menu(void) {
    int choix;
    
    printf("-- Menu --\n\n");
    printf("1. Question 1\n");
    printf("2. Question 2\n");
    printf("3. Question 3\n");
    printf("4. Question 4\n\n");
    
    printf("Quel est votre choix ? ");
    scanf("%d", &choix);

    return choix;
}

/**
 * @brief Fonction principale pour tester les fonctions implémentées.
 *
 * @return 0 en cas de succès.
 */
int main() {

    int size = 5;
    int *a;
    unsigned x;
    int lsb;
    int msb;

    switch (menu()) {
    case 1:
        printf("Question 1 :\n\n");
        a = malloc(size * sizeof(int));
        printf("  tableau initial : ");
        for(int i = 0; i < size; i++) {
            a[i] = rand() % 10 + 1;
            printf("%d  ", a[i]);
        }
        printf("\n");    
        reverse_array(a, size);
        printf("  tableau inverse : ");
        for(int i = 0; i < size; i++) {
            printf("%d  ", a[i]);
        }
        printf("\n\n");
        break;

    case 2:
        printf("Question 2 :\n\n");
        returnLSB(0x89ABCDEF,0x76543210);        
        printf("\n");
        break;

    case 3:
        printf("Question 3 :\n\n");
        printf("Saisir x :\n");
        scanf("%d",&x);
        lsb = fn_lsb(x);
        msb = fn_msb(x);
        printf(" Pour x=%d : \n",x);
        printf(" 1. Au moins un bit de x est égal à 1 : %d \n", bitone(x));
        printf(" 2. Au moins un bit de x est égal à 0 : %d\n", bitzero(x));
        printf(" 3. Au moins un bit de l'octet le moins significatif (%.8x) de x est égal à 1 : %d\n", lsb,bitone(lsb));
        printf(" 4. Au moins un bit de l'octet le plus significatif (%.8x) de x est égal à 0 : %d\n\n", msb,bitzero(msb));
        break;

    case 4:
        printf("Question 4 :\n\n");
        printf("  n = 0 : 0x%.8x\n", rotate_left(0x12345678, 0));
        printf("  n = 4 : 0x%.8x\n", rotate_left(0x12345678, 4));
        printf("  n = 20 : 0x%.8x\n\n", rotate_left(0x12345678, 20));
        break;
    
    default:
        printf("\n Saisie incorrecte ! Veuillez choisir un entier entre 1 et 4 ! \n\n");
        break;
    }

    return 0;
}
