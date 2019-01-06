/**
 * @file condorcet.c
 *
 * @brief Fichier de définitions relatives aux méthode de scrutin de condorcet
 *
 * @author Dylan CARON
 *
 * @version 0.1.0
 *
 * @date 02/01/2019 
 */


#include "../head/condorcet.h"


bool condorcet_vainqueur(t_duel_mat duel, int* v) {
  int win;

  for (int l = 0; l < duel.mat.nbRows; l ++) {
    win = 0;

    for (int c = 0; c < duel.mat.nbCol; c ++) {
      if (duel.mat.tab[l][c] > duel.mat.tab[c][l]) {        
        win ++;
      }
    }

    if (win == duel.mat.nbCol - 1) {
      *v = l;
      return true;
    }
  }

  return false;
}


int resolution_minimax(t_duel_mat duel) {
  t_tab_int_dyn t_res;
  creer_t_tab_int_dyn(&t_res, duel.mat.nbCol);
  init_tab_int(t_res.tab, duel.mat.nbCol, 999);

  for (int l = 0; l < duel.mat.nbRows; l ++) {
    for (int c = 0; c < duel.mat.nbCol; c ++) {
      if (l != c && duel.mat.tab[l][c] < t_res.tab[l]) {        
        t_res.tab[l] = duel.mat.tab[l][c];
      }
    }
  }

  int win = 0;


  for (int i = 1; i < t_res.dim; i ++) {
    if (t_res.tab[i] > t_res.tab[i - 1]) {
      win = i;
    }
  }
  
  return win;
}


void scrutin_cm(t_mat_char_star_dyn t_mat, t_duel_mat duel, FILE* logfp) {
  int v = -1;
  
  fprintf(logfp, "\n\n");
  
  if (! condorcet_vainqueur(duel, &v)) {
    v = resolution_minimax(duel);
  }

  fprintf(logfp, "Mode de scrutin : condorcet minimaux, %d candidats, vainqueur = %s\n",
      t_mat.nbCol - t_mat.offset,
      t_mat.tab[0][v + t_mat.offset]
  );
}


void scrutin_cp(t_mat_char_star_dyn t_mat, t_duel_mat duel, FILE* logfp) {
  int v = -1;

  fprintf(logfp, "\n\n");
  
  if (condorcet_vainqueur(duel, &v)) {
    fprintf(logfp, "Mode de scrutin : condorcet paires, %d candidats, vainqueur = %s\n",
        t_mat.nbCol - t_mat.offset,
        t_mat.tab[0][v + t_mat.offset]
    );
  } else {
    fprintf(logfp, "Mode de scrutin : condorcet paires, %d candidats\n",
        t_mat.nbCol - t_mat.offset
    );

    fprintf(logfp, "Pas de gagnant, pas de mode de résolution pour condorcet paires\n");
  }
}


void scrutin_cs(t_mat_char_star_dyn t_mat, t_duel_mat duel, FILE* logfp) {
  int v = -1;

  fprintf(logfp, "\n\n");
  
  if (condorcet_vainqueur(duel, &v)) {
    fprintf(logfp, "Mode de scrutin : condorcet schulze, %d candidats, vainqueur = %s\n",
        t_mat.nbCol - t_mat.offset,
        t_mat.tab[0][v + t_mat.offset]
    );
  } else {
    fprintf(logfp, "Mode de scrutin : condorcet schulze, %d candidats\n",
        t_mat.nbCol - t_mat.offset
    );

    fprintf(logfp, "Pas de gagnant, pas de mode de résolution pour condorcet schulze\n");
  }
}
