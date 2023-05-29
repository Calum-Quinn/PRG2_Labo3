/*
 -----------------------------------------------------------------------------------
 Nom du fichier : taxes.c
 Auteur(s)      : Ewan Mariaux, Calum Quinn, Dario Vasques
 Date creation  : 25.05.2023

 Description    : Programme servant à effectuer le calcul des taxes

 Remarque(s)    : -

 Compilateurs   : Apple clang version 14.0.3 (clang-1403.0.22.14.1) (Dario)
                : Mingw-w64 g++ 12.2.0 (Calum et Ewan)
 -----------------------------------------------------------------------------------
*/

#include "taxes.h"

double calculerTaxe(Bateau* bateau){
   double taxe = 0;

   if(bateau->categorieBateau == voilier)
   {
      taxe += TAXE_BASE_VOILIER;
      if(bateau->typesBateau.voilier.surfaceVoile >= TAXE_VOILIER_VOILURE_SEUIL)
         taxe += TAXE_VOILIER_VOILURE_GRANDE;
   }else if(bateau->typesBateau.bateauMoteur.typeBateauMoteur == peche){
      if(bateau->typesBateau.bateauMoteur.typeBateauMoteurSpec.peche.poissonsMax >= TAXE_PECHE_TONNAGE_SEUIL)
         taxe += TAXE_PECHE_TONNAGE_GRANDE;
   }else if(bateau->typesBateau.bateauMoteur.typeBateauMoteur == plaisance){
      if(bateau->typesBateau.bateauMoteur.puissancesMoteurs < TAXE_PLAISANCE_PUISSANCE_SEUIL)
         taxe += TAXE_PLAISANCE_PUISSANCE_PETITE;

      taxe += bateau->typesBateau.bateauMoteur.typeBateauMoteurSpec.plaisance.longeurBateau * TAXE_PLAISANCE_LONGUEUR;
   }

   return taxe;
}
