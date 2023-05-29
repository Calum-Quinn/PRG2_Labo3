/*
 -----------------------------------------------------------------------------------
 Nom du fichier : bateau.h
 Auteur(s)      : Ewan Mariaux, Calum Quinn, Dario Vasques
 Date creation  : 25.05.2023

 Description    : Entete pour la création de bateaux.

 Remarque(s)    : -

 Compilateurs   : Apple clang version 14.0.3 (clang-1403.0.22.14.1) (Dario)
                : Mingw-w64 g++ 12.2.0 (Calum et Ewan)
 -----------------------------------------------------------------------------------
*/

#ifndef LABO03_BATEAU_H
#define LABO03_BATEAU_H

#include <inttypes.h>

typedef uint16_t SurfaceVoile;         //en m^2
typedef uint16_t PuissancesMoteurs;    //en CV
typedef uint8_t PoissonsMax;           //en tonnes
typedef uint8_t LongueurBateau;        //en m
typedef char* nom;

typedef struct {
   PoissonsMax poissonsMax;
   PuissancesMoteurs puissancesMoteurs;
}Peche;

typedef struct{
   nom nomProprietaire;
   LongueurBateau longeurBateau;
   PuissancesMoteurs puissancesMoteurs;
}Plaisance;

typedef union{
   Peche peche;
   Plaisance plaisance;
}BateauMoteur;

typedef struct {
   SurfaceVoile  surfaceVoile;
}Voilier;

typedef union {
   BateauMoteur bateauMoteur;
   Voilier voilier;
}TypesBateau;

typedef struct{
   char* nom;
   enum {moteur, voilier} categorie;
   TypesBateau typesBateau;
} Bateau;


#endif //LABO03_BATEAU_H
