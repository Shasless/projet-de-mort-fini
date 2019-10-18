#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structs.h"

void ajouter_lettre(t_chaine *maillon, t_chaine *debut, int pos) {
    if (pos != 0) {
        int i = 0, a = 1;
        t_chaine *temp = debut;
        while (temp->next != NULL && a) {
            i++;
            temp = temp->next;
            if (i == pos)
                a = 0;
        }
        maillon->next = temp->next;
        temp->next = maillon;
    } else {
        maillon->next = debut;
        debut = maillon;
    }
}

t_chaine *init_chaine(char _data) {
    t_chaine *maillon = NULL;
    maillon = malloc(sizeof(t_chaine));
    maillon->_data = _data;
    maillon->next = NULL;
    return maillon;
}

int compare(t_chaine *first, t_chaine *second) {
    t_chaine *tmp_1 = first, *tmp_2 = second;
    int equal = 0;
    while (tmp_1->_data == tmp_2->_data && !equal) {
        tmp_2 = tmp_2->next;
        tmp_1 = tmp_1->next;
        if (tmp_2 && tmp_1)
            equal = 1;
    }
    return equal;
}

t_chaine *creer_mot() {
    t_chaine *chaine = NULL;
    t_chaine *tmp = NULL;
    int taille;
    char usr_m[100];
    printf("Saisissez une chaine\n");
    fflush(stdin);
    scanf(" %[^\n]", usr_m);
    taille = strlen(usr_m);
    chaine = init_chaine(usr_m[0]);
    for (int i = 1; i < taille; i++) {
        tmp = init_chaine(usr_m[i]);
        ajouter_lettre(tmp, chaine, -1);
    }
    return chaine;
}


void afficher_liste(t_chaine *chaine) {
    if (chaine) {
        t_chaine *tmp = chaine;
        while (tmp) {
            printf("%c", tmp->_data);
            tmp = tmp->next;
        }
        printf("\n");
    }
}

t_chaine *copie(t_chaine *base) {
    t_chaine *tmp = base;
    t_chaine *copie = init_chaine(tmp->_data);
    tmp = tmp->next;
    t_chaine *tmp_m = NULL;
    while (tmp) {
        tmp_m = init_chaine(tmp->_data);
        ajouter_lettre(tmp_m, copie, -1);
        tmp = tmp->next;
    }
    return copie;
}

void concatener(t_chaine *first, t_chaine *deux) {
    t_chaine *tmp = first;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = deux;
}

void insertion(t_chaine *a_inserer, t_chaine *base, int pos) {
    t_chaine *tmp = base;
    t_chaine *save = NULL;
    a_inserer = copie(a_inserer);
    if (pos > 0) {
        for (int i = 0; i < pos - 1; i++) {
            if (tmp->next)
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
    } else if (pos == 0) {
        concatener(a_inserer, copie(base));
        *base = *a_inserer;

    } else {
        concatener(base, a_inserer);
    }
}

void suppression(t_chaine *chaine, int pos, int nbr) {
    t_chaine *tmp = chaine;
    t_chaine *save = NULL;
    t_chaine *save_2 = NULL;
    if (pos != 0) {
        for (int i = 0; i < pos - 2; i++) {
            if (tmp->next)
                tmp = tmp->next;

        }

        if (tmp->next) {
            save = tmp->next;

            for (int i = 0; i <= nbr; i++) {
                if (tmp->next)
                    tmp = tmp->next;
            }

            save_2 = tmp->next;
            save->next = save_2;
        }
    } else {
        int n = 0;
        while (n < nbr && tmp) {
            save = tmp;
            tmp = tmp->next;
            free(save);

        }
        if (tmp)
            *chaine = *tmp;
        else {
            chaine->_data = '\n';
            chaine->next = NULL;
        }

    }
}

t_chaine *recherche(t_chaine *sous_chaine, t_chaine *chaine) {
    int pos = 0, a = 1;
    t_chaine *tmp = chaine;
    t_chaine *tmp_2 = chaine;
    t_chaine *sous_tmp = sous_chaine;
    t_chaine *liste_occu = init_chaine('a');
    t_chaine *occu_tmp = NULL;
    while (tmp) {

        while (tmp_2 && tmp_2->_data == sous_tmp->_data && a) {

            if (sous_tmp->next) {
                sous_tmp = sous_tmp->next;
            } else {
                occu_tmp = init_chaine((char) pos);
                ajouter_lettre(occu_tmp, liste_occu, -1);
                a = 0;
            }
            if (tmp_2->next) {
                tmp_2 = tmp_2->next;
            }

        }
        a = 1;
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
    int taille = compter(sous_chaine);
    sous_chaine = copie(sous_chaine);
    remplacer = copie(remplacer);

    t_chaine *liste_occu = recherche(sous_chaine, chaine);
    while (liste_occu != NULL) {
        suppression(chaine, liste_occu->_data, taille);

        insertion(remplacer, chaine, liste_occu->_data);

        liste_occu = recherche(sous_chaine, chaine);

    }

}

t_chaine *from_save() {
    FILE *save = NULL;
    int taille = 0;
    save = fopen("save.txt", "r");
    if (!save) {
        printf("Read Error");
        return NULL;
    }
    fseek(save, 0, SEEK_END);
    taille = ftell(save);
    rewind(save);
    t_chaine *chaine = init_chaine((char) fgetc(save));
    t_chaine *maillon = NULL;
    for (int i = 1; i < taille; i++) {
        maillon = init_chaine((char) fgetc(save));
        ajouter_lettre(maillon, chaine, -1);
    }
    fclose(save);
    return chaine;

}

void save_ch(t_chaine *chaine) {
    FILE *save = NULL;
    t_chaine *tmp = chaine;
    save = fopen("save.txt", "w");
    while (tmp->next) {
        fputc(tmp->_data, save);
        tmp = tmp->next;
    }
    fputc(tmp->_data, save);
    fclose(save);
}

void liberer(t_chaine *chaine) {
    t_chaine *tmp = NULL;
    while (chaine) {
        tmp = chaine;
        chaine = chaine->next;
        free(tmp);
    }

}


int taille(t_chaine *l)
{
    int size = 0;
    if(l == NULL)
        return size;
    while(l)
    {
        size++;
        l = l->next;
    }
    return size;
}