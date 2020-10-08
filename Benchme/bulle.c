/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "bulle.h"

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


    //calcul du temps d'execution du programme et ecriture dans le csv
    t2 = clock();
    temps = (float) (t2 - t1) / CLOCKS_PER_SEC;
    fprintf (fp,"%f,", temps);
    

}