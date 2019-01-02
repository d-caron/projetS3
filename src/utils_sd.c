/**
 * @file utils_sd.h
 *
 * @brief Défini les fonctions de squelette.h
 *
 * @author Vincent DUGAT, Dylan CARON
 *
 * @version 1.0.0
 *
 * @date 02/01/2019 
 */


#include <stdio.h>
#include <stdlib.h>
#include "../head/squelette.h"


int* creer_tab_int (int dim) {
  int* mem = malloc(dim * sizeof(int));

  if (mem == NULL) {
    perror("Erreur : l'allocation de int s'est mal passée\n");
    exit(2);
  }

  return mem;
}


void init_tab_int (int* tab, int dim, int valeur) {
  for (int i = 0; i < dim; i ++) {
    tab[i] = valeur;
  }
}


void affiche_tab_int (int* tab, int dim, FILE* logfp) {
  for (int i = 0; i < dim - 1; i ++) {
    fprintf(logfp, "%d\t", tab[i]);
  }

  fprintf(logfp, "%d\n", tab[dim - 1]);
}


int** creer_mat_int (int nbRows, int nbCol) {
  int** mem = malloc(nbRows * sizeof (int*));

  if (mem == NULL) {
    perror("Erreur : l'allocation de int* s'est mal passée\n");
    exit(2);
  }

  for (int i = 0; i < nbRows; i ++) {
    mem[i] = creer_tab_int(nbCol);
  }

  return mem;
}


void init_mat_int (int** mat, int nbRows, int nbCol, int valeur) {
  for(int l = 0; l < nbRows; l ++) {
    for(int c = 0; c < nbCol; c ++) {
      mat[l][c] = valeur;
    }
  }
}


void affiche_mat_int (int** duels_mat, int nbRows, int nbCol, FILE* logfp) {
  for (int l = 0; l < nbRows; l ++) {
    affiche_tab_int(duels_mat[l], nbCol, logfp);
  }
}


void creer_t_tab_int_dyn (t_tab_int_dyn* stTab, int dim) {
  stTab->dim = dim;
  stTab->tab = creer_tab_int(dim);
}


void affiche_t_tab_int_dyn (t_tab_int_dyn t_tab, FILE *logfp) {
  affiche_tab_int(t_tab.tab, t_tab.dim, logfp);
}


void creer_t_mat_int_dyn (t_mat_int_dyn* stTab, int nbRows, int nbCol) {
  stTab->nbRows = nbRows;
  stTab->nbCol = nbCol;
  stTab->tab = creer_mat_int(nbRows, nbCol);
}


void affiche_t_mat_int_dyn (t_mat_int_dyn t_tab, FILE* logfp) {
  affiche_mat_int(t_tab.tab, t_tab.nbRows, t_tab.nbCol, logfp);
}


void creer_t_mat_char_dyn (t_mat_char_star_dyn* s_tabmot) {
  s_tabmot->nbRows = 1;
  s_tabmot->nbCol = 1;
  s_tabmot->offset = 0;
  
  s_tabmot->tab = malloc(STR_MAT_ROW * sizeof(char**));

  if (s_tabmot->tab == NULL) {
    perror("Erreur : l'allocation de char** s'est mal passée\n");
    exit(2);
  }
  
  for (int i = 0; i < STR_MAT_ROW; i ++) {
    s_tabmot->tab[i] = malloc(STR_MAT_COL * sizeof(char*));

    if (s_tabmot->tab[i] == NULL) {
      perror("Erreur : l'allocation de char* s'est mal passée\n");
      exit(2);
    }
    
    for (int j = 0; j < STR_MAT_COL; j ++) {
      s_tabmot->tab[i][j] = malloc(STR_LEN * sizeof(char));

      if (s_tabmot->tab[i][j] == NULL) {
        perror("Erreur : l'allocation de char s'est mal passée\n");
        exit(2);
      }
    }
  }
}


void affiche_t_mat_char_star_dyn (t_mat_char_star_dyn t_tabmots, FILE* logfp) {
  for (int l = 0; l < t_tabmots.nbRows; l ++) {
    for (int c = 0; c < t_tabmots.nbCol - 1; c ++) {
      fprintf(logfp, "%s\t", t_tabmots.tab[l][c]);
    }

    fprintf(logfp, "%s\n", t_tabmots.tab[l][t_tabmots.nbCol - 1]);
  }
}


void creer_t_duel_mat (t_duel_mat* duel, int dim) {
  creer_t_mat_int_dyn(&duel->mat, dim, dim);
  
  duel->entete = malloc(dim * sizeof(char*));

  if (duel->entete == NULL) {
    perror("Erreur : l'allocation de char* s'est mal passée\n");
    exit(2);
  }

  for (int c = 0; c < dim; c ++) {
    duel->entete[c] = malloc(STR_LEN * sizeof(char));

    if (duel->entete[c] == NULL) {
      perror("Erreur : l'allocation de char s'est mal passée\n");
    }
  }
}


void affiche_t_duel_mat (t_duel_mat duel, FILE* logfp) {
  for (int c = 0; c < duel.mat.nbCol - 1; c ++) {
    fprintf(logfp, "%s\t", duel.entete[c]);
  }

  fprintf(logfp, "%s\n", duel.entete[duel.mat.nbCol - 1]);

  affiche_t_mat_int_dyn(duel.mat, logfp);
}
