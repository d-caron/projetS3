/**
 * @file csv_to_duel.h
 *
 * @brief Déclare les fonctions permettant de transformer une structure t_mat_char_star_dyn 
 *  en structure t_duel
 *
 * @author Dylan CARON
 *
 * @version 1.0.0
 *
 * @date 02/01/2019 
 */


#ifndef _CSV_TO_DUEL_H
#define _CSV_TO_DUEL_H

#include "../head/squelette.h"


/**
 * @fn void csv_to_duel (const t_mat_char_star_dyn t_mat, t_duel_mat* t_duel)
 *
 * @brief Transforme un csv de type liste de vote stocké dans une structure t_mat_char_star_dyn
 *  en structure t_duel (matrice de duel)
 *
 * @param t_mat Structure t_mat_char_star_dyn à transformer (non modifié)
 * @param t_duel Matrice de duel à remplir
 */
void csv_to_duel (const t_mat_char_star_dyn t_mat, t_duel_mat* t_duel);

/**
 * @fn void duel_to_duel (const t_mat_char_star_dyn t_mat, t_duel_mat* t_duel)
 *
 * @brief Transforme un csv de type matrice de duel stocké dans une structure t_mat_char_star_dyn
 *  en structure t_duel (matrice de duel)
 *
 * @param t_mat Structure t_mat_char_star_dyn à transformer (non modifié)
 * @param t_duel Matrice de duel à remplir
 */
void duel_to_duel (const t_mat_char_star_dyn t_mat, t_duel_mat* t_duel);

#endif
