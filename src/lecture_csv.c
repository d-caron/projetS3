#include "../head/lecture_csv.h"

/**
 * @brief ouvre un fichier csv et crash en cas de problème d'ouverture
 *
 * @param chemin
 */
void open_csv (char* chemin, FILE** csv) {
  *csv = fopen(chemin, "r");

  if (*csv == NULL) {
    printf("Impossible d'ouvrir le fichier %s", chemin);
    exit(EXIT_FAILURE);
  }
}

/**
 * @brief Lis le fichier csv et renvoi son contenu dans une chaine de caractère
 *
 * @param csv
 */
void read_csv (FILE** csv, char** s_csv) {  
  char buff[10];
  //printf("je vais lire le csv");
  //fflush(stdout);
  if (*csv == NULL) {
    printf("Impossible de lire le fichier");
    exit(EXIT_FAILURE);
  }

  while (fgets (buff, 10, *csv) != NULL) {
    printf("%s", buff);
  }
  //printf("j'ai lu le fichier csv");
  //fflush(stdout);
}


/**
 * @brief ferme le fichier csv ouvert
 *
 * @param csv
 */
void close_csv (FILE** csv) {
  fclose(*csv);
}
