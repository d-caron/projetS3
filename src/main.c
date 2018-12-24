#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../head/args.h"
#include "../head/lecture_csv.h"
#include "../head/squelette.h"
#include "../head/csv_to_duel.h"


int main (int argc, char** argv) {
  // ETAPE 1 : Vérification des arguments
  args my_args;
  init_args (&my_args);

  verif_args (&my_args, argc, argv);

  // ETAPE 2 : Lecture du fichier csv
  FILE* csv = NULL;  
  open_csv(my_args.csv_file, &csv);

  t_mat_char_star_dyn t_mat_char;
  creer_t_mat_char_dyn(&t_mat_char);

  t_duel_mat t_duel;   

  if (strcmp(my_args.csv_type, "-d") == 0) {  // Si le csv est une matrice de duel :
    read_duel(&csv, &t_duel);
  } else {                                    // Sinon :
    read_csv(&csv, &t_mat_char);

    affiche_t_mat_char_star_dyn(t_mat_char, stdout);

    if (strcmp(my_args.method, "uni1") != 0 &&
        strcmp(my_args.method, "uni2") != 0 &&
        strcmp(my_args.method, "va") != 0)
    {
      int dim_duel = t_mat_char.nbCol - t_mat_char.offset;

      creer_t_duel_mat(&t_duel, dim_duel);
      init_mat_int(t_duel.mat.tab, dim_duel, dim_duel, 0);
      csv_to_duel(t_mat_char, &t_duel);
    }
  }
  
  close_csv(&csv);

  affiche_t_duel_mat(t_duel, stdout);

  return 0;
}
