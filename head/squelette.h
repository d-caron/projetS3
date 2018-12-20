#define STR_LEN 50
#define STR_MAT_ROW 50
#define STR_MAT_COL 10
// mettre des choses avant
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

/// \struct pour encapsuler des tableaux dynamiques d'entiers avec la dimension.
typedef struct s_tab_dyn{
  int * tab;
  int dim;
} t_tab_int_dyn;

typedef struct s_mat_dyn{
  int ** tab;
  int nbRows;
  int nbCol;
} t_mat_int_dyn;

/// \struct idem avec des chaînes de cractères
typedef struct s_mat_char_dyn{
  char *** tab;
  int nbRows;
  int nbCol;
  int offset; // donne le nombre de colonnes avant celles des candidats
} t_mat_char_star_dyn;

/// \struct arc pour les graphes
typedef struct s_arc_p{ /// arc pondéré
  int orig;
  int dest;
  int poids;
} t_arc_p;

/* X */ int * creer_tab_int(int dim); // juste un malloc de dim cases
/* X */ int ** creer_mat_int(int nbRows,int nbCol); // malob 2D
/* X */ void affiche_tab_int(int *tab,int dim, FILE *logfp);

/* X */ void creer_t_mat_int_dyn(t_mat_int_dyn *stTab,int nbRows,int nbCol); // utilise la struct
/* X */ void creer_t_tab_int_dyn(t_tab_int_dyn *stTab,int dim); // idem
/* X */ void creer_t_mat_char_dyn(t_mat_char_star_dyn * s_tabmots);
/* X */ void affiche_t_tab_int_dyn(t_tab_int_dyn t_tab, FILE *logfp);
void affiche_t_mat_char_star_dyn(t_mat_char_star_dyn t_tabmots, FILE *logfp);
/* X */ void affiche_t_mat_int_dyn(t_mat_int_dyn t_tab, FILE *logfp);
void affiche_mat_int(int **duels_mat,int nbRows,int nbCol,FILE *logfp);

/* X */ void init_tab_int(int *tab,int dim,int valeur);// initialise avec une valeur
/* X */ void init_mat_int(int **mat,int nbRows,int nbCol,int valeur); // idem

// mettre des choses après
