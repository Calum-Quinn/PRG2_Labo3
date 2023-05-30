/*
 -----------------------------------------------------------------------------------
 Nom du fichier : main.c
 Auteur(s)      : Ewan Mariaux, Calum Quinn, Dario Vasques
 Date creation  : 25.05.2023

 Description    : Programme servant à ...

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
#include "creation.h"
#include "taxes.h"

int main (){

//   Bateau monBateau = {"Titanic",plaisance,{.bateauMoteur={500,
//																				.typeBateauMoteurSpec={.plaisance={"Edward Smith",(LongueurBateau)100}}}}};

//   int taillePort = 0;
//   Bateau* port = creationPort(&taillePort);

   Bateau port[] = {{"Poisson", peche, {.bateauMoteur={20,.typeBateauMoteurSpec={.peche={10}}}}}
                     ,{"Santa Maria", voilier,{.voilier={150}}}
                     ,{"L'Hermione",voilier,{.voilier={250}}}
                     ,{"Titanic",plaisance,{.bateauMoteur={500,.typeBateauMoteurSpec={.plaisance={"Edward Smith",250}}}}}
                     ,{"Chalutier",peche,{.bateauMoteur={30,.typeBateauMoteurSpec={.peche={25}}}}}
                     ,{"Atlantis",plaisance,{.bateauMoteur={50,.typeBateauMoteurSpec={.plaisance={"Ewan Mariaux",100}}}}}
                     ,{"Test",plaisance,{.bateauMoteur={50,.typeBateauMoteurSpec={.plaisance={"Test Mariaux",100}}}}}
   };

   int taillePort = sizeof(port) / sizeof(Bateau);

   affichage(port, taillePort);

	printf("\n");
	printf("AFFICHAGE PAR TYPE\n\n");
	affichageParType(port, taillePort, peche, estPeche);

	printf("\n");
	affichageParType(port, taillePort, plaisance, estPlaisance);

	printf("\n");
	affichageParType(port, taillePort, voilier, estVoilier);

//   free(port);

	return EXIT_SUCCESS;
}