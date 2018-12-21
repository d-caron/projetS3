#include "../head/args.h"
#include "../head/squelette.h"
#include "../head/lecture_csv.h"


int main (int argc, char** argv) {
  // ETAPE 1 : Vérification des arguments
  args my_args;
  init_args (&my_args);

  verif_args (&my_args, argc, argv);

  /*
  // ETAPE 2 : Lecture du fichier csv
  FILE* csv = NULL;
  char** s_csv = NULL;
  
  
  open_csv(my_args.csv_file, &csv);
  read_csv(&csv, &s_csv);
  close_csv(&csv);
  */

  return 0;
}
