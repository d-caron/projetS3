#include "../head/uni.h"
#include "../head/squelette.h"


/**
 * @brief Cherche la valeur max de la ligne et la stocke dans *max
 *
 * @param t_mat
 * @param l
 * @param max
 *
 * @return N° de la colonne correspondant au max
 */
int recup_max(t_mat_char_star_dyn t_mat, int l, int* max) {
  int res;
  *max = 0;

  for (int c = t_mat.offset; c < t_mat.nbCol; c ++) {
    if (atoi(t_mat.tab[l][c]) > *max) {
      *max = atoi(t_mat.tab[l][c]);
      res = c - t_mat.offset;
    } 
  }

  return res;
}


/**
 * @brief Vérifie l'unicité du vote
 *
 * @param t_mat
 * @param l
 * @param max
 * @param res
 *
 * @return true si unique, false sinon
 */
bool verif_unicite(t_mat_char_star_dyn t_mat, int l, int max, int res) {
  for (int c = t_mat.offset; c < t_mat.nbCol; c ++) {
    if (atoi(t_mat.tab[l][c]) == max && res != c - t_mat.offset) {
      return false;
    } 
  }

  return true;
}


/**
 * @brief Déroule le premier tout d'un vote uninominal et stocke les scores dans t_res
 *
 * @param t_mat
 * @param t_res
 */
void uni_tour_1(t_mat_char_star_dyn t_mat, t_tab_int_dyn* t_res) {
  int max, res;

  for (int l = 1; l < t_mat.nbRows; l ++) {

    res = recup_max(t_mat, l, &max);
    if (verif_unicite(t_mat, l, max, res)) {
      printf("res = %d\n", res);
      t_res->tab[res] ++;
    }
  }
}


/**
 * @brief Trouve le vainqueur d'un scrutin uninominal à 1 tour et affiche le résultat
 *
 * @param t_mat
 * @param logfp
 */
void scrutin_uni1(t_mat_char_star_dyn t_mat, FILE* logfp) {
  int i_win = 0;
  t_tab_int_dyn t_res;
  uni_tour_1(t_mat, &t_res);

  for (int c = 0; c < t_res.dim - 1; c ++) {
    if (t_res.tab[c + 1] > t_res.tab[c]) {
      i_win = c;
    }
  }

  fprintf(logfp, "Mode de scrutin : uninominal à 1 tour, %d candidat, %d votant, vainqueur = %s, score = %d", 
      t_mat.nbCol - t_mat.offset, 
      t_mat.nbRows - 1, 
      t_mat.tab[0][t_mat.offset + i_win], 
      (t_res.tab[i_win] * 100) / (t_mat.nbRows - 1)
  );
}

