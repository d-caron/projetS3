/**
 * @file lecture_csv.c
 *
 * @brief Fichier de définitions relatives à la lecture d'un csv
 *
 * @see ../head/lecture_csv.h
 *
 * @author Dylan CARON
 *
 * @version 1.0.0
 *
 * @date 02/01/2019 
 */


#include "../head/lecture_csv.h"


void read_csv (FILE** csv, t_mat_char_star_dyn* t_mat_char) {  
  int ch;
  int l = 0, c = 0, i = 0;
  int len_s = 1;
  
  // Première ligne (on en profite pour compter le nombre de colones)
  while ((ch = fgetc(*csv)) != '\n') {
    if ((char) ch == '\t') {
      t_mat_char->nbCol ++;
      t_mat_char->tab[l][c][i + 1] = '\0';
      c ++;
      i = 0;
    } else {
      t_mat_char->tab[l][c][i] = (char)ch;
      i ++;
      if (i == len_s) len_s ++;
    }
  }
  
  l ++; c = 0; i = 0;
  t_mat_char->nbRows ++;
  
  // Lignes suivantes (on en profite pour compter le nombre de lignes)
  while ((ch = fgetc(*csv)) != EOF) {
    
    if ((char)ch == '\n') {           // Si on tombe sur une fin de ligne
      t_mat_char->nbRows ++;
      t_mat_char->tab[l][c][i + 1] = '\0';
      l ++;
      c = 0;
      i = 0;
    } else if ((char)ch == '\t') {    // Si on tombe sur une tabulation
      t_mat_char->tab[l][c][i + 1] = '\0';
      c ++;
      i = 0;
    } else {                          // Si c'est un autre caractère
      t_mat_char->tab[l][c][i] = (char)ch;
      i ++;
      if (i == len_s) len_s ++;
    }
  }

  t_mat_char->nbRows --;
}
