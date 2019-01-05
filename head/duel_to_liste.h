/**
 * @file duel_to_liste.h
 *
 * @brief Fichier de déclaration relative à la transformation d'une matrice de duel en liste d'arc
 *
 * Déclare les fonctions permettant de transformer une structure t_duel_mat 
 * en structure liste
 *
 * @author Dylan CARON
 *
 * @version 1.0.0
 *
 * @date 02/01/2019 
 */


#ifndef _DUEL_TO_LISTE_H
#define _DUEL_TO_LISTE_H


#include "squelette.h"
#include "liste.h"


/**
 * @fn void remplir_liste (liste* l, t_duel_mat duel)
 *
 * @brief Rempli une liste
 *
 * Rempli une liste avec les arcs correspondant à la matrice de duel
 * passé en paramètres
 *
 * @param l Pointeur vers la liste à remplir
 * @param duel Matrice de duel à transformer
 * @param nb_vote  Nombre de votant du scrutin en cours de traitement
 */
void remplir_liste (liste* l, t_duel_mat duel, int nb_vote);


#endif
