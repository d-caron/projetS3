/**
 * @file csv_to_duel.c
 *
 * @brief Fichier de définitions relatives à la transformation d'un csv en matrice de duel 
 *
 * @author Dylan CARON
 *
 * @version 1.0.0
 *
 * @date 02/01/2019 
 */


#include "../head/csv_to_duel.h"
#include <stdlib.h>


void csv_to_duel (const t_mat_char_star_dyn t_mat, t_duel_mat* t_duel) {
  for (int c = t_mat.offset; c < t_mat.nbCol; c ++) {
    t_duel->entete[c - t_mat.offset] = t_mat.tab[0][c];
  }
  
  for (int l = 1; l < t_mat.nbRows; l ++) {                   // Pour chaques lignes
    for (int c1 = t_mat.offset; c1 < t_mat.nbCol; c1 ++) {    // et chaques colones,
      for (int c2 = t_mat.offset; c2 < t_mat.nbCol; c2 ++) {  // comparaison avec les autres colones de la même ligne
        if (atoi(t_mat.tab[l][c1]) < atoi(t_mat.tab[l][c2])) {
          t_duel->mat.tab[c1 - t_mat.offset][c2 - t_mat.offset] ++;
        }
      }
    }
  }   
}


void duel_to_duel (const t_mat_char_star_dyn t_mat, t_duel_mat* t_duel) {
  for (int c = t_mat.offset; c < t_mat.nbCol; c ++) {
    t_duel->entete[c - t_mat.offset] = t_mat.tab[0][c];
  }

  for (int l = 1; l < t_mat.nbRows; l ++) {                   // Pour chaques lignes
    for (int c = t_mat.offset; c < t_mat.nbCol; c ++) {       // et chaques colones,
      t_duel->mat.tab[l - 1][c] = atoi(t_mat.tab[l][c]);
    }
  } 

}
