/**
 * @file args.h
 *
 * @brief Fichier de déclarations relatives aux arguments
 *
 * Déclare un nouveau type de structure permettant de stocker les arguments
 * ainsi que toutes les fonctions permettant d'initialiser cette nouvelle structure
 * ainsi que de récupérer, stocker, vérifier et afficher les arguments passés au programme
 *
 * @author Dylan CARON
 *
 * @version 1.0.0
 *
 * @date 02/01/2019 
 */

#ifndef _ARGS_
#define _ARGS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * @struct args
 *
 * @brief Structure d'arguments
 *
 * Permet de stocker les arguments afin de pouvoir les réutiliser simplement
 * lorsque l'on à accès à la structure
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
 * @brief Initialise args
 *
 * Initialise une structure de type args 
 * pour la rendre utilisable
 *
 * @param args_struct Pointeur vers la structure à initialiser
 */
void init_args (args* args_struct);

/**
 * @fn void show_args (args* args_struct)
 *
 * @brief Affiche args
 *
 * Affiche une structure args à l'écran
 *
 * @param args_struct pointeur vers la structure que l'on veux afficher
 *
 * @todo ajouter une destination d'affichage à show_args() 
 * pour pouvoir l'afficher dans un fichier de log
 */
void show_args (args* args_struct);

/**
 * @fn void err_args ()
 *
 * @brief Erreur d'arguments
 *
 * Affiche une erreur avec un message typique
 * d'une érreur causé par les arguments
 */
void err_args ();

/**
 * @fn bool check_method (args* args_struct)
 *
 * @brief Vérifie la méthode
 *
 * Vérifie que la méthode de scrutin soit valide
 * par rapport au type de csv passé en paramètre
 *
 * @param args_struct Pointeur vers la structure dont on veux vérifier si la méthode est valide
 *
 * @return true, si valide, false sinon
 */
bool check_method (args* args_struct);


/**
 * @fn void verif_args (args* my_args, int argc, char** argv)
 *
 * @brief Vérifie les arguments
 *
 * Utilise l'enssemble des autres fonctions pour vérifier 
 * les arguments passés lors de l'appel du programme
 *
 * @param args_struct Pointeur vers la structure qui va contenir les arguments
 * @param argc Nombre d'arguments passés
 * @param argv Tableau d'arguments
 */
void verif_args (args* my_args, int argc, char** argv);

#endif
