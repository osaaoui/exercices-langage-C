#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void printTab(int rows, int cols, char tab[rows][cols]);
void insertCharacter(int rows, int cols, int x, int y, char letter, char tab[rows][cols]);
void compterLignes(const char *chemin, int *max, int *min);
void compterColonnes(const char *chemin, int *max, int *min);


int main(void) {
	
        char *chemin={"EEEENNNNW"};
	
        int i, j;
        int count=0;
        int maxLignes=0;
        int minLignes=0;
        
        int maxCol=0;
        int minCol=0;
        for(i=0; i < (strlen(chemin)); i++){
            count++;
        }
        compterLignes(chemin, &maxLignes, &minLignes);
        printf("Le minimum Lignes = %d\n", minLignes);
        //int *minLignes= &min;
        //int *maxLignes= &max;
        printf("Le minimum Lignes = %d\n", minLignes);
        printf("Le max Lignes = %d\n", maxLignes);
        
        compterColonnes(chemin, &maxCol, &minCol);
        //printf("Le minimum colonnes= %d\n", minCol);
        //int *minCol= &min;
        //int *maxCol= &max;
        printf("Le minimum col = %d\n", minCol);
        printf("Le max col = %d\n", maxCol);
        int rows= maxLignes + 1;
        int cols= maxCol + 1;
        printf("Rows = %d\n", rows);
        printf("Cols = %d\n", cols);
        int debutChemin= (maxLignes - maxCol);
        printf("Le debut du chemin= %d\n", debutChemin);
        
        //printf("Le minimum = %d", min);
        char tab[rows][cols];
        memset(tab, ' ', sizeof(tab));//fill under bar
        printf("taille chemin %d\n", count);
        //compterLignes(chemin, &max, &min);
        //compterColonnes(chemin, &max, &min);
        int abs= 0;
        int ordonnee= 0;
        for(i=0;i< count + 1;i++){
            
            
            
	insertCharacter(rows, cols, abs, ordonnee, 'x', tab);
        ++ordonnee;
        
        }
        //insertCharacter(rows, cols, 1, 0, 'x', tab);
        //insertCharacter(rows, cols, 0, 0, 'x', tab);
        //insertCharacter(rows, cols, 0, 2, 'x', tab);
        //insertCharacter(10, 15, 1, 0, 'x', tab);
        //insertCharacter(10, 15, 0, 0, 'x', tab);
        //insertCharacter(10, 15, 0, 1, 'x', tab);
        //insertCharacter(10, 15, 0, 2, 'x', tab);
	printTab(rows, cols, tab);
	return 0;
}
void compterLignes(const char *chemin, int *max, int *min){
    int compteurNord=0;
    int compteurSud=0;
    //int max=0;
    int i;
    for (i = 0; i < (strlen(chemin)); i++){
        if(chemin[i] == 'N'){
            //   printf("le caractere %c\n", chemin[i]);
            compteurNord++;
        }if(chemin[i]=='S'){
            compteurSud++;
        }

    }
    //printf("longueur du chemin: %lu\n",strlen(chemin));
    printf("compteur caractere N: %d\n", compteurNord);

    printf("compteur caractere S: %d\n", compteurSud);
    if (compteurNord > compteurSud){

        *max= compteurNord;
        *min= compteurSud;
        printf("N est Max. Nombre de lignes=: %d\n", compteurNord + 1);
    }else if(compteurNord < compteurSud){
        *max= compteurSud;
        *min= compteurNord;
        printf("S est MaX. Nombre de lignes = %d\n", compteurSud + 1);
    }else if(compteurNord ==0 && compteurSud==0){
        *max=1;
        printf("N==0 et S==0. donc max = %d\n", max);
    }else if(compteurNord== compteurSud){
        *max= compteurNord + 1;
        printf("N == S. Nombre de Lignes= %d\n", compteurNord + 1);
    }
   
}





void compterColonnes(const char *chemin, int *max, int *min){
    int compteurEst=0;
    int compteurWest=0;
    //int max=0;
    //int min=0;
    int i;
    for (i = 0; i < (strlen(chemin)); i++){
        if(chemin[i] == 'E'){
            //   printf("le caractere %c\n", chemin[i]);
            compteurEst++;
        }if(chemin[i]=='W'){
            compteurWest++;
        }

    }
    //printf("longueur du chemin: %lu\n",strlen(chemin));
    printf("compteur caractere E: %d\n", compteurEst);

    printf("compteur caractere W: %d\n", compteurWest);
    if (compteurEst > compteurWest){

        *max= compteurEst;
        *min= compteurWest;
        printf("E est Max. Nombre de colonnes= %d\n", compteurEst + 1);
    }else if(compteurEst < compteurWest){
        *max= compteurWest;
        *min= compteurEst;
        printf("W est Max. Nombre de colonnes = %d\n", compteurWest + 1);
    }else if(compteurEst==0 && compteurWest==0){
        *max=1;
        printf("E et W=0, donc max = %d\n", max);
    } else if(compteurEst== compteurWest){
        *max= compteurEst +1;
        printf("E == W. Nombre de colonnes= %d\n", compteurEst + 1);
    }
    //return max;
}
 
void insertCharacter(int rows, int cols, int x, int y, char letter, char tab[rows][cols]) {
	tab[x][y] = letter;
}
 
void printTab(int rows, int cols, char tab[rows][cols]){
	int i, j;
 
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			printf("%c", tab[i][j]);
		}
		printf("\n");
	}
}