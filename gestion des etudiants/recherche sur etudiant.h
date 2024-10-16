#ifndef RECHERCHE_SUR_ETUDIANT_H_INCLUDED
#define RECHERCHE_SUR_ETUDIANT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void reherche() {
    system("cls");
    etudiant etu,etuR;
int temp = 0;
    char tmp[20], res[20],CNER[10];
    float  note;
    fflush(stdin);
printf("                                                                   donne le cne de etudiant pour reherche :");
gets(CNER);
    FILE *f = fopen("C:\\Users\\Mohamed Sabbar\\Desktop\\etudiants.bin", "rb");
    FILE *fr = fopen("C:\\Users\\Mohamed Sabbar\\Desktop\\les notes.txt", "rt");


    fread(&etu, sizeof(etu), 1, f);


    while (!feof(f)) {
        if (strcmp(etu.cne, CNER) == 0) {
            etuR = etu;
            temp++;
            break;
        }
        fread(&etu, sizeof(etu), 1, f);
    }
char annee[4],filliere[5];

    while (fscanf(fr, "%s %s %s %f", tmp,annee ,filliere,&note) == 4) {
        if (strcmp(CNER, tmp) == 0) {

            break;
        }
    }

    fclose(f);
    fclose(fr);

    if (temp == 0) {
            printf("\a");
        printf("                                                                   CNE incorrect !");
    }

else{
system("cls");
gotoxy(80,1);
    printf(" ---------- Vos informations : ---------- \n\n");
    gotoxy(80,2);
    printf("CNE      : %s\n", etuR.cne);
    gotoxy(80,3);
    printf("NOM      : %s\n", etuR.nom);
    gotoxy(80,4);
    printf("PRENOM   : %s\n", etuR.prenom);
    gotoxy(80,5);
    printf("date de naissance   : %s\n", etuR.dateNaissance);
    gotoxy(80,6);
    printf("ville de naissance     : %s\n", etuR.villeNaissance);
    gotoxy(80,7);
    printf("NOTE     : %.2f\n", note);
    gotoxy(80,8);
    printf(" --------------------------------------- \n");
sleep(10);
system("cls");
accueil_admin( );
}}



#endif // RECHERCHE_SUR_ETUDIANT_H_INCLUDED
