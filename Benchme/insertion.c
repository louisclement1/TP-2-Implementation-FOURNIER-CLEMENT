/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "insertion.h"

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



    //calcul du temps d'execution du programme et ecriture dans le csv
    t2 = clock();
    temps = (float) (t2 - t1) / CLOCKS_PER_SEC;
    fprintf (fp,"%f\n", temps);
}