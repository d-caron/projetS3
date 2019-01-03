/**
 * @file liste.h
 *
 * @brief Fichier de déclaration relative aux listes
 *
 * Déclare un nouveau type de structure permettant d'encapsuler les listes d'arcs
 * et un enssemble de fonctions permettant de manipuler ces dernières
 *
 * @author Vincent DUGAT, Dylan CARON
 *
 * @version 0.0.15
 *
 * @date 03/01/2019 
 */


#ifndef listeSTAT
#define listeSTAT


#include "elementliste.h"


#define DIMMAX 100 /// @def taille maximale de la liste statique
#define VIDE -1   /// @def constante  pour indiquer que la liste est vide (par convention)


/**
 * @struct liste
 *
 * @brief Liste d'arcs
 *
 * Liste d' Elementliste de dimension DIMMAX où 
 * Tete correspond à la première case de la liste et 
 * nbElt au nombre d'élément qu'elle contient
 */
typedef struct liste {
    Elementliste Tabliste[DIMMAX];
    int Tete;
    int nbElt;
} liste;

/**
 * @fn int nbEltList (liste lst)
 * 
 * @brief Nombre d'élément de la liste
 *
 * Calcule et renvoi le nombre d'élément de la liste "lst"
 *
 * @param lst Liste dont il faut calculer le nombre d'éléments
 *
 * @return Nombre d'éléments de la liste
 */
int nbEltList (liste lst);

/**
 * @fn void createList (liste *p)
 *
 * @brief Crée une liste statique
 *
 * Initialise la Tete et nbElt à 0 pour la liste "p"
 *
 * @param p Pointeur vers la liste à initialiser
 */
void createList (liste *p); 

/**
 * @fn void addFrontList (liste* p, Elementliste e)
 *
 * @brief Ajoute en début de liste
 *
 * Si la liste n'est pas pleine, ajoute un Elementliste "e"
 * au début de la liste, incrémente le "nbElt" de la liste
 * et met à jours la "Tete" de la liste
 *
 * @param p Pointeur vers la liste
 * @param e Elementliste à ajouter à la fin de la liste
 */
void addFrontList (liste* p, Elementliste e);

/**
 * @fn void addTailList (liste* p, Elementliste e)
 *
 * @brief Ajoute en fin de liste
 *
 * Si la liste n'est pas pleine, ajoute un Elementliste "e"
 * à la fin de la liste et incrémente le "nbElt" de la liste
 *
 * @param p Pointeur vers la liste
 * @param e Elementliste à ajouter à la fin de la liste
 */
void addTailList (liste* p, Elementliste e); 

/**
 * @fn void delTailList (liste* p)
 *
 * @brief Supprime en fin de liste
 *
 * décrémente le "nbElt" de la liste "p"
 * afin de supprimer le dernier Elementliste
 *
 * @param p Pointeur vers la liste
 */
void delTailList (liste* p);

/**
 * @fn void delFrontList (liste* p)
 *
 * @brief Supprime en début de liste
 *
 * Incrémente le "nbElt" et met à jour la "Tete" de la liste
 * afin de supprimer le premier Elementliste
 *
 * @param p Pointeur vers la liste
 */
void delFrontList (liste* p); 

/**
 * @fn void headList (liste p, Elementliste* e)
 *
 * @brief Elementliste de tête
 *
 * Stocke dans "e" l' Elementliste de Tete de la liste "p"
 *
 * @param p Liste
 * @param e Pointeur vers l' Elementliste qui contiendra l'élement de Tête
 */
void headList (liste p, Elementliste* e); 

/**
 * @fn void headList (liste p, Elementliste* e)
 *
 * @brief Elementliste de queue
 *
 * Stocke dans "e" l' Elementliste de Queue de la liste "p"
 *
 * @param p Liste
 * @param e Pointeur vers l' Elementliste qui contiendra l'élement de Tête
 */
void tailList (liste p, Elementliste* e); 

/**
 * @fn bool emptyList (liste p)
 *
 * @brief Liste vide
 *
 * Vérifie que la liste soit bien vide
 *
 * @param p liste à analyser
 *
 * @return true si vide, false sinon
 */
bool emptyList (liste p);

/**
 * @fn bool fullList (liste p)
 *
 * @brief Liste pleine
 *
 * Vérifie que la liste soit bien pleine
 *
 * @param p Liste à analyser
 *
 * @return true si pleine, false sinon
 */
bool fullList (liste p); 

/**
 * @fn void dumpList (liste p, FILE* fp)
 *
 * @brief Affiche la liste
 *
 * Affiche le contenu de la liste "p",
 * dans la destination d'affichage pointé par "fp"
 *
 * @param p Liste à afficher
 * @param fp Destination d'affichage
 */
void dumpList (liste p, FILE* fp); 

/**
 * @fn void swapEltList (Elementliste* a, Elementliste* b)
 *
 * @brief Echange d' Elementliste dans la liste
 *
 * Echange deux Elementsliste "a" et "b" d'emplacement
 *
 * @param a Pointeur vers l'élement a à échanger
 * @param b Pointeur vers l'élement b à échanger
 */
void swapEltList (Elementliste* a, Elementliste* b);

/**
 * @fn void bubbleSortList (liste* p)
 *
 * @brief Tri à bulle
 *
 * Tri les Elementsliste de la liste "p" en fonction de leurs poids.
 * Suit la méthode du tri à bulle
 *
 * @param p Pointeur vers la liste à trier
 */
void bubbleSortList (liste* p); 

/**
 * @fn void pickEltList (liste l, Elementliste* e, int index)
 *
 * @brief Prend un Elementliste dans la liste
 *
 * Cherche l' Elementliste d'indice "index" dans la liste "l"
 * et le stocke dans la structure pointé par "e"
 *
 * @param l Liste
 * @param e Pointeur vers un Elementliste pour stocker l'élement
 * @param index Indice de l'élement dans la liste
 */
void pickEltList (liste l, Elementliste* e, int index); 

/**
 * @fn bool belongEltList (liste p, Elementliste e)
 *
 * @brief Elementliste est dans liste
 *
 * Vérifie que l' Elementliste "e" soit bien présent dans la liste "p"
 *
 * @param p Liste
 * @param e Elementliste qu'on cherche
 *
 * @return true si présent, false sinon
 */
bool belongEltList (liste p, Elementliste e);

#endif
