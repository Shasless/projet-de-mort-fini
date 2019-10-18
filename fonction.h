#ifndef fonction
#define fonction

typedef struct t_chaine {
    char _data;
    struct t_chaine *next;
} t_chaine;

int compter(t_chaine *maillon);

void suppression(t_chaine *chaine, int position, int nbr);

t_chaine *recherche(t_chaine *sous_chaine, t_chaine *chaine);

void remplacer(t_chaine *sous_chaine, t_chaine *remplacer, t_chaine *chaine);

void insertion(t_chaine *a_inserer, t_chaine *base, int position);

t_chaine *concatener(t_chaine *first, t_chaine *deux);

t_chaine *copie(t_chaine *);

t_chaine *cree_mot();

t_chaine *init_chaine(char _data);

void ajouter_lettre(t_chaine *maillon, t_chaine *debut, int position);

void afficher_liste(t_chaine *chaine);

void save_ch(t_chaine* chaine);

t_chaine *from_save();

#endif