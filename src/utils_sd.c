#include <stdio.h>
#include <stdlib.h>
#include "../head/squelette.h"


/**
 * @brief Alloue l'espace pour un tableau de dim entier
 *
 * @param dim
 *
 * @return l'espace alloué
 */
int* creer_tab_int (int dim) {
  int* mem = malloc(dim * sizeof(int));

  if (mem == NULL) {
    perror("Erreur : l'allocation de int s'est mal passée\n");
    exit(2);
  }

  return mem;
}

/**
 * @brief Initialise un tableau d'entier de dimension dim avec la valeur passé en paramètre
 *
 * @param tab
 * @param dim
 * @param valeur
 */
void init_tab_int (int* tab, int dim, int valeur) {
  for (int i = 0; i < dim; i ++) {
    tab[i] = valeur;
  }
}

/**
 * @brief Affiche le tableau d'entier passé en paramètre
 *
 * @param tab
 * @param dim
 * @param logfp
 */
void affiche_tab_int (int* tab, int dim, FILE* logfp) {
  for (int i = 0; i < dim - 1; i ++) {
    printf("%d\t", tab[i]);
  }

  printf("%d\n", tab[dim - 1]);
}


/**
 * @brief Alloue l'espace pour une matrice d'entier de nbRows lignes et nbCol colonnes
 *
 * @param nbRows
 * @param nbCol
 *
 * @return l'espace alloué
 */
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

/**
 * @brief Initialise une matrice d'entier de nbRows lignes et nbCol colonnes avec la valeur passé en paramètre
 *
 * @param mat
 * @param nbRows
 * @param nbCol
 * @param valeur
 */
void init_mat_int (int** mat, int nbRows, int nbCol, int valeur) {
  for(int l = 0; l < nbRows; l ++) {
    for(int c = 0; c < nbCol; c ++) {
      mat[l][c] = valeur;
    }
  }
}

/**
 * @brief Affiche la matrice d'entier passé en paramètre
 *
 * @param duels_mat
 * @param nbRows
 * @param nbCol
 * @param logfp
 */
void affiche_mat_int (int** duels_mat, int nbRows, int nbCol, FILE* logfp) {
  for (int l = 0; l < nbRows; l ++) {
    affiche_tab_int(duels_mat[l], nbCol, logfp);
  }
}


/**
 * @brief crée une structure t_tab_int_dyn et alloue l'espace nécessaire
 *
 * @param stTab
 * @param dim
 */
void creer_t_tab_int_dyn (t_tab_int_dyn* stTab, int dim) {
  stTab->dim = dim;
  stTab->tab = creer_tab_int(dim);
}

/**
 * @brief Affiche la structure t_tab_int_dyn passé en parametre
 *
 * @param t_tab
 * @param logfp
 */
void affiche_t_tab_int_dyn (t_tab_int_dyn t_tab, FILE *logfp) {
  affiche_tab_int(t_tab.tab, t_tab.dim, logfp);
}

/**
 * @brief crée une structure t_mat_int_dyn et alloue l'espace nécessaire
 *
 * @param stTab
 * @param nbRows
 * @param nbCol
 */
void creer_t_mat_int_dyn (t_mat_int_dyn* stTab, int nbRows, int nbCol) {
  stTab->nbRows = nbRows;
  stTab->nbCol = nbCol;
  stTab->tab = creer_mat_int(nbRows, nbCol);
}

/**
 * @brief Affiche la structure t_mat_int_dyn passé en paramètre
 *
 * @param t_tab
 * @param logfp
 */
void affiche_t_mat_int_dyn (t_mat_int_dyn t_tab, FILE* logfp) {
  affiche_mat_int(t_tab.tab, t_tab.nbRows, t_tab.nbCol, logfp);
}

/**
 * @brief crée une structure t_mat_char_dyn et alloue l'espace nécessaire
 *
 * @param s_tabmot
 */
void creer_t_mat_char_dyn (t_mat_char_star_dyn* s_tabmot) {
  s_tabmot->nbRows = 1;
  s_tabmot->nbCol = 1;
  s_tabmot->offset = 3;
  
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

/**
 * @brief Affiche la structure t_mat_char_star_dyn passé en paramètre
 *
 * @param t_tabmots
 * @param logfp
 */
void affiche_t_mat_char_star_dyn (t_mat_char_star_dyn t_tabmots, FILE* logfp) {
  for (int l = 0; l < t_tabmots.nbRows; l ++) {
    for (int c = 0; c < t_tabmots.nbCol - 1; c ++) {
      printf("%s\t", t_tabmots.tab[l][c]);
    }

    printf("%s\n", t_tabmots.tab[l][t_tabmots.nbCol - 1]);
  }
}


/**
 * @brief Crée une structure t_duel_mat et alloue l'espace nécessaire
 *
 * @param duel
 * @param nbRows
 * @param nbCol
 */
void creer_t_duel_mat (t_duel_mat* duel, int nbRows, int nbCol) {
  creer_t_mat_int_dyn(&duel->mat, nbRows, nbCol);
  
  duel->entete = malloc(nbCol * sizeof(char*));

  if (duel->entete == NULL) {
    perror("Erreur : l'allocation de char* s'est mal passée\n");
    exit(2);
  }

  for (int c = 0; c < nbCol; c ++) {
    duel->entete[c] = malloc(STR_LEN * sizeof(char));

    if (duel->entete[c] == NULL) {
      perror("Erreur : l'allocation de char s'est mal passée\n");
    }
  }
}

/**
 * @brief Affiche la structure t_duel_mat passé en paramètre
 *
 * @param duel
 * @param logfp
 */
void affiche_t_duel_mat (t_duel_mat duel, FILE* logfp) {
  for (int c = 0; c < duel.mat.nbCol - 1; c ++) {
    printf("%s\t", duel.entete[c]);
  }

  printf("%s\n", duel.entete[duel.mat.nbCol - 1]);

  affiche_t_mat_int_dyn(duel.mat, logfp);
}
