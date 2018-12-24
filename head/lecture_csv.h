#ifndef _LECTURE_CSV_H
#define _LECTURE_CSV_H

#include <stdio.h>
#include <stdlib.h>
#include "../head/squelette.h"

#define MAX_CSV_WIDTH 1000

/**
 * @brief ouvre un fichier csv et le stocke.
 * Crash en cas de problème d'ouverture
 *
 * @param chemin
 * @param csv
 *
 * @return
 */
void open_csv (char* chemin, FILE** csv);

/**
 * @brief Lis le fichier csv et 
 * stocke son contenu dans une structure t_mat_char_star_dyn
 *
 * @param csv
 * @param t_mat_char
 *
 * @return 
 */
void read_csv (FILE** csv, t_mat_char_star_dyn* t_mat_char);


/**
 * @brief Lis le fichier csv (matrice de duel) et 
 * stocke son contenu dans une structure t_duel_mat
 *
 * @param csv
 * @param t_duel
 */
void read_duel (FILE** csv, t_duel_mat* t_duel);

/**
 * @brief ferme le fichier csv ouvert
 *
 * @param csv
 */
void close_csv (FILE** csv);

#endif
