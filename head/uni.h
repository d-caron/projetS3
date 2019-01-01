#ifndef _UNI_H
#define _UNI_H

#include "../head/squelette.h"
#include <stdbool.h>
#include <stdlib.h>


/**
 * @brief Cherche la valeur max de la ligne et la stocke dans *min
 *
 * @param t_mat
 * @param l
 * @param min
 *
 * @return N° de la colonne correspondant au max
 */
int recup_min (t_mat_char_star_dyn t_mat, int l, int* min);

/**
 * @brief Cherche la valeur min de la ligne (sauf pour le candidat exclus) et la stocke dans *min
 *
 * @param t_mat
 * @param l
 * @param min
 *
 * @return N° de la colonne correspondant au min
 */
int recup_min_bis (t_mat_char_star_dyn t_mat, int l, int exclus, int* min);
 
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
 * @brief Vérifie l'unicité du vote (sauf pour le candidat exclus)
 *
 * @param t_mat
 * @param l
 * @param min
 * @param res
 *
 * @return true si unique, false sinon
 */
bool verif_unicite_bis (t_mat_char_star_dyn t_mat, int l, int min, int exclus, int res);
 
/**
 * @brief Déroule le premier tout d'un vote uninominal et stocke les scores dans t_res
 *
 * @param t_mat
 * @param t_res
 */
void uni_tour_1(t_mat_char_star_dyn t_mat, t_tab_int_dyn* t_res);

/**
 * @brief Déroule le premier tour d'un vote uninominal (sauf pour le candidat exclus) et stocke les scores dans t_res
 *
 * @param t_mat
 * @param t_res
 */
void uni_tour_1_bis (t_mat_char_star_dyn t_mat, int exclus, t_tab_int_dyn* t_res);
 
/**
 * @brief Trouve le vainqueur d'un scrutin uninominal à 1 tour et affiche le résultat
 *
 * @param t_mat
 * @param logfp
 */
void  scrutin_uni1(t_mat_char_star_dyn t_mat, FILE* logfp);

/**
 * @brief Trouve le vainqueur d'un scrutin uninominal à 1 tour et affiche le résultat
 *
 * @param t_mat
 * @param logfp
 */
void scrutin_uni2 (t_mat_char_star_dyn t_mat, FILE* logfp),

#endif
