/// \file global.h
/// \author Vincent Dugat
/// \date august 2018
#ifndef GLOBAL_H
#define GLOBAL_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_arc_p{ /// arc pondéré
  int orig;
  int dest;
  int poids;
} t_arc_p;

#endif
