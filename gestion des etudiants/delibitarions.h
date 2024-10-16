#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct Choix {
    char nR[10], fr[10],specia[10];
} choix;

choix choixR() {
    choix ch1;
    do {system("cls");
        printf("                                                                   SVP respectez l'écriture !!\n");
        printf("                                                                   Saisir le niveau ( AP/ CI ) : ");
        fflush(stdin);
        gets(ch1.nR);
    } while (strcmp(ch1.nR, "AP") != 0 && strcmp(ch1.nR, "CI") != 0 );
    system("cls");
    if(strcmp(ch1.nR,"AP")==0){
    do {

        printf("                                                                   Saisir  ( CP1 / CP2 ) : ");
        fflush(stdin);
        gets(ch1.fr);
    } while (strcmp(ch1.fr, "CP1") != 0 && strcmp(ch1.fr, "CP2") != 0);
strcpy(ch1.specia,ch1.fr);
    return ch1;}
    if(strcmp(ch1.nR,"CI")==0){
        do{
            printf("                                                                   \tSaisir la niveau (CI1 / CI2/ CI3) :");
            fflush(stdin);
            gets(ch1.fr);
        }while((strcmp(ch1.fr,"CI1") != 0) && (strcmp(ch1.fr, "CI2") != 0) && (strcmp(ch1.fr, "CI3") != 0));
        do{
            printf("                                                                   \tSaisir le niveau (GI / ID / GEER/ G2E /GM / TDIA / GC) :");
            fflush(stdin);
            gets(ch1.specia);
        }while((strcmp(ch1.specia, "GI") != 0) && (strcmp(ch1.specia, "ID") != 0) && (strcmp(ch1.specia, "TDIA") != 0 )&& (strcmp(ch1.specia, "GC") != 0)&& (strcmp(ch1.specia, "GM") != 0) && (strcmp(ch1.specia, "GEER") != 0)&& (strcmp(ch1.specia, "G2e") != 0));
   return ch1; }
}

void deliberation(choix ch1) {
    system("cls");
    char tmp[15], n[10], f[10];
    float note, som = 0.0;
    int nbr = 0, nbrV = 0, nbrNV = 0;
    etudiant etu;
    FILE *fe = fopen("C:\\Users\\Mohamed Sabbar\\Desktop\\etudiants.bin", "rb");
    FILE *fn = fopen("C:\\Users\\Mohamed Sabbar\\Desktop\\les notes.txt", "rt");
    if (fe == NULL || fn == NULL) {
        printf("Erreur lors de l'ouverture des fichiers !");
        exit(1);
    }
   printf("                                                                   \t************************************Deliberation %s :%s************************************ \n", ch1.nR, ch1.fr);
    printf("                                                                   \t%-15s %-15s %-15s %-15s %-15s\n", "CNE", "Nom", "Prenom", "Moyenne", "Validation");

    while (fread(&etu, sizeof(etudiant), 1, fe) == 1) {
        fseek(fn, 0, SEEK_SET);
        while (fscanf(fn, "%s %s %s %f", tmp, n, f, &note) == 4) {
            if (strcmp(etu.cne, tmp) == 0 && strcmp(f, ch1.specia) == 0 && strcmp(n, ch1.fr) == 0) {
                nbr++;
                som += note;

                if ((strcmp(ch1.fr, "CI1") == 0 || strcmp(ch1.fr, "CI2") == 0 || strcmp(ch1.fr, "CI3") == 0) && note < 12) {
                    printf("                                                                   \t%-15s %-15s %-15s %-15.2f %-15s\n", tmp, etu.nom, etu.prenom, note, "NON VALIDE");
                    nbrNV++;
                } else if ((strcmp(ch1.fr, "CP1") == 0 || strcmp(ch1.fr, "CP2") == 0) && note < 10) {
                    printf("                                                                   \t%-15s %-15s %-15s %-15.2f %-15s\n", tmp, etu.nom, etu.prenom, note, "NON VALIDE");
                    nbrNV++;
                } else {
                    printf("                                                                   \t%-15s %-15s %-15s %-15.2f %-15s\n", tmp, etu.nom, etu.prenom, note, "VALIDE");
                    nbrV++;
                }
            }
        }
    }
    printf("                                                                   *******************************************************************************************");
    printf("                                                                   %60s %.2f\n", "La moyenne de la filiere : ", som / (float)nbr);
    printf("                                                                   %60s %d\n", "Le nombre des etudiants de la filiere : ", nbr);
    printf("                                                                   %60s %d\n", "Le nombre des etudiants valides : ", nbrV);
    printf("                                                                   %60s %d\n", "Le nombre des etudiants ajournes : ", nbrNV);

    fclose(fe);
    fclose(fn);
    sleep(10);
    system("cls");
accueil_admin( );
}


