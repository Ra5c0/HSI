/**
 * @file tp2.c
 * @brief Programme de démonstration pour les fonctions de manipulation.
 * @author Oscar Gigon
 * @date 21/09/2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

/**
 * @brief Calcule la somme des éléments d'un tableau de flottants.
 *
 * @param a Pointeur vers le tableau de flottants.
 * @param length Nombre d'éléments dans le tableau.
 * @return Somme des éléments du tableau.
 */
float sum_elements(float* a, unsigned length) { 
    int i; 
    float result = 0; 
    for (i = 0; i < length; i++) 
        result += a[i]; 
    return result;
} 

/**
 * @brief Compare les longueurs de deux chaînes de caractères.
 *
 * @param s Première chaîne de caractères.
 * @param t Deuxième chaîne de caractères.
 * @return 1 si la première chaîne est plus longue que la deuxième, sinon 0.
 */
int strlonger(char* s, char* t) { 
    return (strlen(s) > strlen(t)); 
} 

/**
 * @brief Vérifie si un entier x peut être représenté avec n bits.
 *
 * @param x Entier à vérifier.
 * @param n Nombre de bits à utiliser.
 * @return 1 si x peut être représenté avec n bits, sinon 0.
 */
int fits_bits(int x, int n) {
    int diff = 32 + (~n + 1);
    return !(x ^ ((x << diff) >> diff)); 
}

/**
 * @brief Vérifie si un entier non signé a un nombre impair de bits à 1.
 *
 * @param x Entier non signé.
 * @return 1 si x a un nombre impair de bits à 1, sinon 0.
 */
int odd_ones(unsigned x){
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;
    return (x & 1);
}

/**
 * @brief Affiche un menu et demande à l'utilisateur de choisir une option.
 *
 * @return Choix de l'utilisateur.
 */
int menu(void) {
    int choix;
    printf("-- Menu --\n\nQuestion 1\nQuestion 2\nQuestion 3\nQuestion 4\nQuestion 5\n\n");
    printf("Quel est votre choix ?\n\n");
    scanf("%d", &choix);
    return (choix);
}

/**
 * @brief Fonction principale pour tester les fonctions implémentées.
 *
 * @return 0 en cas de succès.
 */
int main() {

    int size = 5;
    float *a;
    char *s;
    char *t;

    switch (menu()) {
    case 1:
        printf("Question 1 :\n\n");
        a = malloc(size * sizeof(float));
        printf("  Tableau : ");
        for (int i = 0; i < size; i++) {
            a[i] = ((float)rand() / (float)(RAND_MAX)) * 5.0;
            printf("%f  ", a[i]);
        } 
        printf("\n  Somme des éléments du tableau : %f\n\n", sum_elements(a, size));
        break;

    case 2:
        printf("Question 2 :\n\n");
        s = "bonjour";
        t = "salut";
        printf("  %s est plus long que %s : %d\n\n",s,t,strlonger(s,t));
        t = "bonjour";
        s = "salut";
        printf("  %s est plus long que %s : %d\n\n",s,t,strlonger(s,t));
        break;

    case 3:
        printf("Question 3 :\n\n");
        printf("  1) (x > 0) || (x-1 < 0) : Faux\n  Si on a x égal à -2 147 483 648, alors x-1 est égal à 2147483647.\n");
        printf("  2) (x & 7) != 7 || (x<<29 < 0) : Vrai\n  Si (x & 7) est différent de 7, alors le bit x2 doit être égal à 1. Lorsqu'il est décalé vers la gauche de 29, il devient le bit de signe.\n");
        printf("  3) (x * x) >= 0 : Faux\n  Lorsque x vaut 65 535 (0xFFFF), x*x vaut -131 071 (0xFFFE0001).\n");
        printf("  4) x < 0 || -x <= 0 : Vrai\n  Si x est négatif, alors -x est non positif.\n");
        printf("  5) x > 0 || -x >= 0 : Faux\n  Si on a x égal à -2 147 483 648, alors x et -x sont tous deux négatifs.\n");
        printf("  6) x+y == uy+ux : Vrai\n  Le complément à deux et l'addition non signée ont le même comportement au niveau des bits.\n");
        printf("  7) x*~y + uy*ux == -x : Vrai\n  ~y est égal à -y-1. uy*ux est égal à x*y. Donc le côté gauche est équivalent à x*-y-x+x*y.\n\n");
        break;

    case 4:
        printf("Question 4 :\n\n");
        printf("  fits_bits(5.3) = %d\n", fits_bits(5,3));
        printf("  fits_bits(-4,3) = %d\n\n", fits_bits(-4,3));
        break;

    case 5:
        printf("Question 5 :\n\n");
        printf("  x contient un nombre impair de 1 : %d\n\n", odd_ones(0x0111));
        break;
    
    default:
        printf("\n Saisie incorrecte ! Veuillez choisir un entier entre 1 et 5 ! \n\n");
        break;
    }

    return 0;
}
