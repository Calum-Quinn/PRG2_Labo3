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
#include <stdlib.h>
#include "math.h"

double calculerTaxe(const Bateau* bateau){
   double taxe = 0;

   //Voilier
   if(bateau->typeBateau == voilier)
   {
      taxe += TAXE_BASE_VOILIER;
      //Taxe selon la taille du voile
      if(bateau->typesBateauSpec.voilier.surfaceVoile >= TAXE_VOILIER_VOILURE_SEUIL)
         taxe += TAXE_VOILIER_VOILURE_GRANDE;
      else
         taxe += TAXE_VOILIER_VOILURE_PETITE;
   }
   //Moteur
   //Pêche
   else if(bateau->typeBateau == peche){
      taxe += TAXE_BASE_MOTEUR;
      //Taxe selon la quantité de poisson
      if(bateau->typesBateauSpec.bateauMoteur.typeBateauMoteurSpec.peche.poissonsMax >= TAXE_PECHE_TONNAGE_SEUIL)
         taxe += TAXE_PECHE_TONNAGE_GRANDE;
      else
         taxe += TAXE_PECHE_TONNAGE_PETITE;
   }
   //Plaisance
   else if(bateau->typeBateau == plaisance){
      taxe += TAXE_BASE_MOTEUR;
      //Taxe selon la puissance
      if(bateau->typesBateauSpec.bateauMoteur.puissancesMoteurs < TAXE_PLAISANCE_PUISSANCE_SEUIL)
         taxe += TAXE_PLAISANCE_PUISSANCE_PETITE;
      else
         taxe += bateau->typesBateauSpec.bateauMoteur.typeBateauMoteurSpec.plaisance.longeurBateau * TAXE_PLAISANCE_LONGUEUR;
   }

   return taxe;
}

int taxePlusPetit (const void* a, const void* b) {
   const Bateau* bateauA = (const Bateau*) a;
   const Bateau* bateauB = (const Bateau*) b;

   //Compare les taxes des deux bateaux
   if (bateauA->taxe < bateauB->taxe) {
      return 1;
   }
   else if (bateauA->taxe > bateauB->taxe) {
      return -1;
   }
   else {
      return 0;
   }
}

double calculerSomme(const double* taxes, size_t nbBateaux){
	double somme = 0;
	for(size_t i = 0; i < nbBateaux; ++i){
		somme += taxes[i];
	}
	return somme;
}

double calculerMoyenne(const double* taxes,size_t nbBateaux){
   return calculerSomme(taxes, nbBateaux) / (double) nbBateaux;
}

int plusGrand (const void * a, const void * b) {
   return (*(double*)a > *(double*)b);
}

double calculerMediane(double taxes[],size_t nbBateaux){
   qsort(taxes, nbBateaux, sizeof(double), plusGrand);

   if(nbBateaux % 2){
      return taxes[(nbBateaux + 1) / 2 - 1];
   }else{
      return ((taxes[nbBateaux / 2 - 1] + taxes[nbBateaux / 2]) / 2);
   }
}

double calculerEcartType(const double* taxes, size_t nbBateaux){
	double moyenne = calculerMoyenne(taxes, nbBateaux);
	double somme = 0;

	for(size_t i = 0; i < nbBateaux; ++i){
		somme += pow(taxes[i] - moyenne, 2.0);
	}
	return sqrt(somme / (double) nbBateaux);
}

double* calculTaxeType(const Bateau port[], size_t* taillePort, bool (*estDeType)
	(const Bateau*)){
	double* taxes = (double*) calloc(*taillePort, sizeof(double));
	size_t nbBateauxDuType = 0;

   //Compte le nombre de bateaux du même type et stock leur taxe
	for(size_t i = 0; i < *taillePort; ++i){
		if(estDeType(&port[i])){
			taxes[nbBateauxDuType] = calculerTaxe(&port[i]);
			++nbBateauxDuType;
		}
	}

	taxes = (double*) realloc(taxes, nbBateauxDuType * sizeof(double));
	//Contrôle que la réallocation de mémoire s'est correctement déroulée
	if(taxes)
		*taillePort = nbBateauxDuType;
	else
		*taillePort = 0;

	return taxes;
}
