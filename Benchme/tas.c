/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "tas.h"

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



    //calcul du temps d'execution et ecriture dans le csv
    t2 = clock();
    temps = (float) (t2 - t1) / CLOCKS_PER_SEC;
    fprintf (fp,"%f,", temps);

}