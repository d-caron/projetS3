/**
 * @file test.c
 *
 * @brief Fichier de tests 
 *
 * Teste les différentes fonctions programés. 
 * Il génère l'exécutable "test"
 *
 * @author Dylan CARON
 *
 * @version 1.0.0
 *
 * @date 02/01/2019 
 */


#include "../head/args.h"
#include "../head/lecture_csv.h"
#include "../head/csv_to_duel.h"


int main (int argc, char** argv) {
  // Vérification des arguments
  args my_args;
  init_args (&my_args);

  verif_args (&my_args, argc, argv);
  show_args (&my_args);

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

  FILE* csv = fopen(my_args.csv_file, "r");

  read_csv(&csv, &t_mat_char);
  
  if (csv != stdout) {
    fclose(csv);
  }

  affiche_t_mat_char_star_dyn(t_mat_char, logfp);

  printf("\n\n");

  t_duel_mat t_duel;
  int dim = t_mat_char.nbCol - t_mat_char.offset;
  creer_t_duel_mat(&t_duel, dim);
  init_mat_int(t_duel.mat.tab, dim, dim,  0);
  csv_to_duel(t_mat_char, &t_duel);

  affiche_t_duel_mat(t_duel, logfp);


  return 0;
}
