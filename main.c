#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Rectangle {
    int xmin;
    int xmax;
    int ymin;
    int ymax;

};
void initialiserRectangle(struct Rectangle *rect, int *lignes, int *colonnes);

void printTab(int rows, int cols, char tab[rows][cols]);
void insererCaractere(int rows, int cols, int x, int y, char letter, char tab[rows][cols]);
int compterLignes(const char *chemin);
int compterColonnes(const char *chemin);
void afficherChemin(const char *chemin, int lignes, int colonnes, int abscisse, int ordonnee, char lettre,
        char tab[lignes][colonnes]);

int main(void) {

    char *chemin = {"EEEENNWWSSSS"};

    int i, j;
    int count = 0;
    int lignes = 10;
    int colonnes = 14;

    int abscisse = 4;
    int ordonnee = 6;

    int maxLignes = 0;
    int maxCol = 0;
    int abscDansDessin = abscisse;
    int ordoDansDessin = ordonnee;
    
    
    char tab[lignes][colonnes];
    
    
     afficherChemin(chemin, lignes, colonnes, abscisse, ordonnee, 'w',
        tab);
    //fill under bar
    printf("taille chemin %d\n", count);
    maxLignes = compterLignes(chemin);
    maxCol = compterColonnes(chemin);
    
    struct Rectangle rect;
    initialiserRectangle(&rect, &maxLignes, &maxCol);
    int abscisseRectangle= debutChemin(abscDansDessin, maxLignes);
    int ordonneeRectangle= rect.ymin;
    // Affichage du rectangle
    char tabRectangle[maxLignes][maxCol];
    afficherChemin(chemin, maxLignes, maxCol, abscisseRectangle, ordonneeRectangle, 'w',
        tabRectangle);
    
    
    printf("Nombre de N ou S: lignes = %d\n", maxLignes);
    printf("Nombre de E ou W: colonnes = %d\n", maxCol);
    
    printf("xmin, ymin = (%d, %d)\n", rect.xmin, rect.ymin);
    printf("xmin, ymax = (%d, %d)\n", rect.xmin, rect.ymax);
    printf("xmax, ymin = (%d, %d)\n", rect.xmax, rect.ymin);
    printf("xmax, ymiax = (%d, %d)\n", rect.xmax, rect.ymax);

    printf("maxCol = %d\n", maxCol);
    printf("ordonnee = %d\n", abscDansDessin);
    printf("ordonnee + maxCol = %d\n", ordoDansDessin + maxCol);

    int debut = debutChemin(abscDansDessin, maxLignes);
    printf("maxLignes = %d\n", maxLignes);
    //printf("abscisse = %d\n", absc);
    printf("abscisse + maxCol = %d\n", abscDansDessin - maxLignes);
    printf("debut dans Dessin = %d\n", debut);
    //int debut=
    printTab(maxLignes, maxCol, tabRectangle);


    return 0;
}

void afficherChemin(const char *chemin, int lignes, int colonnes, int abscisse, int ordonnee, char lettre,
        char tab[lignes][colonnes]) {
    int i, count;
    struct Rectangle rect;
    int maxLignes = compterLignes(chemin);
    int maxCol = compterColonnes(chemin);
    initialiserRectangle(&rect, &maxLignes, &maxCol);
    for (i = 0; i < (strlen(chemin)); i++) {
        if (chemin[i] == 'E') {
            count++;
            insererCaractere(lignes, colonnes, abscisse, ordonnee, lettre, tab);
            insererCaractere(lignes, colonnes, abscisse, ordonnee + 1,lettre, tab);
            ordonnee++;
        }
        abscisse = abscisse;
        ordonnee = ordonnee;
        if (chemin[i] == 'N') {
            insererCaractere(lignes, colonnes, --(abscisse), ordonnee, lettre, tab);

        }
        abscisse = abscisse++;
        ordonnee = ordonnee;
        if (chemin[i] == 'S') {
            insererCaractere(lignes, colonnes, ++(abscisse), ordonnee, lettre, tab);
        }
        if (chemin[i] == 'W') {
            insererCaractere(lignes, colonnes, abscisse, --(ordonnee), lettre, tab);
        }
    }

}

int debutChemin(int abscisseOrigine, int maxLignes) {
    int debut = 0;
    int zeroZeroDansDessin = abscisseOrigine - maxLignes;
    if (zeroZeroDansDessin > 0) {
        zeroZeroDansDessin = zeroZeroDansDessin;
    } else if (zeroZeroDansDessin < 0) {
        zeroZeroDansDessin = -zeroZeroDansDessin + 1;
    }
    debut = abscisseOrigine - zeroZeroDansDessin;
    return debut;
}

void initialiserRectangle(struct Rectangle *rect, int *lignes, int *colonnes) {
    rect->xmin = 0;
    rect->xmax = *lignes;

    rect->ymin = 0;
    rect->ymax = *colonnes;

}

int compterLignes(const char *chemin) {
    int compteurNord = 0;
    int compteurSud = 0;
    int max = 0;
    int i;
    for (i = 0; i < (strlen(chemin)); i++) {
        if (chemin[i] == 'N') {

            compteurNord++;
        }
        if (chemin[i] == 'S') {
            compteurSud++;
        }

    }

    if (compteurNord > compteurSud) {

        max = compteurNord;

        //printf("N est Max. Nombre de lignes=: %d\n", compteurNord);
    } else if (compteurNord < compteurSud) {
        max = compteurSud;

        //printf("S est MaX. Nombre de lignes = %d\n", compteurSud);
    } else if (compteurNord == 0 && compteurSud == 0) {
        max = 0;
        //printf("N==0 et S==0. donc max = %d\n", max);
    } else if (compteurNord == compteurSud) {
        max = compteurNord;
        //printf("N == S. Nombre de Lignes= %d\n", compteurNord);
    }
    return max;
}

int compterColonnes(const char *chemin) {
    int compteurEst = 0;
    int compteurWest = 0;
    int max = 0;
    int i;
    for (i = 0; i < (strlen(chemin)); i++) {
        if (chemin[i] == 'E') {

            compteurEst++;
        }
        if (chemin[i] == 'W') {
            compteurWest++;
        }

    }

    if (compteurEst > compteurWest) {

        max = compteurEst;

        //printf("E est Max. Nombre de lignes=: %d\n", compteurEst);
    } else if (compteurEst < compteurWest) {
        max = compteurWest;

        //printf("W est MaX. Nombre de lignes = %d\n", compteurWest);
    } else if (compteurEst == 0 && compteurWest == 0) {
        max = 0;
        //printf("N==0 et S==0. donc max = %d\n", max);
    } else if (compteurEst == compteurWest) {
        max = compteurEst;
        //printf("N == S. Nombre de Lignes= %d\n", compteurEst);
    }
    return max;
}

void printTab(int rows, int cols, char tab[rows][cols]) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%c ", tab[i][j]);
        }
        printf("\n");
    }
}

void insererCaractere(int rows, int cols, int x, int y, char letter, char tab[rows][cols]) {
    tab[x][y] = letter;
}
