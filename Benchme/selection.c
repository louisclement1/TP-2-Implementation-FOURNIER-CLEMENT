/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

//tri par selection
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "selection.h"

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


    //calcul du temps d'execution et ecriture dans le csv
    t2 = clock();
    temps = (float) (t2 - t1) / CLOCKS_PER_SEC;
    fprintf (fp,"%f,", temps);
}