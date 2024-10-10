/**
 * @file tp3.c
 * @brief Programme de démonstration pour les fonctions de manipulation.
 * @author Oscar Gigon
 * @date 22/09/2022
 */

#include <stdio.h>

/**
 * @brief Fonction pour échanger les valeurs de deux entiers.
 *
 * @param xp Pointeur vers le premier entier.
 * @param yp Pointeur vers le deuxième entier.
 */
void swap(int *xp, int *yp) {
    int t0 = *xp;
    int t1 = *yp;
    *xp = t1;
    *yp = t0;
}
/*
tp3.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <swap>:
   0:   f3 0f 1e fa             endbr64 
   4:   8b 07                   mov    (%rdi),%eax
   6:   8b 16                   mov    (%rsi),%edx
   8:   89 17                   mov    %edx,(%rdi)
   a:   89 06                   mov    %eax,(%rsi)
   c:   c3                      retq  
*/

/* Question 2
1)  
2) taille du suffixe d'instruction != taille id du registre
3) on peut pas avoir une source et une destination mémoire ensemble
4) Il n'existe pas de registre %sl
5) 0x123 ne peut pas être une destination
6) %dx n'est pas de la bonne taille
7) taille du suffixe d'instruction != taille id du registre
*/

/**
 * @brief Fonction pour effectuer un échange de valeurs entre trois entiers pointés.
 *
 * @param xp Pointeur vers le premier entier.
 * @param yp Pointeur vers le deuxième entier.
 * @param zp Pointeur vers le troisième entier.
 */
void decode1(long *xp, long *yp, long *zp) {
    int var_8 = *xp;
    int var_c = *yp;
    int var_a = *zp;
    *yp = var_8;
    *zp = var_c;
    *xp = var_a;
}

/**
 * @brief Fonction pour décoder une valeur en utilisant des opérations arithmétiques.
 *
 * @param x Valeur entière.
 * @param y Valeur entière.
 * @param z Valeur entière.
 * @return Résultat de l'opération de décodage.
 */
long decode2(long x, long y, long z) {
    z = z - y;
    long var_a = z;
    var_a = var_a<<63;
    var_a = var_a>>63;
    z = z * x;
    var_a = var_a ^ z;
    return var_a;
}

/* Question 5 
1) x => %rdx / y => %rcx / n => %rax 
2) leaq : change l'addresse et non la valeure
*/

/* Question 6 
1) Les valeurs de cas dans le switch vont de 0 à 8
2) 1 et 8, 3 et 5, 4 et 7 ont des multiples labels
*/ 

/**
 * @brief Fonction pour retourner la valeur pointée par un pointeur, ou 0 si le pointeur est nul.
 *
 * @param xp Pointeur vers une valeur.
 * @return Valeur pointée par xp, ou 0 si xp est NULL.
 */
long cread_alt(long *xp) {
    return (!xp ? 0 : *xp);
}

/**
 * @brief Fonction principale pour tester les fonctions implémentées.
 *
 * @return 0 en cas de succès.
 */
int main() {
    int choix;

    do {
        // Affichage du menu
        printf("\n-- Menu --\n");
        printf("1. Tester la fonction swap\n");
        printf("2. Tester la fonction decode1\n");
        printf("3. Tester la fonction decode2\n");
        printf("4. Tester la fonction cread_alt\n");
        printf("0. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);

        // Sélection de l'action en fonction du choix
        switch (choix) {
            case 1:
                {
                    // Tester la fonction swap
                    int a = 10, b = 20;
                    printf("Avant swap : a = %d, b = %d\n", a, b);
                    swap(&a, &b);
                    printf("Après swap : a = %d, b = %d\n", a, b);
                    break;
                }
            case 2:
                {
                    // Tester la fonction decode1
                    long x = 1, y = 2, z = 3;
                    printf("Avant decode1 : x = %ld, y = %ld, z = %ld\n", x, y, z);
                    decode1(&x, &y, &z);
                    printf("Après decode1 : x = %ld, y = %ld, z = %ld\n", x, y, z);
                    break;
                }
            case 3:
                {
                    // Tester la fonction decode2
                    long res = decode2(10, 20, 30);
                    printf("Résultat de decode2 : %ld\n", res);
                    break;
                }
            case 4:
                {
                    // Tester la fonction cread_alt
                    long value = 42;
                    long *ptr = &value;
                    long result = cread_alt(ptr);
                    printf("Valeur obtenue avec cread_alt : %ld\n", result);
                    break;
                }
            case 0:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
                break;
        }

    } while (choix != 0); // Répéter tant que l'utilisateur ne choisit pas de quitter (0)

    return 0;
}