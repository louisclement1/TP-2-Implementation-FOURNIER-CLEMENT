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

void TriSelection(int tab[],int longueurTab)
{
    //variable tri
    int i, j, temp;
    int rangMin;
    
    //variable mesure du temps
    float temps;
    clock_t t1, t2;
    
    t1 = clock();
    
    //algorithme tri par selection
    for(i=0; i<longueurTab;i++)
    {
        //on commence le tri au rang i
        rangMin = i;
        
        //on parcours le tableau
        for (j =i; j<longueurTab;j++)
        {
            //le rang de la plus petite valeur est stocké
            if (tab[rangMin]>tab[j])
            { 
                rangMin = j;
            }
        }
        
        //invertion des valeurs, la plus petite prend la position i
        temp = tab[rangMin];
        tab[rangMin] = tab[i];
        tab[i] = temp;
    }
    
    //affichage des resultats, a retirer plus tard
    for (i=0; i<longueurTab;i++)
    {
        printf("%d\n",tab[i]);
    }
    
    t2 = clock();
    temps = (float)(t2-t1)/CLOCKS_PER_SEC;
    printf("temps = %f\n", temps);
}

void TriTas(int tab[],int longueurTab)
{ 
    int i,j,fils,stock;
    
    //on range le tableau pour faire un tas
    for (i = 0; i<longueurTab/2;i++)
    {
        fils = 2*i +1 ;
        
        if (tab[fils] >tab[i])
        {
            j = fils;
            while (j>0 && tab[j]>tab[(j-1)/2])
            {
                stock = tab[j];
                tab[j] = tab[(j-1)/2];
                tab[(j-1)/2]= stock;
                
                j = (j-1)/2;
            }
        }
        if (tab[fils+1] >tab[i] && fils+1<longueurTab)
        {
            j = fils+1;
            while (j>0 && tab[j]>tab[(j-1)/2])
            {
                stock = tab[j];
                tab[j] = tab[(j-1)/2];
                tab[(j-1)/2]= stock;
                j = (j-1)/2;
            }
        }
        
        for (int p =0; p<longueurTab;p++)
        {
            printf("%d , ",tab[p]);
        }
        printf("\n");
    }//fin du rangement
    
   
    
}

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
        stock = tab[j];
        while (j > 0 && tab[j-1] > stock)
        {
            
            tab[j]=tab[j-1];
            j--;
        }
        tab[j-1]=stock;
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
    TriSelection(tab, longueurTab);*/
    
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

