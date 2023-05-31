/*
 -----------------------------------------------------------------------------------
 Nom du fichier : main.c
 Auteur(s)      : Ewan Mariaux, Calum Quinn, Dario Vasques
 Date creation  : 25.05.2023

 Description    : Programme principal qui crée, calcul et affiche différents éléments
                  de bateaux

 Remarque(s)    : -

 Compilateurs   : Apple clang version 14.0.3 (clang-1403.0.22.14.1) (Dario)
                : Mingw-w64 g++ 12.2.0 (Calum et Ewan)
 -----------------------------------------------------------------------------------
*/

/*
 *    moteurs
 *       types
 *          pêches
 *             tonnes de poissons
 *          plaisance
 *             longueur
 *             nom du propriétaire
 *       puissance moteurs
 *
 *
 *    voiliers
 *       surface m^2 voile
 *
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "bateau.h"
#include "affichage.h"
#include "taxes.h"

int main (){

   //Initialisation de nos bateaux
   Bateau port[] = {{"Poisson", peche, 0,{.bateauMoteur={20,.typeBateauMoteurSpec={.peche={10}}}}}
                     ,{"Santa Maria", voilier, 0,{.voilier={150}}}
                     ,{"L'Hermione",voilier, 0,{.voilier={250}}}
                     ,{"Titanic",plaisance, 0,{.bateauMoteur={500,.typeBateauMoteurSpec={.plaisance={"Edward Smith",250}}}}}
                     ,{"Chalutier",peche, 0,{.bateauMoteur={30,.typeBateauMoteurSpec={.peche={25}}}}}
                     ,{"Atlantis",plaisance, 0,{.bateauMoteur={50,.typeBateauMoteurSpec={.plaisance={"Ewan Mariaux",100}}}}}
                     ,{"Test",plaisance, 0,{.bateauMoteur={50,.typeBateauMoteurSpec={.plaisance={"Test Mariaux",100}}}}}
   };

   //La taille est définissable à l'intérieur du domaine de définition du tableau
   int taillePort = sizeof(port) / sizeof(Bateau);

   //On calcul les taxes
   for (int j = 0; j < taillePort; ++j) {
      port[j].taxe = calculerTaxe(&port[j]);
   }

   //On tris le port dans l'ordre décroissant des taxes et on affiche
   qsort(port,taillePort,sizeof(Bateau),taxePlusPetit);
   affichage(port, taillePort);

   //-------------------------------------------------------------------------


	printf(SEPARATEUR"\n\n");
	printf("AFFICHAGE PAR TYPE\n\n");
	affichageParType(port, taillePort, peche, estPeche);

	affichageParType(port, taillePort, plaisance, estPlaisance);

	affichageParType(port, taillePort, voilier, estVoilier);

	return EXIT_SUCCESS;
}