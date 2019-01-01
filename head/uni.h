#ifndef _UNI_H
#define _UNI_H

#include "../head/squelette.h"
#include <stdbool.h>
#include <stdlib.h>


/**
 * @brief Cherche la valeur min de la ligne et la stocke dans *min
 *
 * @param t_mat
 * @param l
 * @param min
 *
 * @return N° de la colonne correspondant au max
 */
int recup_min (const t_mat_char_star_dyn t_mat, const int l, int* min);

/**
 * @brief Vérifie l'unicité du vote
 *
 * @param t_mat
 * @param l
 * @param min
 * @param res
 *
 * @return true si unique, false sinon
 */
bool verif_unicite(const t_mat_char_star_dyn t_mat, const int l, const int min, const int res);

/**
 * @brief Déroule le premier tout d'un vote uninominal et stocke les scores dans t_res
 *
 * @param t_mat
 * @param t_res
 */
void uni_tour_1(const t_mat_char_star_dyn t_mat, t_tab_int_dyn* t_res);

/**
 * @brief Déroule le second tour d'un vote uninominal et stocke les scores dans c1 et c2
 *
 * @param t_mat
 * @param c1 : Premier candidat élu au premier tour
 * @param c2 : Second candidat élu au premier tour
 */
void uni_tour_2 (const t_mat_char_star_dyn t_mat, const int i_c1, const int i_c2, int* res_c1, int* res_c2);

/**
 * @brief Trouve le vainqueur d'un scrutin uninominal à 1 tour et affiche le résultat
 *
 * @param t_mat
 * @param logfp
 */
void  scrutin_uni1(const t_mat_char_star_dyn t_mat, FILE* logfp);

/**
 * @brief Trouve le vainqueur d'un scrutin uninominal à 2 tour et affiche le résultat
 *
 * @param t_mat
 * @param logfp
 */
void scrutin_uni2 (const t_mat_char_star_dyn t_mat, FILE* logfp);

#endif
