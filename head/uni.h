/**
 * @file uni.h
 *
 * @brief Déclare un enssemble de fonctions permettant de dérouler 
 *  un scrutin uninominal à un ou deux tour(s)
 *
 * @author Dylan CARON
 *
 * @version 1.0.0
 *
 * @date 02/01/2019 
 */

#ifndef _UNI_H
#define _UNI_H

#include "../head/squelette.h"
#include <stdbool.h>
#include <stdlib.h>


/**
 * @fn int recup_min (const t_mat_char_star_dyn t_mat, const int l, int* min)
 *
 * @brief Cherche le vote minimum de la ligne "l" et la stocke dans "*min"
 *
 * @param t_mat Structure t_mat_char_star_dyn à analyser (Non modifié)
 * @param l Numéro de la ligne à analyser (Non modifié)
 * @param min Pointeur vers l'entier de stockage pour le vote minimum
 *
 * @return N° de la colonne correspondant au min
 */
int recup_min (const t_mat_char_star_dyn t_mat, const int l, int* min);

/**
 * @fn bool verif_unicite (const t_mat_char_star_dyn t_mat, const int l, const int min, const int res, int* null)
 *
 * @brief Vérifie l'unicité du vote "min" à la ligne "l"
 *
 * @param t_mat Structure t_mat_char_star_dyn à analyser (Non modifié)
 * @param l Numéro de la ligne à analyser (Non modifié)
 * @param min Valeur dont on doit vérifier l'unicitée
 * @param res Numéro de la colone à laquelle se trouve la valeur min
 * @param null Pointeur vers le nombre de votes null
 *
 * @return true si la valeur est unique, false sinon
 */
bool verif_unicite (const t_mat_char_star_dyn t_mat, const int l, const int min, const int res, int* null);

/**
 * @fn void uni_tour_1(const t_mat_char_star_dyn t_mat, t_tab_int_dyn* t_res, int* null)
 *
 * @brief Déroule le premier tour d'un vote uninominal et stocke les scores dans t_res
 *
 * @param t_mat Structure t_mat_char_star_dyn contenant la liste des votes (Non modifié)
 * @param t_res Pointeur vers une structure t_tab_int_dyn qui recevra les résultats des votes
 * @param null Pointeur vers le nombre de votes null
 */
void uni_tour_1(const t_mat_char_star_dyn t_mat, t_tab_int_dyn* t_res, int* null);

/**
 * @fn void uni_tour_2 (const t_mat_char_star_dyn t_mat, const int i_c1, const int i_c2, int* res_c1, int* res_c2, int* null)
 *
 * @brief Déroule le second tour d'un vote uninominal entre les candidats d'indices "i_c1" et "ic2" 
 *  et stoque les résultats dans "*res_c1" et "*res_c2"
 *
 * @param t_mat Structure t_mat_char_star_dyn contenant la liste des votes (Non modifié)
 * @param i_c1 Indice du premier gagnant du premier tour
 * @param i_c2 Indice du second gagnant du premier tour
 * @param res_c1 Pointeur vers le résultat du premier gagnant du premier tour lors du second tour
 * @param res_c2 Pointeur vers le résultat du premier gagnant du premier tour lors du second tour
 * @param null Pointeur vers le nombre de votes null
 */
void uni_tour_2 (const t_mat_char_star_dyn t_mat, const int i_c1, const int i_c2, int* res_c1, int* res_c2, int* null);

/**
 * @brief Trouve le vainqueur d'un scrutin uninominal à 1 tour et affiche le résultat dans la destination "logfp"
 *
 * @param t_mat Structure t_mat_char_star_dyn contenant la liste des votes (Non modifié)
 * @param logfp Destination d'affichage
 */
void  scrutin_uni1(const t_mat_char_star_dyn t_mat, FILE* logfp);

/**
 * @brief Trouve le vainqueur d'un scrutin uninominal à 2 tour et affiche le résultat dans la destination "logfp"
 *
 * @param t_mat Structure t_mat_char_star_dyn contenant la liste des votes (Non modifié)
 * @param logfp Destination d'affichage
 */
void scrutin_uni2 (const t_mat_char_star_dyn t_mat, FILE* logfp);

#endif
