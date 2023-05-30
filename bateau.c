/*
 -----------------------------------------------------------------------------------
 Nom du fichier : bateau.c
 Auteur(s)      : Ewan Mariaux, Calum Quinn, Dario Vasques
 Date creation  : 25.05.2023

 Description    : Programme servant à créer des bateaux

 Remarque(s)    : -

 Compilateurs   : Apple clang version 14.0.3 (clang-1403.0.22.14.1) (Dario)
                : Mingw-w64 g++ 12.2.0 (Calum et Ewan)
 -----------------------------------------------------------------------------------
*/

#include "bateau.h"

const char* type[] = {"Peche","Plaisance","Voilier"};

bool estVoilier(const Bateau* bateau){
   return bateau->typeBateau == voilier;
}

bool estPlaisance(const Bateau* bateau){
   return bateau->typeBateau == plaisance;
}

bool estPeche(const Bateau* bateau){
   return bateau->typeBateau == peche;
}

