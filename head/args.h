#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct args {
  char* csv_type;
  char* csv_file;
  char* log_file;
  char* method;
} args;

/**
 * @brief Initialise une structure de type args
 *
 * @param args_struct
 */
void init_args (args* args_struct);

/**
 * @brief Affiche une structure de type args
 *
 * @param args_struct
 */
void show_args (args* args_struct);

/**
 * @brief Affiche une erreur avec un message typique
 *
 * @param err
 */
void err_args (char* err);

/**
 * @brief vérifie que la méthode de scrutin soit valide
 *
 * @param args_struct
 *
 * @return true, si valide, false sinon
 */
bool check_method (args* args_struct);


/**
 * @brief FONCTION ULTIME : Utilise l'enssemble des autres méthodes
 *        pour vérifier les "argc"  arguments passés dans "argv"
 *
 * @param args_struct
 * @param argc
 * @param argv
 *
 * @return true, si valide, false sinon
 */
bool verif_args (args* my_args, int argc, char** argv);
