/*
 -----------------------------------------------------------------------------------
 Nom du fichier : bateau.h
 Auteur(s)      : Ewan Mariaux, Calum Quinn, Dario Vasques
 Date creation  : 25.05.2023

 Description    : Entete pour la création de bateau.

 Remarque(s)    : -

 Compilateurs   : Apple clang version 14.0.3 (clang-1403.0.22.14.1) (Dario)
                : Mingw-w64 g++ 12.2.0 (Calum et Ewan)
 -----------------------------------------------------------------------------------
*/

#ifndef LABO03_BATEAU_H
#define LABO03_BATEAU_H

#include <inttypes.h>
#include <stdbool.h>

typedef uint16_t SurfaceVoile;         //en m^2
typedef uint16_t PuissancesMoteurs;    //en CV
typedef uint8_t PoissonsMax;           //en tonnes
typedef uint8_t LongueurBateau;        //en m
typedef char* nom;


//typedef enum {peche, plaisance} TypeBateauMoteur;
typedef enum {peche, plaisance, voilier} TypeBateau;
extern const char* type[];

typedef struct {
   PoissonsMax poissonsMax;
}Peche;

typedef struct{
   nom nomProprietaire;
   LongueurBateau longeurBateau;
}Plaisance;

typedef union {
   Peche peche;
   Plaisance plaisance;
}TypeBateauMoteurSpec;

typedef struct{
   PuissancesMoteurs puissancesMoteurs;
   TypeBateauMoteurSpec typeBateauMoteurSpec;
}BateauMoteur;

typedef struct {
   SurfaceVoile  surfaceVoile;
}Voilier;

typedef union {
   BateauMoteur bateauMoteur;
   Voilier voilier;
}TypesBateauSpec;

typedef struct{
   char* nom;
   TypeBateau typeBateau;
   TypesBateauSpec typesBateauSpec;
} Bateau;

bool estVoilier(const Bateau* bateau);
bool estPlaisance(const Bateau* bateau);
bool estPeche(const Bateau* bateau);

#endif //LABO03_BATEAU_H
