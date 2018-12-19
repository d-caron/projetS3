#include "../head/args.h"
#include "../head/squelette.h"
#include "../head/lecture_csv.h"


int main (int argc, char** argv) {
  // Vérification des arguments
  args my_args;
  init_args (&my_args);

  verif_args (&my_args, argc, argv);
  
  /* Lecture du fichier csv

  FILE* csv = NULL;
  char** s_csv = NULL;

  open_csv(my_args.csv_file, &csv);
  read_csv(&csv, &s_csv);
  close_csv(&csv);
  */

  // Test des structures des fichiers squelette.h/utils_sd.c
  FILE* logfp = NULL;

  int* tab = creer_tab_int(10);
  init_tab_int(tab, 10, 42);
  affiche_tab_int(tab, 10, logfp);

  return 0;
}
