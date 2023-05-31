/*
 -----------------------------------------------------------------------------------
 Nom du fichier : affichage.h
 Auteur(s)      : Ewan Mariaux, Calum Quinn, Dario Vasques
 Date creation  : 25.05.2023

 Description    : En-tête afin d'effectuer l'affichage des bateaus

 Remarque(s)    : -

 Compilateurs   : Apple clang version 14.0.3 (clang-1403.0.22.14.1) (Dario)
                : Mingw-w64 g++ 12.2.0 (Calum et Ewan)
 -----------------------------------------------------------------------------------
*/
#ifndef LABO03_AFFICHAGE_H
#define LABO03_AFFICHAGE_H

#include "bateau.h"

/**
     * @name            : affichage
     *
     * @but             : afficher tous les bateaux avec leurs données
     *
     * @param bateau    : pointeur sur le tableau de bateaux
     * @param taille    : taille du tableau
     * @return          : void
     * @throws          : NIL
     */
void affichage(Bateau* bateau, int taille);

/**
     * @name            : affichageParType
     *
     * @but             : afficher la somme, la moyenne, la médiane et l'écart type
     *                    de chaque type de bateau
     *
     * @param port      : pointeur sur le tableau de bateaux
     * @param taillePort: taille du tableau
     * @param typeBat   : type de bateaux qu'on veut utiliser
     * @param estDeType : pointeur sur la fonction estDeType
     * @return          : void
     * @throws          : NIL
     */
void affichageParType(const Bateau port[], size_t taillePort, TypeBateau typeBat, bool
(*estDeType)
	(const Bateau*));

#endif //LABO03_AFFICHAGE_H