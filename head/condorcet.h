/**
 * @file condorcet.h
 *
 * @brief Fichier de déclarations relatives aux méthode de scrutin de condorcet
 *
 * Déclare des fonctions permettant de trouver un vainqueur 
 * selon les méthodes de scrutins de condorcet
 *
 * @author Dylan CARON
 *
 * @version 0.1.0
 *
 * @date 02/01/2019 
 */


#ifndef _CONDORCET_H
#define _CONDORCET_H


#include "squelette.h"
#include <stdbool.h>


/**
 * @fn bool condorcet_vainqueur(t_duel_mat duel, int* v)
 *
 * @brief Trouve le gagnant de condorcet
 *
 * Parcours la matrice de duel "duel" afin de trouver (s'il existe)
 * un vainqueur selon la methode de scrutin de condorcet classique
 * (sans résolution en cas d'égalitée)
 * Stocke le vainqueur, s'il existe, dans l'entier pointé par "v"
 *
 * @param duel Matrice de duel à analyser
 * @param v Pointeur vers le gagnant par condorcet (s'il existe)
 *
 * @return true, s'il y a un gagnant, false sinon
 */
bool condorcet_vainqueur(t_duel_mat duel, int* v);

/**
 * @fn int resolution_minimax(t_duel_mat duel)
 *
 * @brief Applique la méthode minimax
 *
 * Lorsque la méthode de condorcet n'à pas de gagnant, on peux appliquer
 * la méthode de résolution minimax.
 * On cherche le pire score de chaques candidats, et on retient celui qui à le meilleur
 *
 * @param duel Matrice de duel à analyser
 *
 * @return l'indice du vainqueur dans la matrice
 */
int resolution_minimax(t_duel_mat duel);

/**
 * @fn void scrutin_cm(t_mat_char_star_dyn t_mat, t_duel_mat, duel, FILE* logfp)
 *
 * @brief Déroule un scrutin condorcet minimax
 *
 * Déroule un scrutin condorcet minimax avec la matrice de duel "duel"
 * grace aux données des votes de "t_mat" et affiche le vaiqueur dans la destination
 * "logfp"
 *
 * @param t_mat Liste des votes
 * @param duel Matrice de duel correspondante
 * @param logfp Destination d'affichage
 */
void scrutin_cm(t_mat_char_star_dyn t_mat, t_duel_mat duel, FILE* logfp);

/**
 * @fn void scrutin_cp(t_mat_char_star_dyn t_mat, t_duel_mat, duel, FILE* logfp)
 *
 * @brief Déroule un scrutin condorcet paires
 *
 * Déroule un scrutin condorcet paires avec la matrice de duel "duel"
 * grace aux données des votes de "t_mat" et affiche le vaiqueur dans la destination
 * "logfp"
 *
 * @param t_mat Liste des votes
 * @param duel Matrice de duel correspondante
 * @param logfp Destination d'affichage
 */
void scrutin_cp(t_mat_char_star_dyn t_mat, t_duel_mat duel, FILE* logfp);

/**
 * @fn void scrutin_cs(t_mat_char_star_dyn t_mat, t_duel_mat, duel, FILE* logfp)
 *
 * @brief Déroule un scrutin condorcet schulze
 *
 * Déroule un scrutin condorcet schulze avec la matrice de duel "duel"
 * grace aux données des votes de "t_mat" et affiche le vaiqueur dans la destination
 * "logfp"
 *
 * @param t_mat Liste des votes
 * @param duel Matrice de duel correspondante
 * @param logfp Destination d'affichage
 */
void scrutin_cs(t_mat_char_star_dyn t_mat, t_duel_mat duel, FILE* logfp);


#endif
