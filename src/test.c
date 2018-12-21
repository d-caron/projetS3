#include "../head/args.h"
#include "../head/lecture_csv.h"


int main (int argc, char** argv) {
  // Vérification des arguments
  args my_args;
  init_args (&my_args);

  verif_args (&my_args, argc, argv);

  printf("\n\n");  

  // Test des structures des fichiers squelette.h/utils_sd.c
  FILE* logfp = NULL;

  t_tab_int_dyn t_tab;
  creer_t_tab_int_dyn(&t_tab, 10);
  init_tab_int(t_tab.tab, t_tab.dim, 555);
  affiche_t_tab_int_dyn(t_tab, logfp);

  printf("\n\n");

  t_mat_int_dyn t_mat;
  creer_t_mat_int_dyn(&t_mat, 5, 10);
  init_mat_int(t_mat.tab, t_mat.nbRows, t_mat.nbCol, 21);
  affiche_t_mat_int_dyn(t_mat, logfp);

  printf("\n\n");

  t_mat_char_star_dyn t_mat_char;
  creer_t_mat_char_dyn(&t_mat_char);

  // Lecture du fichier csv

  FILE* csv = NULL;

  open_csv(my_args.csv_file, &csv);
  read_csv(&csv, &t_mat_char);
  close_csv(&csv);

  affiche_t_mat_char_star_dyn(t_mat_char, logfp);


  return 0;
}
