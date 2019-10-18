#ifndef PROJET1_FONCTIONS_H
#define PROJET1_FONCTIONS_H


#include "fonctions.c"

int compare(t_chaine *first, t_chaine *second);

int compter(t_chaine *maillon);

void suppression(t_chaine *chaine, int position, int nbr);

t_chaine *recherche(t_chaine *sous_chaine, t_chaine *chaine);

void remplacer(t_chaine *sous_chaine, t_chaine *remplacer, t_chaine *chaine);

void insertion(t_chaine *a_inserer, t_chaine *base, int position);

void concatener(t_chaine *first, t_chaine *deux);

t_chaine *copie(t_chaine *);

t_chaine *creer_mot();



void ajouter_lettre(t_chaine *maillon, t_chaine *debut, int position);

void afficher_liste(t_chaine *chaine);

void save_ch(t_chaine *chaine);

t_chaine *from_save();

void liberer(t_chaine*);

void Color(int couleurDuTexte,int couleurDeFond);

int taille(t_chaine *l);

#endif
