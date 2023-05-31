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
#include "bateau.h"
#include <assert.h>

void affichage(Bateau* bateau, int taille) {
	assert(bateau != NULL);

   //Tri les bateaux par ordre décroissant de leur taxe
   qsort(bateau,taille,sizeof(Bateau),taxePlusPetit);
   for (int i = 1; i <= taille; ++i,++bateau) {
      //Voilier
      if (bateau->typeBateau == voilier) {
         printf("Bateau %d :\n"
                " - %s\n"
					 " - %d"UNITE_SURFACE_VOILE" de voile\n",
                i,
                type[bateau->typeBateau],
                bateau->typesBateauSpec.voilier.surfaceVoile);
      }
      //Moteur
      else {
         printf("Bateau %d :\n"
                " - Moteur\n"
                " - %s\n"
					 " - %d"UNITE_PUISSANCE_BATEAU"\n",
                i,
                type[bateau->typeBateau],
                bateau->typesBateauSpec.bateauMoteur.puissancesMoteurs);
         //Pêche
         if (bateau->typeBateau == peche) {
            printf(" - %d"UNITE_POIDS_POISSON" de poisson\n"
						 ,bateau->typesBateauSpec.bateauMoteur.typeBateauMoteurSpec.peche.poissonsMax);
         }
         //Plaisance
         else {
            printf(" - %d"UNITE_LONGUEUR_BATEAU"\n"
                   " - %s\n",
                   bateau->typesBateauSpec.bateauMoteur.typeBateauMoteurSpec.plaisance.longeurBateau,
                   bateau->typesBateauSpec.bateauMoteur.typeBateauMoteurSpec.plaisance.nomProprietaire);
         }
      }

      printf("%s"FORMAT_CALCUL" %s""\n\n", "Taxe annuelle: ",
				 bateau->taxe,
				 UNITE_TAXE);
   }
}

void affichageParType(const Bateau port[], size_t taillePort, TypeBateau typeBat,
							 bool
(*estDeType)
	(const Bateau*)){

	assert(port != NULL && estDeType != NULL);

	double* taxes = calculTaxeParType(port, &taillePort, estDeType);

	if(!taxes)
		return;

	if(estDeType){
		printf(MSG_TITRES"%s\n", type[typeBat]);

		printf(FORMAT_MSG FORMAT_CALCUL" %s\n",
				 MSG_SOMME, calculerSomme(taxes,taillePort),
				 UNITE_TAXE);

		printf(FORMAT_MSG FORMAT_CALCUL" %s\n",
				 MSG_MOYENNE, calculerMoyenne(taxes,taillePort),
				 UNITE_TAXE);

      printf(FORMAT_MSG FORMAT_CALCUL" %s\n",
				 MSG_MEDIANE, calculerMediane(taxes,taillePort),
				 UNITE_TAXE);

		printf(FORMAT_MSG FORMAT_CALCUL" %s\n\n",
				 MSG_ECART_TYPE, calculerEcartType(taxes,taillePort),
				 UNITE_TAXE);

		printf(SEPARATEUR"\n\n");
	}
}