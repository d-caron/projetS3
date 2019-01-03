/**
 * @file elementliste.d
 *
 * @brief Fichier de définitions relatives à l' Elementliste
 *
 * @author Vincent DUGAT, Dylan CARON
 *
 * @version 1.0.0
 *
 * @date 02/01/2019 
 */


#include "../head/elementliste.h"


void saisie_element (Elementliste* e) {
  printf("Saisissez l'arc : \n");
  scanf("%d", &(e->orig));
  scanf("%d", &(e->dest));
  scanf("%d", &(e->poids));
}


void copie_element (Elementliste* cible, Elementliste source) {
  cible->orig = source.orig;
  cible->dest = source.dest;
  cible->poids = source.poids;
}


void afficher_element (Elementliste e, FILE* fp) {
  fprintf (fp, "%d --- %d --> %d",
      e.orig,
      e.dest,
      e.poids
  );
}


bool cmp_elements (Elementliste e1, Elementliste e2) {
  if (e1.orig == e2.orig &&
      e1.dest == e2.dest &&
      e1.poids == e2.poids
  ) {
    return true;
  }

  return false;
}
