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
void err_args (char* err) {
  printf("%s\n", err);
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
  if (strcmp(args_struct->method, "cm") == 0 ||
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


int main (int argc, char** argv) {
  args my_args;
  init_args (&my_args);

  int i = 1;
  while (i < argc) {
    if (strcmp(argv[i], "-i") == 0 || strcmp(argv[i], "-d") == 0) {
      if (strcmp(my_args.csv_type, "\0") == 0) {
        my_args.csv_type = argv[i];
        if (++i < argc) {
          my_args.csv_file = argv[i];
          i++;
        } 
        else { 
          err_args("Erreur, vous n'avez pas spécifié le nom du fichier csv");
          return -1;
        }
      } 
      else {
        err_args("Erreur, vous essayez de passer 2 fichiers csv en paramètres");
        return -1;
      }


    } else if (strcmp(argv[i], "-l") == 0) {
      if (++i < argc) {
        my_args.log_file = argv[i];
        i++;
      } else {
        err_args("Erreur, vous n'avez pas spécifié le nom du fichier log");
        return -1;
      }
      

    } else if (strcmp(argv[i], "-m") == 0) {
      if (++i < argc) {
        my_args.method = argv[i];
        i++;
      } else {
        err_args("Erreur, vous n'avez pas spécifié de méthode");
        return -1;
      }

    } else {
      err_args("Erreur, les arguments passés ne sont pas valides\n");
      return -1;
    }
   
  }

  if (!check_method (&my_args)) {
    err_args("Erreur, la méthode spécifié n'est pas valide");
    return -1;
  }

  show_args(&my_args);

  return 0;
}
