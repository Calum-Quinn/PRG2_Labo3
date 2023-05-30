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

void affichage(Bateau* bateau, size_t taille);

void affichageParType(const Bateau port[], size_t taillePort, TypeBateau typeBat, bool
(*estDeType)
	(const Bateau*));

#endif //LABO03_AFFICHAGE_H