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
#include <stdbool.h>

typedef uint16_t SurfaceVoile;         //en m^2
typedef uint16_t PuissancesMoteurs;    //en CV
typedef uint8_t PoissonsMax;           //en tonnes
typedef uint8_t LongueurBateau;        //en m
typedef char* nom;

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
   double taxe;
   TypesBateauSpec typesBateauSpec;
} Bateau;


/**
     * @name            : estVoilier
     *
     * @but             : controle si le bateau est un voilier
     *
     * @param bateau    : pointeur constant sur le bateau
     * @return          : retourne true si le bateau est un voilier
     * @throws          : NIL
     */
bool estVoilier(const Bateau* bateau);

/**
     * @name            : estPlaisance
     *
     * @but             : controle si le bateau est un bateau de plaisance
     *
     * @param bateau    : pointeur constant sur le bateau
     * @return          : retourne true si le bateau est un bateau de plaisance
     * @throws          : NIL
     */
bool estPlaisance(const Bateau* bateau);

/**
     * @name            : estPeche
     *
     * @but             : controle si le bateau est un bateau de peche
     *
     * @param bateau    : pointeur constant sur le bateau
     * @return          : retourne true si le bateau est un bateau de peche
     * @throws          : NIL
     */
bool estPeche(const Bateau* bateau);

#endif //LABO03_BATEAU_H