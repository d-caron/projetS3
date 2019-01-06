/**
 * @file vote_alternatif.h
 *
 * @brief Fichier de déclaraion relatives à la méthode de scrutin vote alternatif
 *
 * Déclare un enssemble de fonctions permettant de dérouler 
 * un scrutin de vote alternatif
 *
 * @author Dylan CARON
 *
 * @version 1.0.0
 *
 * @date 02/01/2019 
 */


#ifndef _VOTE_ALTERNATIF_H
#define _VOTE_ALTERNATIF_H


#include "squelette.h"

/**
 * @fn void scrutin_alternatif (const t_mat_char_star_dyn vote)
 *
 * @brief Scrutin de vote alternatif
 *
 * Trouve le vainqueur d'un scrutin de vote alternatif
 * et affiche le résultat dans la destination "logfp"
 *
 * @param votet_mat_char_star_dyn contenant la liste des votes (Non modifié)
 * @param logfp Destination d'affichage
 */
void scrutin_alternatif (const t_mat_char_star_dyn vote, FILE* logfp);

/**
 * @fn void derouler_alternatif(const t_mat_char_star_dyn vote, const t_tab_int_dyn t_candidat, t_tab_int_dyn* t_res)
 *
 * @brief Déroule un tour de vote alternatif
 *
 * Déroule un tour de vote alternatif avec les candidats de "t_candidat" et les votes du fichier "vote"
 * et stocke les résultats dans "t_res"
 *
 * @param vote Structure t_mat_char_star_dyn contenant les votes
 * @param t_candidat Tableau contenant les indices des candidats encore en lice
 * @param t_res Pointeur vers le tableau qui contiendra les résultats
 */
void derouler_alternatif(const t_mat_char_star_dyn vote, const t_tab_int_dyn t_candidat, t_tab_int_dyn* t_res);


#endif
