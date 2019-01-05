/**
 * @file graphe_python.h
 *
 * @brief Fichier de déclaration relative à la création du fichier python affichant les graphes
 *
 * Déclare la fonction permettant de créer le fichier python qui pourra 
 * afficher un graphe représentant une liste d'arc
 *
 * @author Dylan CARON
 *
 * @version 0.0.1
 *
 * @date 05/01/2019 
 */


#ifndef _GRAPHE_PYTHON_H
#define _GRAPHE_PYTHON_H


#include "liste.h"


/**
 * @fn void creer_python (liste lst)
 *
 * @brief Crée l'exécutable python
 *
 * Ecrit l'exécutable python permettant d'afficher un graphe 
 * représentant une liste d'arc passé en paramètre
 *
 * @param lst liste d'arc à représenter
 */
void creer_python (liste lst);


#endif
