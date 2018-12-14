#include "../head/args.h"


/**
 * @brief Initialise une structure de type args
 *
 * @param args_struct
 */
void init_args (args* args_struct) {
  args_struct->csv_type = "\0";
  args_struct->csv_file = "\0";
  args_struct->log_file = "\0";
  args_struct->method = "\0";
}

/**
 * @brief Affiche une structure de type args
 *
 * @param args_struct
 */
void show_args (args* args_struct) {
  printf("{\n");
  printf("  csv_type : %s\n", args_struct->csv_type);
  printf("  csv_file : %s\n", args_struct->csv_file);
  printf("  log_file : %s\n", args_struct->log_file);
  printf("  method   : %s\n", args_struct->method);
  printf("}\n");
}

/**
 * @brief Affiche une erreur avec un message typique
 *
 * @param err
 */
void err_args () {
  printf("Usage : rev_party -d|-i <fichier>.csv [-l <fichier>.txt] [-m <methode>]\n");
  printf("pour -i methode peut être égal à : \"uni1\", \"uni2\", \"cm\", \"cp\", \"cs\" ou \"va\"\n");
  printf("pour -d methode peut être égal à : \"cm\", \"cp\" ou \"cs\"\n");
}

/**
 * @brief vérifie que la méthode de scrutin soit valide
 *
 * @param args_struct
 *
 * @return true, si valide, false sinon
 */
bool check_method (args* args_struct) {
  if (strcmp(args_struct->method, "\0") == 0 ||
      strcmp(args_struct->method, "cm") == 0 ||
      strcmp(args_struct->method, "cp") == 0 ||
      strcmp(args_struct->method, "cs") == 0 || (
      strcmp(args_struct->csv_type, "-i") == 0 && (
        strcmp(args_struct->method, "uni1") == 0 ||
        strcmp(args_struct->method, "uni2") == 0 ||
        strcmp(args_struct->method, "va") == 0))) {
    
    return true;
  }

  return false;
}

/**
 * @brief FONCTION ULTIME : Utilise l'enssemble des autres méthodes
 *        pour vérifier les "argc"  arguments passés dans "argv"
 *
 * @param args_struct
 * @param argc
 * @param argv
 */
void verif_args (args* my_args, int argc, char** argv) {
  int i = 1;

  while (i < argc) {
    if (strcmp(argv[i], "-i") == 0 || strcmp(argv[i], "-d") == 0) {
      if (strcmp(my_args->csv_type, "\0") == 0) {
        my_args->csv_type = argv[i];
        if (++i < argc) {
          my_args->csv_file = argv[i];
          i++;
        } 
        else { 
          printf("ERREUR, vous n'avez pas spécifié le nom du fichier csv\n");
          err_args();
          exit(EXIT_FAILURE);
        }
      } 
      else {
        printf("ERREUR, %s ne peut être spécifié après %s\n", argv[i], my_args->csv_type);
        err_args();
        exit(EXIT_FAILURE);
      }


    } else if (strcmp(argv[i], "-l") == 0) {
      if (++i < argc) {
        my_args->log_file = argv[i];
        i++;
      } else {
        printf("Erreur, vous n'avez pas spécifié le nom du fichier log\n");
        err_args();
        exit(EXIT_FAILURE);
      }
      

    } else if (strcmp(argv[i], "-m") == 0) {
      if (++i < argc) {
        my_args->method = argv[i];
        i++;
      } else {
        printf("Erreur, vous n'avez pas spécifié de méthode\n");
        err_args();
        exit(EXIT_FAILURE);
      }

    } else {
      printf("Erreur, les arguments passés ne sont pas valides\n");
      err_args();
      exit(EXIT_FAILURE);
    }
   
  }

  if (!check_method (my_args)) {
    printf("Erreur, la méthode spécifié n'est pas valide\n");
    err_args();
    exit(EXIT_FAILURE);
  }

  show_args(my_args);
}
