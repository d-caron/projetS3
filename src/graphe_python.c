/**
 * @file graphe_python.c
 *
 * @brief Fichier de définition relative à la création du fichier python affichant les graphes
 *
 * @author Dylan CARON
 *
 * @version 0.0.1
 *
 * @date 05/01/2019 
 */


#include "../head/graphe_python.h"


void creer_python (liste lst) {
  // Ouverture des fichiers
  FILE* modele = fopen("pollTests.py", "r");
  FILE* py = fopen("graphe.py", "w");
  char ch;

  // Lecture et écriture de la première partie du code python
  while ((ch = fgetc(modele)) != '#') {
    fprintf(py, "%c", ch);
  }

  // Lecture sans écriture du commentaire
  while ((ch = fgetc(modele)) != '\n') {}

  // Ecriture des instructions
  for (int i = 0; i < lst.nbElt; i ++) {
    printf("nbElt : %d, i = %d\n", lst.nbElt, i);
    fprintf(py, "G.add_edges_from([%d, %d], weight=%d)\n", 
        lst.Tabliste[(lst.Tete + i + DIMMAX) % DIMMAX].orig,
        lst.Tabliste[(lst.Tete + i + DIMMAX) % DIMMAX].dest,
        lst.Tabliste[(lst.Tete + i + DIMMAX) % DIMMAX].poids
    );
  }

  // Lecture et écriture de la suite du code python
  while (! feof(modele)) {
    fprintf(py, "%c", ch);
    ch = fgetc(modele);
  }

  // Fermeture des fichiers
  fclose(modele);
  fclose(py);
}
