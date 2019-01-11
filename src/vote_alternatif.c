#include "../head/vote_alternatif.h"

void scrutin_alternatif (const t_mat_char_star_dyn vote, FILE* logfp) {
  t_tab_int_dyn t_candidats;
  t_tab_int_dyn t_res;
  creer_t_tab_int_dyn(&t_candidats, vote.nbCol - vote.offset);
  creer_t_tab_int_dyn(&t_res, vote.nbCol - vote.offset);
  init_tab_int(t_res.tab, t_res.dim, 0);

  for (int i = 0; i < vote.nbCol - vote.offset; i ++) {
    t_candidats.tab[i] = i;
  }
  
  int min;

  while (t_res.dim > 1) {
    min = 0;
    
    derouler_alternatif(vote, t_candidats, &t_res);  // On déroule un tour de vote
 
    for (int i = 1; i < t_res.dim; i ++) {          // On cherche le candidat qui à perdu
      if (t_res.tab[i] < t_res.tab[i - 1]) {
        min = i;
      }
    }

    // Elimination du candidat qui à perdu
    t_candidats.tab[min] = t_candidats.tab[t_candidats.dim - 1];
    t_candidats.dim --;
    t_res.dim --;
    init_tab_int(t_res.tab, t_res.dim, 0);
  }

  fprintf(logfp, "\n\n");
  fprintf(logfp, "mode de scrutin : vote alternatif, %d candidat, %d votant, vainqueur = %s\n", 
      vote.nbCol - vote.offset, 
      vote.nbRows - 1, 
      vote.tab[0][vote.offset + t_candidats.tab[0]]
  );
  
}


void derouler_alternatif(const t_mat_char_star_dyn vote, const t_tab_int_dyn t_candidats, t_tab_int_dyn* t_res) {
  int score;
  int candidat;
  
  for (int l = 1; l < vote.nbRows; l ++) {
    score = vote.nbCol - vote.offset;
    candidat = 0;

    for (int c = 0; c < t_candidats.dim; c ++) {
      if(atoi(vote.tab[l][t_candidats.tab[c] + vote.offset]) < score) {
        score = atoi(vote.tab[l][t_candidats.tab[c] + vote.offset]);
        candidat = c;
      }
    }

    t_res->tab[candidat] ++;
  }
}
