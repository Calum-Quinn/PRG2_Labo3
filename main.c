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
#include "taxes.h"


int main (){

   Bateau monBateau = {"Titanic",moteur,{.bateauMoteur={plaisance,500,.typeBateauMoteurSpec={.plaisance={"Edward Smith",(LongueurBateau)269}}}}};

   Bateau port[] = {{"Poisson", moteur, {.bateauMoteur={peche,20,.typeBateauMoteurSpec={.peche={10}}}}}
                     ,{"Santa Maria", voilier,{.voilier={150}}}
                     ,{"L'Hermione",voilier,{.voilier={250}}}
                     ,{"Titanic",moteur,{.bateauMoteur={plaisance,500,.typeBateauMoteurSpec={.plaisance={"Edward Smith",269}}}}}
                     ,{"Chalutier",moteur,{.bateauMoteur={peche,30,.typeBateauMoteurSpec={.peche={25}}}}}
                     ,{"Atlantis",moteur,{.bateauMoteur={plaisance,50,.typeBateauMoteurSpec={.plaisance={"Ewan Mariaux",100,50}}}}}
   };

   double taxe = calculerTaxe(&monBateau);

   printf("%f",taxe);


	return EXIT_SUCCESS;
}