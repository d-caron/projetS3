/**
 * @file duel_to_liste.c
 *
 * @brief Fichier de définition relative à la transformation d'une matrice de duel en liste d'arc
 *
 * @author Dylan CARON
 *
 * @version 1.0.0
 *
 * @date 02/01/2019 
 */


#include "../head/duel_to_liste.h"


void remplir_liste (liste* lst, t_duel_mat duel, int nb_vote) {
  Elementliste e;
  
  for (int l = 0; l < duel.mat.nbRows; l ++) {
    for (int c = 0; c < duel.mat.nbCol; c ++) {
      if (duel.mat.tab[l][c] > duel.mat.tab[c][l]) {
        e.orig = l;
        e.dest = c;
        e.poids = duel.mat.tab[l][c];

        addTailList (lst, e);
      }
    }
  }
}
