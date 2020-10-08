/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: student
 *
 * Created on October 7, 2020, 6:03 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * 
 */

//tri par selection

void TriSelection(float tab[], int longueurTab, FILE *fp) {

    //variable tri
    int i, j, rangMin;
    float stock;

    //variable mesure du temps
    float temps;
    clock_t t1, t2;

    t1 = clock();

    //algorithme tri par selection
    for (i = 0; i < longueurTab - 1; i++) {
        //on commence le tri au rang i
        rangMin = i;

        //on parcours le tableau
        for (j = i; j < longueurTab; j++) {
            //le rang de la plus petite valeur est stocké
            if (tab[rangMin] > tab[j]) {
                rangMin = j;
            }
        }

        //invertion des valeurs, la plus petite prend la position i
        stock = tab[rangMin];
        tab[rangMin] = tab[i];
        tab[i] = stock;
    }

    //affichage des resultats
    /*for (i = 0; i < longueurTab; i++) {
        printf("%f , ", tab[i]);
    }
    printf("\n");*/


    //calcul du temps d'execution et ecriture dans le csv
    t2 = clock();
    temps = (float) (t2 - t1) / CLOCKS_PER_SEC;
    fprintf (fp,"%f,", temps);
}

//tri par tas

void TriTas(float tab[], int longueurTab, FILE *fp) {

    //declaration variable tri
    int i, j, fils, fils2;
    float stock;

    //variable mesure du temps
    float temps;
    clock_t t1, t2;

    t1 = clock();

    //on range le tableau pour faire un tas
    for (i = 0; i < longueurTab / 2; i++) {

        //on calcule la position de la valeur fils
        fils = 2 * i + 1;
        fils2 = 2 * i + 2;

        //on compare la valeur fils et la valeur pere
        if (tab[fils] > tab[i]) {

            j = fils;

            //tant que la valeur fils est plus grande que la valeur pere et valeur pere > 0 on echange
            while (j > 0 && tab[j] > tab[(j - 1) / 2]) {
                stock = tab[j];
                tab[j] = tab[(j - 1) / 2];
                tab[(j - 1) / 2] = stock;

                j = (j - 1) / 2;
            }
        }

        //meme comparaison mais on verifie en plus que la valeur fils de cette position existe
        if (tab[fils2] > tab[i] && fils2 < longueurTab) {
            j = fils2;
            //tant que la valeur fils est plus grande que la valeur pere et valeur pere > 0 on echange
            while (j > 0 && tab[j] > tab[(j - 1) / 2]) {
                stock = tab[j];
                tab[j] = tab[(j - 1) / 2];
                tab[(j - 1) / 2] = stock;
                j = (j - 1) / 2;
            }
        }

    }//fin du rangement


    //tri par tas
    //parcours le tableau a l'envers 
    for (i = longueurTab - 1; i > 0; i--) {
        fils = 2 * i + 1;

        for (j = 0; j < i / 2; j++) {

            int fils2 = 2 * j + 1;

            //on fait remonter la valeur la plus grande en haut de l'arbre
            if (tab[fils2] > tab[j]) {
                stock = tab[j];
                tab[j] = tab[fils2];
                tab[fils2] = stock;
            }
            if (tab[fils2 + 1] > tab[j]) {
                stock = tab[j];
                tab[j] = tab[fils2 + 1];
                tab[fils2 + 1] = stock;
            }
        }

        //on echange la valeur en haut de l'arbre et celle a la position i
        stock = tab[i];
        tab[i] = tab[0];
        tab[0] = stock;

    }

    //affichage des resultats
    /*for (i = 0; i < longueurTab; i++) {
        printf("%f , ", tab[i]);
    }
    printf("\n");*/

    //calcul du temps d'execution et ecriture dans le csv
    t2 = clock();
    temps = (float) (t2 - t1) / CLOCKS_PER_SEC;
    fprintf (fp,"%f,", temps);

}

void bulle(float tab[], int longueurTab, FILE *fp) {
    //variable de tri
    int i, j;
    float stock = 0;
    float temps;
    clock_t t1, t2;

    t1 = clock();

    //algorithme de tri
    for (i = 0; i < longueurTab - 1; i++) {
        for (j = 0; j < longueurTab - i - 1; j++) //on parcours le tableau
        {
            if (tab[j] > tab[j + 1]) //la valeur la plus grande est stocké
            {
                //échange les valeurs
                stock = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = stock;

            }
        }

    }


    //affichage des resultats
    /*for (i = 0; i < longueurTab; i++) {
        printf("%f , ", tab[i]);
    }
    printf("\n");*/

    //calcul du temps d'execution du programme et ecriture dans le csv
    t2 = clock();
    temps = (float) (t2 - t1) / CLOCKS_PER_SEC;
    fprintf (fp,"%f,", temps);
    

}

void insertion(float tab[], int longueurTab, FILE *fp) {
    //variable de tri
    int i, j;
    float stock;
    float temps;
    clock_t t1, t2;

    t1 = clock();

    //algorithme de tri
    for (i = 1; i < longueurTab; i++) {
        j = i;
        stock = tab[j]; // on stock la valeur

        //on parcours le tableau 
        while (j > 0 && tab[j - 1] > stock) {

            tab[j] = tab[j - 1]; // décale les élements plus grand que stock 
            j--;
        }
        tab[j] = stock; //place la valeur stock dans le trou laissé
    }

    //affichage des resultats
    /*for (i = 0; i < longueurTab; i++) {
        printf("%f , ", tab[i]);
    }
    printf("\n");*/

    //calcul du temps d'execution du programme et ecriture dans le csv
    t2 = clock();
    temps = (float) (t2 - t1) / CLOCKS_PER_SEC;
    fprintf (fp,"%f\n", temps);
}

int main(int argc, char** argv) {
    
    
    int i, j, longueurTab = 0, nbtest;
    char csvfile[1000];
    
    //variable fichier
    FILE *fp ;
    
    //saisie de l'emplacement du fichier csv
    printf("Saisir le nom du fichier CSV dans lequel ecrire les resultats: ");
    scanf("%s", &csvfile);
    
    //ouverture et initialisation du fichier csv
    fp = fopen(csvfile, "w+");
    fprintf(fp, "Temps tri par selection, Temps tri par tas, Temps tri a bulle, Temps tri par insertion\n");
    
    // nombre de test a effectuer
    printf("Saisir le nombre de test a faire : ");
    scanf("%d", &nbtest);
    
    //on effectue les test et on ecrit dans le fichier csv au fur et a mesure
    for (j = 0; j < nbtest; j++) {
        
        //saisie longeur du tableau
        printf("Saisir le nombre de valeur du tableau : ");
        scanf("%d", &longueurTab);

        float tab[longueurTab];

        for (i = 0; i < longueurTab; i++) {
            tab[i] = rand() % 1000000;
        }

        //execution des algorithmes de tri
        TriSelection(tab, longueurTab, fp);

        TriTas(tab, longueurTab, fp);

        bulle(tab, longueurTab, fp);

        insertion(tab, longueurTab, fp);

    }
    
    //fermeture du fichier
    fclose(fp);

    return (EXIT_SUCCESS);
}

