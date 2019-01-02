/**
 * @file args.h
 *
 * @brief Déclare un nouveau type de structure permettant de stocker les arguments
 *  ainsi que toutes les fonctions permettant d'initialiser cette nouvelle structure
 *  et permettant de récupérer, stocker, vérifier et afficher les arguments passés au programme
 *
 * @author Dylan CARON
 *
 * @version 1.0.0
 *
 * @date 02/01/2019 
 */

#ifndef _ARGS_H
#define _ARGS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * @struct args
 *
 * @typedef args args
 *
 * @brief Permet de stocker les arguments afin de pouvoir les réutiliser simplement
 *  lorsque l'on à accès à la structure
 */
typedef struct args {
  char* csv_type;
  char* csv_file;
  char* log_file;
  char* method;
} args;

/**
 * @fn void init_args (args* args_struct)
 *
 * @brief Initialise une structure de type args
 *
 * @param args_struct Pointeur vers la structure à initialiser
 */
void init_args (args* args_struct);

/**
 * @fn void show_args (args* args_struct)
 *
 * @brief Affiche une structure de type args
 *
 * @param args_struct pointeur vers la structure que l'on veux afficher
 */
void show_args (args* args_struct);

/**
 * @fn void err_args ()
 *
 * @brief Affiche une erreur avec un message typique'une érreur causé par les arguments
 */
void err_args ();

/**
 * @fn bool check_method (args* args_struct)
 *
 * @brief vérifie que la méthode de scrutin soit valide
 *
 * @param args_struct Pointeur vers la structure dont on veux vérifier si la méthode est valide
 *
 * @return true, si valide, false sinon
 */
bool check_method (args* args_struct);


/**
 * @fn void verif_args (args* my_args, int argc, char** argv)
 *
 * @brief Utilise l'enssemble des autres fonctions pour vérifier 
 *  les arguments passés lors de l'appel du programme
 *
 * @param args_struct Pointeur vers la structure qui va contenir les arguments
 * @param argc Nombre d'arguments passés
 * @param argv Tableau d'arguments
 */
void verif_args (args* my_args, int argc, char** argv);

#endif
