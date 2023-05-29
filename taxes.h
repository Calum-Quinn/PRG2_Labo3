/*
 -----------------------------------------------------------------------------------
 Nom du fichier : taxes.h
 Auteur(s)      : Ewan Mariaux, Calum Quinn, Dario Vasques
 Date creation  : 25.05.2023

 Description    : header pour la calcul des taxe

 Remarque(s)    : -

 Compilateurs   : Apple clang version 14.0.3 (clang-1403.0.22.14.1) (Dario)
                : Mingw-w64 g++ 12.2.0 (Calum et Ewan)
 -----------------------------------------------------------------------------------
*/

#ifndef LABO03_TAXES_H
#define LABO03_TAXES_H

#include "bateau.h"

#define TAXE_BASE_VOILIER 50.0
#define TAXE_BASE_MOTEUR 100.0

#define TAXE_VOILIER_VOILURE_PETITE 0.0
#define TAXE_VOILIER_VOILURE_GRANDE 25.0
#define TAXE_VOILIER_VOILURE_SEUIL 200

#define TAXE_PECHE_TONNAGE_PETITE 0.0
#define TAXE_PECHE_TONNAGE_GRANDE 100.0
#define TAXE_PECHE_TONNAGE_SEUIL 20.0

#define TAXE_PLAISANCE_PUISSANCE_PETITE 0.0
#define TAXE_PLAISANCE_PUISSANCE_GRANDE 50.0
#define TAXE_PLAISANCE_PUISSANCE_SEUIL 100

#define TAXE_PLAISANCE_LONGUEUR 15.0;    //15 euros par metre de longueur.

double calculerTaxe(Bateau port[]);


#endif //LABO03_TAXES_H
