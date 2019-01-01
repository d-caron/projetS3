#include "../head/uni.h"
#include "../head/squelette.h"


/**
 * @brief Cherche la valeur min de la ligne et la stocke dans *min
 *
 * @param t_mat
 * @param l
 * @param min
 *
 * @return N° de la colonne correspondant au min
 */
int recup_min (t_mat_char_star_dyn t_mat, int l, int* min) {
  *min = atoi(t_mat.tab[l][t_mat.offset]);
  int res = 0;

  for (int c = t_mat.offset + 1; c < t_mat.nbCol; c ++) {
    if (atoi(t_mat.tab[l][c]) < *min) {
      *min = atoi(t_mat.tab[l][c]);
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
 * @param min
 * @param res
 *
 * @return true si unique, false sinon
 */
bool verif_unicite (t_mat_char_star_dyn t_mat, int l, int min, int res) {
  for (int c = t_mat.offset; c < t_mat.nbCol; c ++) {
    if (atoi(t_mat.tab[l][c]) == min && res != c - t_mat.offset) {
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
void uni_tour_1 (t_mat_char_star_dyn t_mat, t_tab_int_dyn* t_res) {
  int min, res;
  
  for (int l = 1; l < t_mat.nbRows; l ++) {

    res = recup_min(t_mat, l, &min);
    if (verif_unicite(t_mat, l, min, res)) {      
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
void scrutin_uni1 (t_mat_char_star_dyn t_mat, FILE* logfp) {
  int i_win = 0;
  t_tab_int_dyn t_res;
  creer_t_tab_int_dyn(&t_res, t_mat.nbCol - t_mat.offset);
  init_tab_int(t_res.tab, t_res.dim, 0);
  
  uni_tour_1(t_mat, &t_res);

  for (int c = 0; c < t_res.dim - 1; c ++) {
    if (t_res.tab[c + 1] > t_res.tab[i_win]) {
      i_win = c + 1;
    }
  }
  fprintf(logfp, "\n\n");
  fprintf(logfp, "Mode de scrutin : uninominal à 1 tour, %d candidat, %d votant, vainqueur = %s, score = %d\%\n", 
      t_mat.nbCol - t_mat.offset, 
      t_mat.nbRows - 1, 
      t_mat.tab[0][t_mat.offset + i_win], 
      (t_res.tab[i_win] * 100) / (t_mat.nbRows - 1)
  );
}

