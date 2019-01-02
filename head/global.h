/**
 * @file csv_to_duel.h
 *
 * @brief Déclare le type t_arc_p pour représenter une structure s_arc_p qui représente
 *  un arc
 *
 * @author Vincent DUGAT, Dylan CARON
 *
 * @version 1.0.0
 *
 * @date 02/01/2019 
 */
#ifndef GLOBAL_H
#define GLOBAL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @struct s_arc_p
 * 
 * @typedef s_arc_p t_arc_p
 *
 * @brief Permet de représenter un arc grace à son point d'origine, 
 *  sa destination et son poids
 */
typedef struct s_arc_p{ 
  int orig;
  int dest;
  int poids;
} t_arc_p;

#endif
