#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "fonctions.h"

#define NORM  "\x1B[0m"
#define JAUN  "\x1B[33m"


int main(int argc, char *argv[]) {
    int n = 1, pos = 0, nombre = 0, choix, i = 0, couleur = 0, j = 0, l;
    t_chaine *a_inserer = NULL;
    t_chaine *chaine = NULL;
    t_chaine *chaine_2 = NULL;
    t_chaine *tmp = NULL;
    t_chaine *tmp2 = NULL;
    do {

        printf("[1] Nouvelle Chaine\n[2] A partir d'un fichier\n");
        scanf("%d", &choix);
        fflush(stdin);
    } while (choix != 1 && choix != 2);
    if (choix == 1)
        chaine = creer_mot();
    else if (choix == 2)
        chaine = from_save();

    while (n) {
        afficher_liste(chaine);
        do {
            fflush(stdin);
            printf("[1] Concatener a la chaine\n"
                   "[2] Inserer dans la chaine\n"
                   "[3] Suprimmer dans la chaine\n"
                   "[4] Rechercher dans la chaine\n"
                   "[5] Remplacer une partie de la chaine par une liste\n"
                   "[6] Sauvegarder la chaine\n"
                   "[7] Quitter\n");

            scanf(" %d", &choix);
        }while(choix<1 || choix >7);
        fflush(stdin);
        switch (choix) {
            case 1:
                a_inserer = creer_mot();
                concatener(chaine, a_inserer);
                break;
            case 2:
                a_inserer = creer_mot();
                printf("Saisissez la pos : \n");
                scanf(" %d", &pos);
                insertion(a_inserer, chaine, pos);

                liberer(a_inserer);
                break;
            case 3:
                printf("Saisissez la pos : \n");
                scanf(" %d", &pos);
                printf("Saisissez le nombre d'element a supprimer : \n");
                scanf(" %d", &nombre);
                suppression(chaine, pos, nombre);
                break;
            case 4:
                a_inserer = creer_mot();
                l = taille(a_inserer);
                chaine_2 = recherche(a_inserer, chaine);
                tmp = chaine;
                tmp2 = chaine_2;
                while (tmp) {
                    if((tmp2 && tmp2->_data==i )|| couleur ){
                        printf("%s", JAUN);
                        if(tmp2 && tmp2->_data==i){
                            couleur = 1;
                            j = 0;
                        }
                        else if(couleur && j==l){
                            couleur = 0;
                            printf("%s", NORM);
                        }
                        j++;
                        if(tmp2 && couleur == 0){
                            tmp2 = tmp2->next;}

                    }
                    printf("%c", tmp->_data);
                    tmp = tmp->next;
                    i++;
                }
                printf("%s", NORM);
                printf("\n");
                liberer(chaine_2);
                j = 0;
                couleur = 0;
                i = 0;
                break;
            case 5:
                printf("Chaine a remplacer :\n");
                a_inserer = creer_mot();
                printf("Chaine de remplacement : \n");
                chaine_2 = creer_mot();
                if (!compare(a_inserer, chaine_2))
                    remplacer(a_inserer, chaine_2, chaine);
                else printf("Les deux chaines sont identiques\n");

                liberer(a_inserer);
                liberer(chaine_2);
                break;
            case 6:
                save_ch(chaine);
                break;
            case 7:
                n = 0;
                break;
            default:
                printf("Erreur\n");
                break;

        }
    }
    while (chaine) {
        tmp = chaine;
        chaine = chaine->next;
        free(tmp);
    }
    return 0;
}
