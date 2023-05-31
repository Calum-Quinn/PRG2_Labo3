/*
 -----------------------------------------------------------------------------------
 Nom du fichier : affichage.h
 Auteur(s)      : Ewan Mariaux, Calum Quinn, Dario Vasques
 Date creation  : 25.05.2023

 Description    : En-tête afin d'effectuer l'affichage des bateaus

 Remarque(s)    : -

 Compilateurs   : Apple clang version 14.0.3 (clang-1403.0.22.14.1) (Dario)
                : Mingw-w64 g++ 12.2.0 (Calum et Ewan)
 -----------------------------------------------------------------------------------
*/
#ifndef LABO03_AFFICHAGE_H
#define LABO03_AFFICHAGE_H

#include "bateau.h"
#include "inttypes.h"

#define SEPARATEUR "-------------------------------------------------------------"
#define FORMAT_CALCUL "%.2f"
#define FORMAT_MSG "%-s : "

#define MSG_TITRES "Statistiques pour les bateaux de type "

#define MSG_SOMME "Somme des taxes"
#define MSG_MOYENNE "Moyenne des taxes"
#define MSG_MEDIANE "Mediane des taxes"
#define MSG_ECART_TYPE "Ecart type des taxes"
#define MSG_BATEAU_ID "Bateau %d :"
#define MSG_BATEAU_NOM "- Nom du bateau : %s"
#define MSG_BATEAU_TYPE "- Type de bateau : %s"
#define MSG_SURFACE_VOILE "- Surface de la voile : %"PRIu16
#define MSG_BATEAU_PECHE " - Tonnes de poissons : %"PRIu8
#define MSG_CAPITAINE " - Nom du propriétaire : %s"
#define MSG_LONG_BATEAU " - Longueur du bateau : %"PRIu8
#define MSG_PUISSANCE_MOTEUR "- Puissance du moteur : %"PRIu16


#define UNITE_TAXE "EUR"
#define UNITE_LONGUEUR_BATEAU "[m]"
#define UNITE_POIDS_POISSON "[t]"
#define UNITE_PUISSANCE_BATEAU "[CV]"
#define UNITE_SURFACE_VOILE "[m^2]"


/**
     * @name            : affichage
     *
     * @but             : afficher tous les bateaux avec leurs données
     *
     * @param bateau    : pointeur sur le tableau de bateaux
     * @param taille    : taille du tableau
     * @return          : void
     * @throws          : NIL
     */
void affichage(Bateau* bateau, int taille);

/**
     * @name            : affichageParType
     *
     * @but             : afficher la somme, la moyenne, la médiane et l'écart type
     *                    de chaque type de bateau
     *
     * @param port      : pointeur sur le tableau de bateaux
     * @param taillePort: taille du tableau
     * @param typeBat   : type de bateaux qu'on veut utiliser
     * @param estDeType : pointeur sur la fonction estDeType
     * @return          : void
     * @throws          : NIL
     */
void affichageParType(const Bateau port[], size_t taillePort, TypeBateau typeBat, bool
(*estDeType)
	(const Bateau*));

#endif //LABO03_AFFICHAGE_H