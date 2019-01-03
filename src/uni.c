/**
 * @file uni.c
 *
 * @brief Fichier de définitions relatives aux méthodes de scrutin uninominales
 *
 * @author Dylan CARON
 *
 * @version 1.0.0
 *
 * @date 02/01/2019 
 */


#include "../head/uni.h"


int recup_min (const t_mat_char_star_dyn t_mat, const int l, int* min) {
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


bool verif_unicite (const t_mat_char_star_dyn t_mat, const int l, const int min, const int res, int* null) {
  for (int c = t_mat.offset; c < t_mat.nbCol; c ++) {
    if (atoi(t_mat.tab[l][c]) == min && res != c - t_mat.offset) {
      (*null) ++;
      return false;
    } 
  }

  return true;
}


void uni_tour_1 (const t_mat_char_star_dyn t_mat, t_tab_int_dyn* t_res, int* null) {
  int min, res;
  
  for (int l = 1; l < t_mat.nbRows; l ++) {

    res = recup_min(t_mat, l, &min);
    if (verif_unicite(t_mat, l, min, res, null)) {      
      t_res->tab[res] ++;
    }
  }
}


void uni_tour_2 (const t_mat_char_star_dyn t_mat, const int i_c1, const int i_c2, int* res_c1, int* res_c2, int* null) {
  *res_c1 = 0; *res_c2 = 0;

  for (int l = 1; l < t_mat.nbRows; l ++) {
    if (atoi(t_mat.tab[l][i_c1 + t_mat.offset]) < atoi(t_mat.tab[l][i_c2 + t_mat.offset])) {
      (*res_c1) ++;
    } else if (atoi(t_mat.tab[l][i_c1 + t_mat.offset]) > atoi(t_mat.tab[l][i_c2 + t_mat.offset])) {
      (*res_c2) ++;
    } else {
      (*null) ++;
    }
  }
}


void scrutin_uni1 (const t_mat_char_star_dyn t_mat, FILE* logfp) {
  int i_win = 0;
  int null = 0;
  t_tab_int_dyn t_res;
  creer_t_tab_int_dyn(&t_res, t_mat.nbCol - t_mat.offset);
  init_tab_int(t_res.tab, t_res.dim, 0);
  
  uni_tour_1(t_mat, &t_res, &null);

  for (int c = 0; c < t_res.dim - 1; c ++) {
    if (t_res.tab[c + 1] > t_res.tab[i_win]) {
      i_win = c + 1;
    }
  }

  fprintf(logfp, "\n\n");
  fprintf(logfp, "Nombre de votes nulls pour uninominal : %d\n", null);
  fprintf(logfp, "mode de scrutin : uninominal à 1 tour, %d candidat, %d votant, vainqueur = %s, score = %d%c\n", 
      t_mat.nbCol - t_mat.offset, 
      t_mat.nbRows - 1, 
      t_mat.tab[0][t_mat.offset + i_win], 
      (t_res.tab[i_win] * 100) / (t_mat.nbRows - null - 1),
      '%'
  );
}


void scrutin_uni2 (const t_mat_char_star_dyn t_mat, FILE* logfp) {
  int i_win1 = 0, i_win2;
  int null = 0;
  t_tab_int_dyn t_res;
  creer_t_tab_int_dyn(&t_res, t_mat.nbCol - t_mat.offset);
  init_tab_int(t_res.tab, t_res.dim, 0);
  
  uni_tour_1(t_mat, &t_res, &null);

  for (int c = 0; c < t_res.dim - 1; c ++) {
    if (t_res.tab[c + 1] > t_res.tab[i_win1]) {
      i_win1 = c + 1;
    }
  }

  fprintf(logfp, "\n\n");
  fprintf(logfp, "Nombre de votes nulls pour uninominal (tour 1) : %d\n", null);
  fprintf(logfp, "mode de scrutin : uninominal à 2 tour, tour 1, %d candidat, %d votant, vainqueur = %s, score = %d%c\n", 
      t_mat.nbCol - t_mat.offset, 
      t_mat.nbRows - 1, 
      t_mat.tab[0][t_mat.offset + i_win1], 
      (t_res.tab[i_win1] * 100) / (t_mat.nbRows - null - 1),
      '%'
  );

  if ((t_res.tab[i_win1] * 100) / (t_mat.nbRows - 1) > 50) {
    return;
  }
  
  if (i_win1 != 0) {
    i_win2 = 0;
  } else {
    i_win2 = 1;
  }

  for (int c = 0; c < t_res.dim - 1; c ++) {
    if (t_res.tab[c + 1] > t_res.tab[i_win2] && c + 1 != i_win1) {
      i_win2 = c + 1;
    }
  }
  
  fprintf(logfp, "Mode de scrutin : uninominal à 2 tour, tour 1, %d candidat, %d votant, vainqueur = %s, score = %d%c\n", 
      t_mat.nbCol - t_mat.offset, 
      t_mat.nbRows - 1, 
      t_mat.tab[0][t_mat.offset + i_win2], 
      (t_res.tab[i_win2] * 100) / (t_mat.nbRows - 1),
      '%'
  );

  int c1 = 0, c2 = 0;
  null = 0;
  uni_tour_2(t_mat, i_win1, i_win2, &c1, &c2, &null);
  
  if (c1 < c2) {
    i_win1 = i_win2;
  }

  fprintf(logfp, "\n");
  fprintf(logfp, "Nombre de votes nulls pour uninominal (tour 2) : %d\n", null);
  fprintf(logfp, "Mode de scrutin : uninominal à 2 tour, tour 2, 2 candidat, %d votant, vainqueur = %s, score = %d%c\n", 
      t_mat.nbRows - 1, 
      t_mat.tab[0][t_mat.offset + i_win1],
      (MAX(c1, c2) * 100) / (t_mat.nbRows - null - 1),
      '%'
  );
}
