/**
 * @file lecture_csv.h
 *
 * @brief Déclare la fonction permettant de lire t de stocker le contenu d'un fichier csv
 *
 * @author Dylan CARON
 *
 * @version 1.0.0
 *
 * @date 02/01/2019 
 */

#ifndef _LECTURE_CSV_H
#define _LECTURE_CSV_H

#include <stdio.h>
#include <stdlib.h>
#include "../head/squelette.h"

#define MAX_CSV_WIDTH 1000

/**
 * @fn void read_csv (FILE** csv, t_mat_char_star_dyn* t_mat_char)
 *
 * @brief Lis le fichier csv et stocke son contenu 
 *  dans une structure t_mat_char_star_dyn
 *
 * @param csv Pointeur vers le fichier csv ouvert
 * @param t_mat_char Pointeur vers la structure t_mat_char_star_dyn qui va être rempli
 *
 * @todo Re-écrire la fonction qui est trop longue et faire des reallocs
 */
void read_csv (FILE** csv, t_mat_char_star_dyn* t_mat_char);

#endif
