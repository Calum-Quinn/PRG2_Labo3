/*
 -----------------------------------------------------------------------------------
 Nom du fichier : creation.c
 Auteur(s)      : Ewan Mariaux, Calum Quinn, Dario Vasques
 Date creation  : 25.05.2023

 Description    : programme servant à créer les bateaux

 Remarque(s)    : -

 Compilateurs   : Apple clang version 14.0.3 (clang-1403.0.22.14.1) (Dario)
                : Mingw-w64 g++ 12.2.0 (Calum et Ewan)
 -----------------------------------------------------------------------------------
*/

#include "creation.h"
#include "taxes.h"
#include <stdlib.h>

#define taille 7

//Bateau* creationPort(int* taillePort) {
//   Bateau** port = (Bateau**)calloc(taille, sizeof(Bateau));
//   *port = (Bateau[]){
//      {"Poisson", peche, 0, {.bateauMoteur={20,.typeBateauMoteurSpec={.peche={10}}}}},
//      {"Santa Maria", voilier, 0, {.voilier={150}}},
//      {"L'Hermione",voilier, 0, {.voilier={250}}},
//      {"Titanic",plaisance, 0, {.bateauMoteur={500,.typeBateauMoteurSpec={.plaisance={"Edward Smith",250}}}}},
//      {"Chalutier",peche, 0, {.bateauMoteur={30,.typeBateauMoteurSpec={.peche={25}}}}},
//      {"Atlantis",plaisance, 0, {.bateauMoteur={50,.typeBateauMoteurSpec={.plaisance={"Ewan Mariaux",100}}}}},
//      {"Test",plaisance, 0, {.bateauMoteur={50,.typeBateauMoteurSpec={.plaisance={"Test Mariaux",100}}}}}
//   };
//   Bateau* i = *port;
//   for (int j = 0; j < taille; ++j, ++i) {
//      i->taxe = calculerTaxe(i);
//   }
//   *taillePort = taille;
//   return *port;
//}