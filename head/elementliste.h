/* liste statique */
/* Vincent Dugat 2018 */

/* Pour éviter les inclusions multiples */

#ifndef ELEMENTLISTE_H
#define ELEMENTLISTE_H

#include "global.h" // définit le type t_arc_p

typedef t_arc_p Elementliste;
void saisie_element(Elementliste *e);
void copie_element(Elementliste *cible, Elementliste source);
void afficher_element(Elementliste e,FILE *fp);
bool cmp_elements(Elementliste e1,Elementliste e2);

#endif
