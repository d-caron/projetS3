/**
 * @file main.c
 *
 * @brief Fichier principal
 *
 * Générateur de l'exécutable principal "rev_party"
 * Il vérifie les arguments,
 * Lis le fichier csv,
 * Effectue les methodes de scrutins demandés et
 * Stocke les résultats dans le fichier demandé ou à défaut les affiches à l'écran
 *
 * @author Dylan CARON
 *
 * @version 1.0.0
 *
 * @date 02/01/2019 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../head/args.h"
#include "../head/lecture_csv.h"
#include "../head/squelette.h"
#include "../head/csv_to_duel.h"
#include "../head/uni.h"
#include "../head/liste.h"
#include "../head/duel_to_liste.h"
#include "../head/graphe_python.h"


int main (int argc, char** argv) {

  //  ETAPE 1 : Gestion des arguments
  args my_args;
  init_args (&my_args);

  verif_args (&my_args, argc, argv);


  //  ETAPE 2 : Gestion du log
  FILE * logfp;
  
  if (strcmp(my_args.log_file, "\0") == 0) {  //  Pas de fichier de log
    logfp = stdout;                           // Ecriture dans stdout         
  } else {                                    //  Fichier de log
    logfp = fopen(my_args.log_file, "a");     // Ecriture dans le fichier
  }


  //  ETAPE 3 : Gestion du csv
  FILE* csv = fopen(my_args.csv_file, "r");   //  Fichier de stockage du csv
    
  t_mat_char_star_dyn t_mat_char;             //  Création de la matrice de char*
  creer_t_mat_char_dyn(&t_mat_char);
  if (strcmp(my_args.csv_type, "-i") == 0) t_mat_char.offset = 3;

  read_csv(&csv, &t_mat_char);                //  Lecture du csv
  fprintf(logfp, "Fichier de vote : \n\n");   //  Affichage du fichier csv
  affiche_t_mat_char_star_dyn(t_mat_char, logfp); 
  

  //  ETAPE 4 : Gestion de la matrice de duel
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


    //  ETAPE 5 : Gestion de la liste d'arcs
    liste lst;
    createList(&lst);
    remplir_liste(&lst, t_duel, t_mat_char.nbRows - 1);

    fprintf(logfp, "\n\n");                   //  Affichage de la liste d'arcs
    fprintf(logfp, "Liste d'arc correspondante : \n\n");
    dumpList(lst, logfp);

    free(t_duel.entete);
    free(t_duel.mat.tab);


    //  ETAPE 6 : Gestion du graphe
    creer_python(lst);
  }


  //  ETAPE 7 : Méthode de scrutin
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

  free(t_mat_char.tab);


  //  ETAPE 8 : Fermeture des fichiers
  fclose(csv);
  fclose(logfp);

  return 0;
}
