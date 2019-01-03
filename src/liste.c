/**
 * @file liste.c
 *
 * @brief Fichier de définitions relative aux listes
 *
 * Défini les fonctions de liste.h
 *
 * @author Dylan CARON
 *
 * @version 0.0.15
 *
 * @date 03/01/2019 
 */


#include "../head/liste.h"


int nbEltList (liste lst) {
  return lst.Tete;
}


void createList (liste *p) {
  p->nbElt = 0;
  p->Tete = 0;
}


void addFrontList (liste* p, Elementliste e) {
  if (! fullList(*p)) {
    copie_element(p->Tabliste + ((p->Tete - 1) % DIMMAX), e);
    p->Tete = (p->Tete - 1) % DIMMAX;
    p->nbElt ++;
  }
}


void addTailList (liste* p, Elementliste e) {
  if (! fullList(*p)) {
    copie_element(p->Tabliste + ((p->Tete + p->nbElt) % DIMMAX), e);
    p->nbElt ++;
  }
}


void delTailList (liste* p) {
  if (! emptyList(*p)) {
    p->nbElt --;
  }
}


void delFrontList (liste* p) {
  if (! emptyList(*p)) {
    p->Tete = (p->Tete + 1) % DIMMAX;
    p->nbElt --;
  }
}


void headList (liste p, Elementliste* e) {
  if (! emptyList(p)) {
    copie_element(e, p.Tabliste[p.Tete]);
  }
}


void tailList (liste p, Elementliste* e) {
  if (! emptyList(p)) {
    copie_element(e, p.Tabliste[(p.Tete + p.nbElt) % DIMMAX]);
  }
}


bool emptyList (liste p) {
  if (p.nbElt == 0) {
    return true;
  }

  return false;
}


bool fullList (liste p) {
  if(p.nbElt == DIMMAX) {
    return true;
  }

  return false;
}


void dumpList (liste p, FILE* fp) {
  for (int i = 0; i < p.nbElt - 1; i ++) {
    afficher_element(p.Tabliste[(p.Tete + i) % DIMMAX], fp);
    fprintf(fp, ",\n");
  }

  afficher_element(p.Tabliste[(p.Tete + p.nbElt - 1) % DIMMAX], fp);
  fprintf(fp, "\n");
}


void swapEltList (Elementliste* a, Elementliste* b) {
  Elementliste buff;
  
  copie_element(&buff, *a);
  copie_element(a, *b);
  copie_element(b, buff);
}


void bubbleSortList (liste* p) {
  bool sorted = true;

  for (int i = nbEltList(*p) - 1; i > 0; i --) {
    sorted = true;
    for (int j = 0; j < i; j ++) {
      if (p->Tabliste[(p->Tete + i) % DIMMAX].poids  < p->Tabliste[(p->Tete + i + 1) % DIMMAX].poids) {
        swapEltList(p->Tabliste + ((p->Tete + i) % DIMMAX), p->Tabliste + ((p->Tete + i + 1) % DIMMAX));
        sorted = false;
      }
    }

    if (sorted) return;
  }
}


void pickEltList (liste l, Elementliste* e, int index) {
  if (index < l.nbElt) {
    copie_element(e, l.Tabliste[(l.Tete + index) % DIMMAX]);
  }
}


bool belongEltList (liste p, Elementliste e) {
  for (int i = 0; i < p.nbElt; i ++) {
    if (cmp_elements(e, p.Tabliste[(p.Tete + i) % DIMMAX])) {
      return true;
    }
  }

  return false;
}
