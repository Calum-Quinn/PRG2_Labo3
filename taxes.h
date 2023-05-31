/*
 -----------------------------------------------------------------------------------
 Nom du fichier : taxes.h
 Auteur(s)      : Ewan Mariaux, Calum Quinn, Dario Vasques
 Date creation  : 25.05.2023

 Description    : header pour la calcul des taxes

 Remarque(s)    : -

 Compilateurs   : Apple clang version 14.0.3 (clang-1403.0.22.14.1) (Dario)
                : Mingw-w64 g++ 12.2.0 (Calum et Ewan)
 -----------------------------------------------------------------------------------
*/

#ifndef LABO03_TAXES_H
#define LABO03_TAXES_H

#include "bateau.h"
#include <stdbool.h>
#include <stdlib.h>

#define TAXE_BASE_VOILIER 50.0
#define TAXE_BASE_MOTEUR 100.0

#define TAXE_VOILIER_VOILURE_PETITE 0.0
#define TAXE_VOILIER_VOILURE_GRANDE 25.0
#define TAXE_VOILIER_VOILURE_SEUIL 200

#define TAXE_PECHE_TONNAGE_PETITE 0.0
#define TAXE_PECHE_TONNAGE_GRANDE 100.0
#define TAXE_PECHE_TONNAGE_SEUIL 20.0

#define TAXE_PLAISANCE_PUISSANCE_PETITE 50.0
#define TAXE_PLAISANCE_PUISSANCE_SEUIL 100

#define TAXE_PLAISANCE_LONGUEUR 15.0

/**
     * @name            : calculerTaxe
     *
     * @but             : calculer la taxe annuelle d'un bateau
     *
     * @param bateau    : bateau pour lequel il faut calculer
     * @return          : la taxe
     * @throws          : NIL
     */
double calculerTaxe(const Bateau* bateau);

/**
     * @name            : taxePlusPetit
     *
     * @but             : comparer deux taxes
     *
     * @param a         : pointeur sur le premier bateau
     * @param b         : pointeur sur le deuxième bateau
     * @return          : int pour dire s'il est plus grand, plus petit ou égal
     * @throws          : NIL
     */
int taxePlusPetit (const void* a, const void* b);

/**
     * @name            : calculerSomme
     *
     * @but             : calculer la somme des taxes annuelles
     *
     * @param taxes     : tableau des taxes annuelles
     * @param nbBateaux : taille du tableau
     * @return          : la somme
     * @throws          : NIL
     */
double calculerSomme(const double* taxes,size_t nbBateaux);

/**
     * @name            : calculerMoyenne
     *
     * @but             : calculer la moyenne des taxes annuelles
     *
     * @param taxes     : tableau des taxes annuelles
     * @param nbBateaux : taille du tableau
     * @return          : la moyenne
     * @throws          : NIL
     */
double calculerMoyenne(const double* taxes,size_t nbBateaux);

/**
     * @name            : calculerMediane
     *
     * @but             : calculer la médiane des taxes annuelles
     *
     * @param taxes     : tableau des taxes annuelles
     * @param nbBateaux : taille du tableau
     * @return          : la médiane
     * @throws          : NIL
     */
double calculerMediane(double taxes[],size_t nbBateaux);

/**
     * @name            : calculerEcartType
     *
     * @but             : calculer l'écart type des taxes annuelles
     *
     * @param taxes     : tableau des taxes annuelles
     * @param nbBateaux : taille du tableau
     * @return          : l'écart type
     * @throws          : NIL
     */
double calculerEcartType(const double* taxes,size_t nbBateaux);

/**
     * @name            : calculTaxeType
     *
     * @but             : calculer les taxes de tous les bateaux d'un type
     *
     * @param port      : tableau de bateaux
     * @param taillePort: taille du tableau
     * @param estDeType : pointeur sur la fonction estDeType
     * @return          : pointeur sur le tableau des taxes selon le type
     * @throws          : NIL
     */
double* calculTaxeType(const Bateau port[], size_t* taillePort, bool (*estDeType)
(const Bateau*));

#endif //LABO03_TAXES_H