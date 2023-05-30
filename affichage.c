/*
 -----------------------------------------------------------------------------------
 Nom du fichier : affichage.c
 Auteur(s)      : Ewan Mariaux, Calum Quinn, Dario Vasques
 Date creation  : 25.05.2023

 Description    : Programme servant à effectuer l'affichage des bateau

 Remarque(s)    : -

 Compilateurs   : Apple clang version 14.0.3 (clang-1403.0.22.14.1) (Dario)
                : Mingw-w64 g++ 12.2.0 (Calum et Ewan)
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include "affichage.h"
#include "taxes.h"

void affichage(Bateau* bateau, int taille) {
   for (int i = 1; i <= taille; ++i,++bateau) {
      double taxe = calculerTaxe(bateau);
      if (bateau->typeBateau == voilier) {
         printf("Bateau %d :'\n'"
                " - Voilier'\n'"
                " - ",
                i);
      }
      else {
         printf("Bateau %d :'\n'"
                " - Moteur'\n'"
                " - %s'\n'"
                " - %dCV'\n'",
                i,
                bateau->typeBateau,
                bateau->typesBateauSpec.bateauMoteur.puissancesMoteurs);
         if (bateau->typeBateau == peche) {
            printf(" - %dt de poisson'\n'",bateau->typesBateauSpec.bateauMoteur.typeBateauMoteurSpec.peche.poissonsMax)
         }
         else {
            printf(" - %d'm\n'"
                   " - %s'\n'",
                   bateau->typesBateauSpec.bateauMoteur.typeBateauMoteurSpec.plaisance.longeurBateau,
                   bate)
         }
      }
   }
}
typedef enum {peche, plaisance, voilier} TypeBateau;

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
