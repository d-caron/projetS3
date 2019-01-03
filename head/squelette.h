/**
 * @file squelette.h
 *
 * @brief Fichier de déclarations relatives aux SD partagées
 *
 * Déclare un enssemble de types (tableaux/matrices de caractère/entiers) 
 * ainsi que les fonctions permettant de les manipuler
 *
 * @author Vincent DUGAT, Dylan CARON
 *
 * @version 1.0.0
 *
 * @date 02/01/2019 
 */


#ifndef _SQUELETTE_H
#define _SQUELETTE_H


#include <stdio.h>


#define STR_LEN 100
#define STR_MAT_COL 100
#define STR_MAT_ROW 500
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))


/**
 * @struct t_tab_int_dyn
 *
 * @brief Tableau d'entier dynamique
 *
 * Pour encapsuler des tableaux dynamiques d'entiers 
 * avec la dimension
 */
typedef struct s_tab_dyn {
  int * tab;
  int dim;
} t_tab_int_dyn;

/**
 * @struct t_mat_int_dyn
 *
 * @brief Matrice d'entier dynamque
 *
 * Pour encapsuler des matrice 2D dynamiques d'entiers
 * avec son nombre de ligne et de colonne ("nbRows" et "nbCol")
 */
typedef struct s_mat_dyn {
  int ** tab;
  int nbRows;
  int nbCol;
} t_mat_int_dyn;

/**
 * @struct t_mat_char_star_dyn
 *
 * @brief Matrice de chaine de caractères
 *
 * Pour encapsuler des matrice 2D dynamiques de chaines de caractères
 * avec son nombre de ligne et de colonne ("nbRows" et "nbCol")
 * offset sert à stocker le nombre de colonnes avant celles des candidats
 */
typedef struct s_mat_char_dyn {
  char *** tab;
  int nbRows;
  int nbCol;
  int offset; 
} t_mat_char_star_dyn;

/**
 * @struct t_duel_mat
 *
 * @brief Matrice de duel
 *
 * Pour encapsuler des matrice de duels 
 * en conservant l'entête et les données
 */
typedef struct s_duel_mat {
  char** entete;
  t_mat_int_dyn mat;
} t_duel_mat;


/**
 * @fn int* creer_tab_int (int dim)
 *
 * @brief Crée un tableau d'entier
 *
 * Alloue l'espace nécessaire pour un tableau de "dim" entiers
 *
 * @param dim Dimension du tableau d'entier
 *
 * @return la mémoire allouée
 */
int* creer_tab_int (int dim); 

/**
 * @fn int** creer_mat_int (int nbRows,int nbCol)
 *
 * @brief Crée matrice d'entier
 *
 * Alloue l'espace nécessaire pour une matrice de "nbRows" * "nbCol" entiers
 *
 * @param nbRows Nombre de ligne de la matrice d'entier
 * @param nbCol Nombre de colonne de la matrice d'entier
 *
 * @return la mémoire allouée
 */
int** creer_mat_int (int nbRows,int nbCol);

/**
 * @fn void affiche_tab_int (int *tab,int dim, FILE *logfp)
 *
 * @brief Affiche un tableau d'entier
 *
 * Permet d'afficher un tableau d'entier.
 * Ecrit dans la destination ciblé par logfp
 *
 * @param tab Tableau d'entier à afficher
 * @param dim Dimension du tableau d'entier à afficher
 * @param logfp Destination d'affichage
 */
void affiche_tab_int (int* tab,int dim, FILE* logfp);

/**
 * @fn void creer_t_mat_int_dyn (t_mat_int_dyn *stTab,int nbRows,int nbCol)
 *
 * @brief Crée une structure t_mat_int_dyn
 *
 * Alloue la mémoire et initialise les valeurs d'une structure t_mat_int_dyn
 *
 * @param stTab Pointeur vers la structure à créer
 * @param nbRows Nombre de lignes de la matrice d'entier
 * @param nbCol Nombre de colennes de la matrice d'entier
 */
void creer_t_mat_int_dyn (t_mat_int_dyn* stTab,int nbRows,int nbCol);

/**
 * @fn void creer_t_tab_int_dyn (t_tab_int_dyn* stTab,int dim)
 *
 * @brief Crée une structure t_tab_int_dyn
 *
 * Alloue la mémoire et initialise les valeurs d'une structure t_tab_int_dyn
 *
 * @param stTab Pointeur vers la structure à créer
 * @param dim Dimension du tableau d'entier
 */
void creer_t_tab_int_dyn (t_tab_int_dyn* stTab,int dim);

/**
 * @fn void creer_t_mat_char_dyn (t_mat_char_star_dyn * s_tabmots)
 *
 * @brief Crée une structure t_mat_char_star_dyn
 *
 * Alloue la mémoire et initialise les valeurs d'une structure t_mat_char_star_dyn
 *
 * @param s_tabmots Pointeur vers la structure à créer
 */
void creer_t_mat_char_dyn (t_mat_char_star_dyn* s_tabmots);

/**
 * @fn void affiche_t_tab_int_dyn (t_tab_int_dyn t_tab, FILE *logfp)
 *
 * @brief Affiche une structure t_tab_int_dyn
 *
 * Permet d'afficher une structure t_tab_int_dyn
 * Ecrit dans la destination ciblé par logfp
 *
 * @param t_tab Structure à afficher
 * @param logfp Destination d'affichage
 */
void affiche_t_tab_int_dyn (t_tab_int_dyn t_tab, FILE *logfp);

/**
 * @fn void affiche_t_mat_char_star_dyn (t_mat_char_star_dyn t_tabmots, FILE *logfp)
 *
 * @brief Affiche une structure t_mat_char_star_dyn
 *
 * Permet d'afficher une structure t_mat_char_star_dyn
 * Ecrit dans la destination ciblé par logfp
 *
 * @param t_tabmots Structure à afficher
 * @param logfp Destination d'affichage
 */
void affiche_t_mat_char_star_dyn (t_mat_char_star_dyn t_tabmots, FILE *logfp);

/**
 * @fn void affiche_t_mat_int_dyn (t_mat_int_dyn t_tab, FILE *logfp)
 *
 * @brief Affiche une structure t_mat_int_dyn
 *
 * Permet d'afficher une structure t_mat_int_dyn
 * Ecrit dans la destination ciblé par logfp
 *
 * @param t_tab Structure à afficher
 * @param logfp Destination d'affichage
 */
void affiche_t_mat_int_dyn (t_mat_int_dyn t_tab, FILE *logfp);

/**
 * @fn void affiche_mat_int (int **duels_mat,int nbRows,int nbCol,FILE *logfp)
 *
 * @brief Affiche une matrice d'entier
 *
 * Permet d'afficher une matrice d'entier 
 * Ecrit dans la destination ciblé par logfp
 *
 * @param duels_mat Matrice d'entier à afficher
 * @param nbRows Nombre de ligne de la matrice d'entier
 * @param nbCol Nombre de colonne de la matrice d'entier
 * @param logfp Destination d'affichage
 */
void affiche_mat_int (int** duels_mat, int nbRows, int nbCol, FILE *logfp);

/**
 * @fn void init_tab_int (int* tab, int dim, int valeur)
 *
 * @brief Initialise un tableau d'entier
 *
 * Initialise un tableau d'entier avec la valeur passé en paramètre
 *
 * @param tab Tableau d'entier à initialiser
 * @param dim Dimension du tableau d'entier
 * @param valeur Valeur pour l'initialisation
 */
void init_tab_int (int* tab, int dim, int valeur);

/**
 * @fn void init_mat_int (int** mat, int nbRows, int nbCol,int valeur)
 *
 * @brief Initialise une matrice d'entier
 *
 * Initialise une matrice d'entier avec la valeur passé en paramètre
 *
 * @param mat Matrice d'entier à initialiser
 * @param nbRows Nombre de ligne de la matrice
 * @param nbCol Nombre de colonne de la matrice
 * @param valeur Valeur pour l'initialisation
 */
void init_mat_int (int** mat, int nbRows, int nbCol,int valeur);

/**
 * @fn void creer_t_duel_mat (t_duel_mat* duel, int dim)
 *
 * @brief Crée une structure t_duel_mat
 *
 * Alloue l'espace pour une structure t_duel_mat et 
 * initialise la "dim" de la matrice
 *
 * @param duel Structure à créer
 * @param dim Dimension de la matrice de duel
 */
void creer_t_duel_mat (t_duel_mat* duel, int dim);

/**
 * @fn void affiche_t_duel_mat (t_duel_mat duel, FILE* logfp)
 *
 * @brief Affiche une structure t_duel_mat
 *
 * Permet d'afficher une structure t_duel_mat
 * Ecrit dans la destination ciblé par logfp
 *
 * @param duel Structure à afficher
 * @param logfp Destination d'affichage
 */
void affiche_t_duel_mat (t_duel_mat duel, FILE* logfp);

#endif
