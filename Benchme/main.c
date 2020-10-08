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
#include "selection.h"
#include "bulle.h"
#include "tas.h"
#include "insertion.h"

/*
 * 
 */

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

