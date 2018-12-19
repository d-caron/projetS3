#include <stdio.h>
#include <stdlib.h>

#define MAX_CSV_WIDTH 1000

/**
 * @brief ouvre un fichier csv et crash en cas de problème d'ouverture
 *
 * @param chemin
 *
 * @return le fichier csv ouvert
 */
void open_csv (char* chemin, FILE** csv);

/**
 * @brief Lis le fichier csv et renvoi son contenu dans une chaine de caractère
 *
 * @param csv
 *
 * @return 
 */
void read_csv (FILE** csv, char*** s_csv);

/**
 * @brief ferme le fichier csv ouvert
 *
 * @param csv
 */
void close_csv (FILE** csv);
