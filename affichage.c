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
   Bateau* adressePort = bateau;
   for (int i = 1; i <= taille; ++i,++bateau) {
      double taxe = calculerTaxe(bateau);
      if (bateau->typeBateau == voilier) {
         printf("Bateau %d :\n"
                " - %s\n"
                " - %dm^2 de voile\n",
                i,
                type[bateau->typeBateau],
                bateau->typesBateauSpec.voilier.surfaceVoile);
      }
      else {
         printf("Bateau %d :\n"
                " - Moteur\n"
                " - %s\n"
                " - %dCV\n",
                i,
                type[bateau->typeBateau],
                bateau->typesBateauSpec.bateauMoteur.puissancesMoteurs);
         if (bateau->typeBateau == peche) {
            printf(" - %dt de poisson\n",bateau->typesBateauSpec.bateauMoteur.typeBateauMoteurSpec.peche.poissonsMax);
         }
         else {
            printf(" - %dm\n"
                   " - %s\n",
                   bateau->typesBateauSpec.bateauMoteur.typeBateauMoteurSpec.plaisance.longeurBateau,
                   bateau->typesBateauSpec.bateauMoteur.typeBateauMoteurSpec.plaisance.nomProprietaire);
         }
      }
      printf("Taxe annuelle: %.2fEUR\n\n", taxe);
   }

   printf("La somme des taxes annuelles pour les %s est de: %f",
          type[bateau->typeBateau],
          calculerMediane(adressePort,taille,1));
}