/**
 * @file tp1.c
 * @brief Programme de démonstration pour les structures et les fonctions associées.
 * @author Oscar Gigon
 * @date 21/09/2022
 */

#include <stdio.h>

// Structure rec pour la question 1
struct rec { 
    char *a;    /**< Pointeur vers un caractère */
    short b;    /**< Entier court */
    double c;   /**< Double précision */
    char d;     /**< Caractère */
    float e;    /**< Flottant */
    char f;     /**< Caractère */
    long g;     /**< Entier long */
    int h;      /**< Entier */
};

/**
 * @brief Affiche les offsets des membres de la structure rec.
 */
void printOffsets() {
    printf("Offsets des membres de la structure rec :\n");
    printf("a : %lu\n", (unsigned long)&(((struct rec *)0)->a));
    printf("b : %lu\n", (unsigned long)&(((struct rec *)0)->b));
    printf("c : %lu\n", (unsigned long)&(((struct rec *)0)->c));
    printf("d : %lu\n", (unsigned long)&(((struct rec *)0)->d));
    printf("e : %lu\n", (unsigned long)&(((struct rec *)0)->e));
    printf("f : %lu\n", (unsigned long)&(((struct rec *)0)->f));
    printf("g : %lu\n", (unsigned long)&(((struct rec *)0)->g));
    printf("h : %lu\n", (unsigned long)&(((struct rec *)0)->h));
}

/**
 * @brief Affiche la taille totale de la structure rec.
 */
void printSize() {
    printf("Taille totale de la structure rec : %lu octets\n", (unsigned long)sizeof(struct rec));
}

// Structure et Union pour la question 2
typedef struct { 
    char c;         /**< Caractère */
    double *p;      /**< Pointeur vers un double */
    int i;          /**< Entier */
    double d;       /**< Double précision */
    short s;        /**< Entier court */
} structtpd;

typedef union { 
    char c;         /**< Caractère */
    double *p;      /**< Pointeur vers un double */
    int i;          /**< Entier */
    double d;       /**< Double précision */
    short s;        /**< Entier court */
} uniontpd;

/**
 * @brief Affiche la taille et l'alignement de structtpd.
 */
void printStructtpdInfo() {
    printf("Taille de structtpd : %lu octets\n", (unsigned long)sizeof(structtpd));
}

/**
 * @brief Affiche la taille et l'alignement de uniontpd.
 */
void printUniontpdInfo() {
    printf("Taille de uniontpd : %lu octets\n", (unsigned long)sizeof(uniontpd));
}

// Tableau 3D et fonction pour la question 3
#define R 3
#define S 5
#define T 8

long A[R][S][T]; /**< Tableau 3D */

/**
 * @brief Accède à un élément du tableau A et retourne sa taille.
 *
 * @param i Indice i.
 * @param j Indice j.
 * @param k Indice k.
 * @param dest Pointeur où stocker l'élément.
 * @return Taille du tableau A en octets.
 */
long store_ele(long i, long j, long k, long *dest) {
    *dest = A[i][j][k];
    return (long)sizeof(A);
}

/**
 * @brief Fonction principale pour tester les fonctionnalités du script.
 *
 * @return 0 en cas de succès.
 */
int main() {
    int choix;

    do {
        // Affichage du menu
        printf("\n-- Menu --\n");
        printf("1. Afficher les offsets des membres de la structure rec\n");
        printf("2. Afficher la taille totale de la structure rec\n");
        printf("3. Afficher la taille et l'alignement de structtpd\n");
        printf("4. Afficher la taille et l'alignement de uniontpd\n");
        printf("5. Tester la fonction store_ele\n");
        printf("0. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);

        // Sélection de l'action en fonction du choix
        switch (choix) {
            case 1:
                printOffsets();
                break;
            case 2:
                printSize();
                break;
            case 3:
                printStructtpdInfo();
                break;
            case 4:
                printUniontpdInfo();
                break;
            case 5:
                {
                    // Tester la fonction store_ele
                    long i, j, k, dest;
                    printf("Entrez les indices (i, j, k) pour acceder a A[i][j][k] : ");
                    scanf("%ld %ld %ld", &i, &j, &k);
                    long size = store_ele(i, j, k, &dest);
                    printf("Valeur de A[%ld][%ld][%ld] : %ld\n", i, j, k, dest);
                    printf("Taille du tableau A : %lu octets\n", (unsigned long)size);
                    break;
                }
            case 0:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
                break;
        }

    } while (choix != 0); // Répéter tant que l'utilisateur ne choisit pas de quitter (0)

    return 0;
}
