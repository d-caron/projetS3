#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../head/args.h"
#include "../head/lecture_csv.h"
#include "../head/squelette.h"
#include "../head/csv_to_duel.h"
#include "../head/uni.h"

int main (int argc, char** argv) {

  //  ETAPE 1 : Vérification des arguments
  args my_args;
  init_args (&my_args);

  verif_args (&my_args, argc, argv);


  //  ETAPE 2 : Lecture du fichier csv
  FILE* csv = NULL;                           //  Fichier de stockage du csv
  FILE * logfp;
  
  if (strcmp(my_args.log_file, "\0") == 0) {  //  Pas de fichier de log
    logfp = stdout;                     // Ecriture dans stdout         
  } else {                                    //  Fichier de log
    logfp = fopen(my_args.log_file, "a");           // Ecriture dans le fichier
  }
  
  open_csv(my_args.csv_file, &csv);           //  Ouverture du csv

  t_mat_char_star_dyn t_mat_char;             //  Création de la matrice de char*
  creer_t_mat_char_dyn(&t_mat_char);
  if (strcmp(my_args.csv_type, "-i") == 0) t_mat_char.offset = 3;

  read_csv(&csv, &t_mat_char);                //  Lecture du csv
  fprintf(logfp, "Fichier de vote : \n\n");   //  Affichage du fichier csv
  affiche_t_mat_char_star_dyn(t_mat_char, logfp); 
  

  //  ETAPE 3 : Création de la matrice de duel
  if (strcmp(my_args.method, "uni1") != 0 &&  //  Si on impose pas de méthode uni1, uni2 ou va
      strcmp(my_args.method, "uni2") != 0 &&  // soit, si on à besoin d'une matrice de duel
      strcmp(my_args.method, "va") != 0)
  {
    t_duel_mat t_duel;                        // Création et initialisation de la matrice de duel
    int dim_duel = t_mat_char.nbCol - t_mat_char.offset;
    creer_t_duel_mat(&t_duel, dim_duel);
    init_mat_int(t_duel.mat.tab, dim_duel, dim_duel, 0);

    if (strcmp(my_args.csv_type, "-i") == 0) {  //  Si csv de vote :
      csv_to_duel(t_mat_char, &t_duel);       //  Remplissage de la matrice de duel à partir du csv (vote)
    } else {                                    //  Si csv de duel :
      duel_to_duel(t_mat_char, &t_duel);      //  Remplissage de la matrice de duel à partir du csv (duel)
    }

    fprintf(logfp, "\n\n");                   //  Affichage de la matrice de duel
    fprintf(logfp, "Matrice de duel correspondante : \n\n");
    affiche_t_duel_mat(t_duel, logfp);
  }


  //  ETAPE 4 : Méthode de scrutin
  if (strcmp(my_args.method, "uni1") == 0) {
    scrutin_uni1(t_mat_char, logfp);
  } else if (strcmp(my_args.method, "uni2") == 0) {
    scrutin_uni2(t_mat_char, logfp);
  } else if (strcmp(my_args.method, "cm") == 0) {

  } else if (strcmp(my_args.method, "cp") == 0) {

  } else if (strcmp(my_args.method, "cs") == 0) {

  } else if (strcmp(my_args.method, "va") == 0) {

  } else {
    if (strcmp(my_args.csv_type, "-i") == 0) {
      // Méthodes uni1, uni2, va
      scrutin_uni1(t_mat_char, logfp);
      scrutin_uni2(t_mat_char, logfp);
    }
    // Méthode cm, cp, cs

  }


  //  ETAPE 5 : Fermeture du csv
  close_csv(&csv);

  return 0;
}
