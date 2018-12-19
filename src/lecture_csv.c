#include "../head/lecture_csv.h"

/**
 * @brief ouvre un fichier csv et crash en cas de problème d'ouverture
 *
 * @param chemin
 */
void open_csv (char* chemin, FILE** csv) {
  *csv = fopen(chemin, "r");

  if (*csv == NULL) {
    printf("Impossible d'ouvrir le fichier %s\n", chemin);
    exit(EXIT_FAILURE);
  }
}

/**
 * @brief Lis le fichier csv et renvoi son contenu dans une chaine de caractère
 *
 * @param csv
 */
void read_csv (FILE** csv, char*** s_csv) {  
  int i = 0;
  
  if (*csv == NULL) {
    printf("Impossible de lire le fichier\n");
    exit(EXIT_FAILURE);
  }

  while (fgets (*s_csv[i], 10, *csv) != NULL) {
    i ++;
    printf("%s", *s_csv[i-1]);
  }
}


/**
 * @brief ferme le fichier csv ouvert
 *
 * @param csv
 */
void close_csv (FILE** csv) {
  printf("je vais fermer le csv\n");
  fflush(stdout);
  fclose(*csv);
  printf("j'ai fermé le csv\n");
  fflush(stdout);
}
