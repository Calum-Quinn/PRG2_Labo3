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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


double calculerTaxe(const Bateau* bateau){
   double taxe = 0;

   if(bateau->typeBateau == voilier)
   {
      taxe += TAXE_BASE_VOILIER;
      if(bateau->typesBateauSpec.voilier.surfaceVoile >= TAXE_VOILIER_VOILURE_SEUIL)
         taxe += TAXE_VOILIER_VOILURE_GRANDE;
      else
         taxe += TAXE_VOILIER_VOILURE_PETITE;
   }else if(bateau->typeBateau == peche){
      taxe += TAXE_BASE_MOTEUR;
      if(bateau->typesBateauSpec.bateauMoteur.typeBateauMoteurSpec.peche.poissonsMax >= TAXE_PECHE_TONNAGE_SEUIL)
         taxe += TAXE_PECHE_TONNAGE_GRANDE;
      else
         taxe += TAXE_PECHE_TONNAGE_PETITE;
   }else if(bateau->typeBateau == plaisance){
      taxe += TAXE_BASE_MOTEUR;
      if(bateau->typesBateauSpec.bateauMoteur.puissancesMoteurs < TAXE_PLAISANCE_PUISSANCE_SEUIL)
         taxe += TAXE_PLAISANCE_PUISSANCE_PETITE;
      else
         taxe += bateau->typesBateauSpec.bateauMoteur.typeBateauMoteurSpec.plaisance.longeurBateau * TAXE_PLAISANCE_LONGUEUR;
   }

   return taxe;
}

double calculerSomme(const Bateau port[],size_t taillePort, TypeBateau typeBateau){
   double somme = 0;
   for(size_t i = 0; i < taillePort; ++i){
      if(port[i].typeBateau == typeBateau){
         somme += calculerTaxe(&port[i]);
      }
   }

   return somme;
}

double calculerMoyenne(const Bateau port[],size_t taillePort, TypeBateau typeBateau){
   double cmpt = 0;
   for(size_t i = 0; i < taillePort; ++i){
      //if(estDeType(&port[i])){
      //}
      if(port[i].typeBateau == typeBateau){
         cmpt++;
      }
   }
   return calculerSomme(port, taillePort, typeBateau) / cmpt;
}

int plusGrand (const void * a, const void * b) {
   return (*(double*)a > *(double*)b);
}

double calculerMediane(const Bateau port[],size_t taillePort, TypeBateau typeBateau){
   double taxes[taillePort];
   size_t j = 0;
   for(size_t i = 0; i < taillePort; ++i){
      if(port[i].typeBateau == typeBateau){
         taxes[j] = calculerTaxe(&port[i]);
         ++j;
      }
   }
   double taxesType[j];
   memcpy(taxesType,taxes,j * sizeof(double));
   qsort(taxesType,j,sizeof(double),plusGrand);

   if(j % 2){
      return taxesType[(j+1) / 2 - 1];
   }else{
      return ((taxesType[j/2] + taxesType[j/2 + 1]) / 2);
   }

//   qsort(taxes,j,sizeof(Bateau),plusGrand);
//
//   if(j % 2){
//      return taxes[(j+1) / 2 - 1];
//   }else{
//      return ((taxes[j/2] + taxes[j/2 + 1]) / 2);
//   }
}

double* calculParType(const Bateau port[],size_t taillePort, bool (*estDeType)(const Bateau*)){
   double* taxes = (double*)malloc(taillePort * sizeof(Bateau));

   for(size_t i = 0; i < taillePort; ++i){
      if(estDeType(&port[i])){
         taxes[0];
      }
   }
}
