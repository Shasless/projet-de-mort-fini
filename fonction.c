#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"

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


t_chaine *cree_mot() {
	t_chaine *chaine = NULL;
	t_chaine *tmp = NULL;
	int taille;
	char usr_m[100];
	printf("Saisissez une chaine\n");
	scanf(" %[^\n]", usr_m);
	taille = strlen(usr_m);
	chaine = init_chaine(usr_m[0]);
	for (int i = 1; i < taille; i++) {
		tmp = init_chaine(usr_m[i]);
		ajouter_lettre(tmp, chaine, -1);
	}
	return chaine;
}

t_chaine *init_chaine(char _data) {
	t_chaine *maillon = NULL;
	maillon = malloc(sizeof(t_chaine));
	maillon->_data = _data;
	maillon->next = NULL;
	return maillon;
}

void ajouter_lettre(t_chaine *maillon, t_chaine *debut, int position) {
	if (position != 0) {
		int i = 0;
		t_chaine *temp = debut;
		while (temp->next != NULL) {
			i++;
			if (i == position)
				break;

			temp = temp->next;

		}
		maillon->next = temp->next;
		temp->next = maillon;
	} else {
		maillon->next = debut;
		debut = maillon;
	}
}

void afficher_liste(t_chaine *chaine) {
	t_chaine *tmp = chaine;
	while (tmp) {
		printf("%c", tmp->_data);
		tmp = tmp->next;
	}
	printf("\n");
}

t_chaine *copie(t_chaine *base) {
	t_chaine *tmp = base;
	t_chaine *copie = init_chaine(tmp->_data);
	tmp = tmp->next;
	t_chaine *tmp_c = copie->next;
	t_chaine *tmp_m = NULL;
	while (tmp) {
		tmp_m = init_chaine(tmp->_data);
		ajouter_lettre(tmp_m, copie, -1);
		tmp = tmp->next;
	}
	return copie;
}

t_chaine *concatener(t_chaine *first, t_chaine *deux) {
	t_chaine *tmp;
	t_chaine *tmp_1 = first;
	t_chaine *tmp_2 = deux;
	t_chaine *concatenat = init_chaine(tmp_1->_data);
	tmp_1 = tmp_1->next;
	while (tmp_1) {
		tmp = init_chaine(tmp_1->_data);
		ajouter_lettre(tmp, concatenat, -1);
		tmp_1 = tmp_1->next;
	}
	while (tmp_2) {
		tmp = init_chaine(tmp_2->_data);
		ajouter_lettre(tmp, concatenat, -1);
		tmp_2 = tmp_2->next;
	}
	return (concatenat);
}

void insertion(t_chaine *a_inserer, t_chaine *base, int position) {
	t_chaine *tmp = base;
	t_chaine *save = NULL;
	if (position != 0) {
		for (int i = 0; i < position - 1; i++) {
			if(tmp->next)
				tmp = tmp->next;

		}
		save = tmp->next;
		tmp->next = a_inserer;
		while (tmp->next) {
			if (tmp->next)
				tmp = tmp->next;
		}
		if (tmp)
			tmp->next = save;
	} else {
		tmp->next= concatener(base,a_inserer)->next;
	}
}

void suppression(t_chaine *chaine, int position, int nbr) {
	t_chaine *tmp = chaine;
	t_chaine *save = NULL;
	t_chaine *save_2 = NULL;

	for (int i = 0; i < position - 2; i++) {
		if(tmp->next)
			tmp = tmp->next;

	}
	if(tmp->next){
		save = tmp->next;

		for (int i = 0; i <= nbr; i++) {
			if (tmp->next)
				tmp = tmp->next;
		}

		save_2 = tmp->next;
		save->next = save_2;
	}}

t_chaine *recherche(t_chaine *sous_chaine, t_chaine *chaine) {
	int pos = 0;
	t_chaine *tmp = chaine;
	t_chaine *tmp_2 = chaine;
	t_chaine *sous_tmp = sous_chaine;
	t_chaine *liste_occu = init_chaine('a');
	t_chaine *occu_tmp = NULL;
	while (tmp) {

		while (tmp_2 && tmp_2->_data == sous_tmp->_data ) {

			if(sous_tmp->next){
				sous_tmp = sous_tmp->next;}
			else{
				occu_tmp = init_chaine(pos+49);
				ajouter_lettre(occu_tmp, liste_occu, -1);
				break;
			}
			if( tmp_2->next ){
				tmp_2 = tmp_2->next;}

		}
		sous_tmp = sous_chaine;
		tmp = tmp->next;
		tmp_2 = tmp;
		pos++;
	}

	return liste_occu->next;
}

int compter(t_chaine *maillon) {
	int i = 1;
	if (maillon == NULL) {
		return 0;
	} else {
		t_chaine *temp = maillon;
		while (temp->next != NULL) {
			temp = temp->next;
			i++;
		}

	}
	return i;
}

void remplacer(t_chaine *sous_chaine, t_chaine *remplacer, t_chaine *chaine) {
	int pos = 0;
	int taille = compter(sous_chaine);
	t_chaine *tmp = chaine;
	t_chaine *tmp_2 = chaine;
	t_chaine *sous_tmp = sous_chaine;
	t_chaine *liste_occu = recherche(sous_chaine, remplacer);

	if(liste_occu==NULL){
		while (tmp) {
			while (tmp_2 && tmp_2->_data == sous_tmp->_data ) {
				if(sous_tmp->next){
					sous_tmp = sous_tmp->next;}
				else{
					suppression(chaine, pos, taille);
					insertion(remplacer, chaine, pos);
					break;
				}
				if( tmp_2->next ){
					tmp_2 = tmp_2->next;}

			}
			sous_tmp = sous_chaine;
			tmp = tmp->next;
			tmp_2 = tmp;
			pos++;

		}
	}}

t_chaine *from_save(){
	FILE* save = NULL;
	int taille = 0;
	save = fopen("save.txt", "r");
	if(!save){
		printf("Read Error");
		return NULL;
	}
	fseek(save, 0, SEEK_END);
	taille = ftell(save);
	rewind(save);
	t_chaine* chaine = init_chaine(fgetc(save));
	t_chaine* maillon = NULL;
	for(int i = 1; i<taille; i++){
		maillon = init_chaine(fgetc(save));
		ajouter_lettre(maillon, chaine, -1);
	}
	fclose(save);
	return chaine;

}
void save_ch(t_chaine* chaine){
	FILE* save = NULL;
	t_chaine* tmp = chaine;
	save = fopen("save.txt", "w");
	while(tmp->next){
		fputc(tmp->_data, save);
		tmp=tmp->next;
	}
	fputc(tmp->_data, save);
	fclose(save);
}