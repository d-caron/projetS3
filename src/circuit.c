#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "global.h" ///
#include "liste.h" ///

// pour la recherche de circuit
#define LIBRE -1
#define OUVERT 0
#define FERME 1

int trouveSuc(liste larcs,int sommet,int **tabVus){
  /// \brief renvoie le successeur suivant d'un sommet
  /// \param[in] larcs : liste des arcs du graphe.
  /// \param[in] sommet : le sommet
  /// \param[in] tabVus : tableau des déjà vus pour ne pas reprendre le même successeur.
  int orig,dest;
  t_arc_p arc;
  int nbElt = nbEltList(larcs);
  for(int j=0;j<nbElt;j++){
    // pour cet arc
    pickEltList(larcs,&arc,j);
    orig = arc.orig;
    dest = arc.dest;
    if (orig==sommet && tabVus[sommet][dest] !=1){
      return dest;
    }
  }
  return KO; /// définie dans global.h
}

bool dfs(liste larcs,int sommet,int * tabMark,int **tabVus){
/// \brief parcours en profondeur d'un graphe orienté pour chercher les circuits
/// \param[in] larcs : liste des arcs du graphe.
/// \param[in] sommet : le sommet de départ
/// \param[in,out] tabMark : tanleau de marquage pour ne pas tourner en rond.
/// \param[in] : tabVus : arcs déjà vus.
/// \return true=circuit, false sinon

  bool res;
  int dest = trouveSuc(larcs,sommet,tabVus); // premier succ

  while (dest!=KO){// pour tous les successeurs
    //printf("==>succ=%d\n",dest);//XXX
    if (tabMark[dest]==LIBRE){
      tabMark[dest] = OUVERT;
      res = dfs(larcs,dest,tabMark,tabVus); // on suit
      if (res)
        return true;
      //else 1==1;
    }
    else
      if(tabMark[dest]==OUVERT)
            return true;
    tabVus[sommet][dest] = 1;// pour ne pas reprendre le même arc
    dest = trouveSuc(larcs,sommet,tabVus);// succ suivant
  }
  tabMark[sommet] = FERME;
  return false;
}

bool circuits(liste larcs, int nbCandidats){// recherche de circuits pour tout le graphe
  /// ajouter un paramètre de dimension pour s'affranchir de la variable globale nbCandidats.
  /// utiliser pickElt
  /// \brief cherche si le graphe contient un circuit
  /// avec tab de marquage et tab de mémoire des arcs
  /// \param[in] la liste des arcs.
  /// \return : true, il y a un circuit, false sinon
  int orig;
  t_arc_p elt;
  bool res;
  int *tabMark = creer_tab_int(nbCandidats);// tableau de marquage
  int ** tabVus = creer_mat_int(nbCandidats,nbCandidats);
  int nbElt = nbEltList(larcs);
  for(int j=0;j<nbElt;j++){  // pour tous les arcs
    pickEltList(larcs,&elt,j);
    orig = elt.orig;
    init_tab_int(tabMark,nbCandidats,LIBRE);
    init_mat_int(tabVus,nbCandidats,nbCandidats,0);
    tabMark[orig]=OUVERT;
    res=dfs(larcs,orig,tabMark,tabVus);
    if (res)
      return true; // on sort
  }
  free(tabVus);
  free(tabMark);
  return false; // c'est la fin
}
