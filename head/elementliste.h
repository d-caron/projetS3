/**
 * @file elementliste.h
 *
 * @brief Fichier de déclarations relatives à l' Elementliste
 * 
 * Déclare le type Elementliste pour représenter une structure s_arc_p qui représente
 * et les fonctions qui permettent de les manipuler
 *
 * @author Vincent DUGAT, Dylan CARON
 *
 * @version 1.0.0
 *
 * @date 02/01/2019 
 */


#ifndef _ELEMENTLISTE_H
#define _ELEMENTLISTE_H


#include "global.h" // définit le type t_arc_p


/**
 * @typedef t_arc_p Elementliste
 *
 * @brief Element liste 
 *
 * Représente une structure t_arc_p (définie dans global.h)
 */
typedef t_arc_p Elementliste;


/**
 * @fn void saisie_element (Elementliste* e)
 *
 * @brief Saisie un Elementliste
 *
 * Demande la saisie d'un Elementliste à l'utilisateur
 *
 * @param e Pointeur vers l' Elementliste qu'on va saisir
 */
void saisie_element (Elementliste* e);

/**
 * @fn void copie_element (Elementliste* cible, Elementliste source)
 *
 * @brief Copie un Elementliste
 *
 * Copie le contenu de l' Elementliste "source" dans "cible"
 *
 * @param cible Pointeur vers l' Elementliste qui recevra la copie
 * @param source Elementliste à copier
 */
void copie_element (Elementliste* cible, Elementliste source);

/**
 * @fn void afficher_element (Elementliste e, FILE* fp)
 *
 * @brief Affiche un Elementliste
 *
 * Affiche l' Elementliste "e"
 * dans la destination d'affichage "fp"
 *
 * @param e Elementliste à afficher
 * @param fp Destination d'affichage
 */
void afficher_element (Elementliste e, FILE* fp);

/**
 * @fn cmp_elements (Elementliste e1, Elementliste e2)
 *
 * @brief Compare deux Elementslistes
 *
 * Compare chaques attributs des Elementslistes "e1" et "e2"
 * entre eux pour vérifier qu'ils soient égaux
 *
 * @param e1 Premier Elementliste à comparer
 * @param e2 Second Elementliste à comparer
 *
 * @return true si égaux, false sinon
 */
bool cmp_elements (Elementliste e1, Elementliste e2);

#endif
