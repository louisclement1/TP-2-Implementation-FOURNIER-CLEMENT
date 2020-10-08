# TP-2-Implementation-FOURNIER-CLEMENT

## Objet du projet

Le projet est de créer des programmes de tri(a bulle, sélection, insertion, par tas) et de stocker leurs temps d'exécution dans un fichier csv.

Le tri par tas sert a trier des valeurs dans un tableau dans  l'ordre croissant ou décroissant en utilisant le système d'arbre binaire pour comparer chaque enfant avec son parent.

Le tri par sélection est un tri par comparaison, il va chercher la plus petite valeur et l'échange avec l'indice 0, recommence avec la plus petite valeur mais cette fois ci à l'indice 1, ect..

Le tri d'insertion permet de comparer des valeurs dans un tableau quand il va trouver une valeur plus grande que celle actuelle il va décaler les éléments et placer l'ancienne valeur dans la position libérée.

Le tri a bulle consiste a comparer des valeurs dans un tableau et a les permuter quand elles sont mal triées.

Le but de se projet est de calculer le temps d'exécution des algorithmes de tri pour en déduire leurs complexité temporelle.

Les valeurs saisies par l'utilisateur sont le nom du fichier csv et le nombre de variable du tableau

## L'usage des commandes

La documentation technique sera disponible grâce a la commande make documentation (la commande `make documentation` à été écrite dans le makefile qui permettra d'appeler la doc technique)

Les résultats des benchmark i.e. seront écrit dans un fichier result.csv, pour l'appeler faudra utiliser la commande benchme result.csv

Chaque fonctions du programme est dans des fichier .c et la signature des fonctions sont dans des fichiers .h

## Les résultats attendus


Les résultats attendus sont les temps d'exécution des algorithmes de tri. Ils seront stockés dans un fichier csv pour déduire la complexité temporelle des algorithmes.


## Les évolutions à venir
