#ifndef _UNI_H
#define _UNI_H

#include "../head/squelette.h"
#include <stdbool.h>
#include <stdlib.h>


/**
 * @brief Cherche la valeur max de la ligne et la stocke dans *max
 *
 * @param t_mat
 * @param l
 * @param max
 *
 * @return N° de la colonne correspondant au max
 */
int recup_max(t_mat_char_star_dyn t_mat, int l, int* max);

/**
 * @brief Vérifie l'unicité du vote
 *
 * @param t_mat
 * @param l
 * @param max
 * @param res
 *
 * @return true si unique, false sinon
 */
bool verif_unicite(t_mat_char_star_dyn t_mat, int l, int max, int res);

/**
 * @brief Déroule le premier tout d'un vote uninominal et stocke les scores dans t_res
 *
 * @param t_mat
 * @param t_res
 */
void uni_tour_1(t_mat_char_star_dyn t_mat, t_tab_int_dyn* t_res);

/**
 * @brief Trouve le vainqueur d'un scrutin uninominal à 1 tour et affiche le résultat
 *
 * @param t_mat
 * @param logfp
 */
void  scrutin_uni1(t_mat_char_star_dyn t_mat, FILE* logfp);

#endif
