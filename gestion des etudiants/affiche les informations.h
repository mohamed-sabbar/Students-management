#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void deliEtu(char nom[], char prenom[],char b[],char cneR[]) {
    etudiant etu, etuR;
    int temp = 0;
    char tmp[20], res[20];
    float noteR, note;

    FILE *f = fopen("C:\\Users\\Mohamed Sabbar\\Desktop\\etudiants.bin", "rb");
    FILE *fr = fopen("C:\\Users\\Mohamed Sabbar\\Desktop\\les notes.txt", "rt");


    // Lecture du fichier binaire des étudiants
    fread(&etu, sizeof(etu), 1, f);

    // Recherche de l'étudiant par CNE
    while (!feof(f)) {
        if (strcmp(etu.cne, cneR) == 0) {
            etuR = etu;
            temp++;
            break;
        }
        fread(&etu, sizeof(etu), 1, f);
    }
char annee[4],filliere[5];
    // Recherche de la note dans le fichier texte
    while (fscanf(fr, "%s %s %s %f", tmp,annee ,filliere,&note) == 4) {
        if (strcmp(cneR, tmp) == 0) {

            break;
        }
    }

    fclose(f);
    fclose(fr);

    if (temp == 0) {
            printf("/a");
        printf("                                                                   CNE incorrect !");
    }

    if((strcmp(annee,"CP1")==0)||(strcmp(annee,"CP2")==0)){
    if (note < 10)
        strcpy(res, "NON VALIDE !");
    else
        strcpy(res, "VALIDE !");
        strcpy(annee,"AP");}
        if((strcmp(annee,"CI3")==0)||(strcmp(annee,"CI2")==0)||(strcmp(annee,"CI1")==0)){
        if (note < 12)
        strcpy(res, "NON VALIDE !");
    else
        strcpy(res, "VALIDE !");
        }
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
    printf("NIVEAU   : %s\n", annee);
    gotoxy(80,6);
    printf("ANNEE    : %s\n", filliere);
    gotoxy(80,7);
    printf("NOTE     : %.2f\n", note);
    gotoxy(80,8);
    printf("RESULTAT : %s\n", res);
    gotoxy(80,9);
    printf(" --------------------------------------- \n");
sleep(10);
system("cls");
accueil( nom,prenom,b,cneR);
}

