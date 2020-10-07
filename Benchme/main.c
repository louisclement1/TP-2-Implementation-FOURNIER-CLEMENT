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

/*
 * 
 */

void bulle(int tab[], int longueurTab)
{
    int i ,j;
    int stock = 0;
    float temps;
    clock_t t1, t2;
    
    t1 = clock();
    
    for(i=0; i< longueurTab - 1; i++)
    {
        for(j = 0; j < longueurTab-i-1 ;j++)
        {
            if(tab[j]>tab[j+1])
            {
                stock = tab[j];
                tab[j] = tab[j+1];
                tab[j+1]= stock;

            }
        }
        
    }
    for (i=0; i<longueurTab;i++)
    {
        printf("%d\n",tab[i]);
    }
    
    t2 = clock();
    temps = (float)(t2-t1)/CLOCKS_PER_SEC;
    printf("temps = %f\n",temps);
   
}

void insertion(int tab[],int longueurTab)
{
    int i, j;
    int stock;
    float temps;
    clock_t t1, t2;
    
    t1 = clock();
    
    for(i=1; i<longueurTab;i++)
    {
        j = i;
        while (j > 0 && tab[j-1] > tab[j])
        {
            stock = tab[j];
            tab[j]=tab[j-1];
            tab[j-1]=stock;
            j--;
        }
    }
    for (i=0; i<longueurTab;i++)
    {
        printf("%d\n",tab[i]);
    }
    
    t2 = clock();
    temps = (float)(t2-t1)/CLOCKS_PER_SEC;
    printf("temps = %f\n", temps);
}

int main(int argc, char** argv) {
    /*int tab[100],i, longueurTab=5;
    for(i = 0; i < longueurTab; i++)
    {
        tab[i]=  rand()%100;
    }
    bulle(tab, longueurTab);*/
    
    /*int tab[100],i, longueurTab=5;
    for(i = 0; i < longueurTab; i++)
    {
        tab[i]=  rand()%100;
    }
    insertion(tab, longueurTab);*/

    return (EXIT_SUCCESS);
}

