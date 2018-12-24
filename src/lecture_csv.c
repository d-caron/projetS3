#include "../head/lecture_csv.h"

/**
 * @brief ouvre un fichier csv et le stocke.
 * Crash en cas de problème d'ouverture
 *
 * @param chemin
 * @param csv
 *
 * @return
 */
void open_csv (char* chemin, FILE** csv) {
  *csv = fopen(chemin, "r");

  if (*csv == NULL) {
    printf("Impossible d'ouvrir le fichier %s\n", chemin);
    exit(EXIT_FAILURE);
  }
}

/**
 * @brief Lis le fichier csv et 
 * stocke son contenu dans une structure t_mat_char_star_dyn
 *
 * @param csv
 * @param t_mat_char
 *
 * @return 
 */
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

/**
 * @brief Lis le fichier csv (matrice de duel) et 
 * stocke son contenu dans une structure t_duel_mat
 *
 * @param csv
 * @param t_duel
 */
void read_duel (FILE** csv, t_duel_mat* t_duel) {
  int ch, l = 0, c = 0, i = 0;
  t_duel->mat.tab[l][c] = 0;

  // Stockage de l'entete
  while (ch = fgetc(*csv) != '\n') {
    if ((char) ch == '\t') {          // Si on tombe sur une tabulation
      t_duel->mat.nbCol ++;
      c ++;
      i = 0;
    } else {                          // Si on tombe sur un caractère
      t_duel->entete[c][i] = (char) ch;
    }
  }

  c = 0;

  // Stockage de la matrice
  while (ch = fgetc(*csv) != EOF) {
    if ((char) ch == '\n') {          // Si on tombe sur une fin de ligne
      t_duel->mat.nbRows ++;      
      l ++;
      c = 0;
      t_duel->mat.tab[l][c] = 0;
    } else if ((char) ch == '\t') {   // Si on tombe sur une tabulation
      c ++;
      t_duel->mat.tab[l][c] = 0;
    } else {                          // Si on tombe sur un caractère
      t_duel->mat.tab[l][c] *= 10;
      t_duel->mat.tab[l][c] += ch;
    }
  }
}


/**
 * @brief ferme le fichier csv ouvert
 *
 * @param csv
 */
void close_csv (FILE** csv) {
  fclose(*csv); 
}
