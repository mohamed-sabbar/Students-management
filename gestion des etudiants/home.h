#include<stdio.h>
#include<conio.h>
#include<time.h>
#include "réinscription.h"
#include "delibitarions.h"
#include "affiche les informations.h"
#include "supprime etudiant.h"
#include "ajouter un etudiant.h"
#include "recherche sur etudiant.h"
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);}
 int n;
void accueil(char nom[], char prenom[],char b[],char CNE[]) {
       time_t t;
    struct tm*now;
    time(&t);
    now = localtime(&t);
printf("\t\t\t\t\t\t\t\t\t| ____| |_ _   _  __| (_) __ _ _ __ | |_          \n");
    printf("\t\t\t\t\t\t\t\t\t|  _| | __| | | |/ _` | |/ _` | '_ \\| __|         \n");
    printf("\t\t\t\t\t\t\t\t\t| |___| |_| |_| | (_| | | (_| | | | | |_          \n");
    printf("\t\t\t\t\t\t\t\t\t|_____|\\__|\\__,_|\\__,_|_|\\__,_|_| |_|\\__|         \n");
    printf("\t\t\t\t\t\t\t\t\t      _       _    __                            \n");
    printf("\t\t\t\t\t\t\t\t\t _ __ | | __ _| |_ / _| ___  _ __ _ __ ___   ___  \n");
    printf("\t\t\t\t\t\t\t\t\t| '_ \\| |/ _` | __| |_ / _ \\| '__| '_ ` _ \\ / _ \\ \n");
    printf("\t\t\t\t\t\t\t\t\t| |_) | | (_| | |_|  _| (_) | |  | | | | | |  __/ \n");
    printf("\t\t\t\t\t\t\t\t\t| .__/|_|\\__,_|\\__|_|  \\___/|_|  |_| |_| |_|\\___| \n");
    gotoxy(90,10);
     printf("la derniere connexion : %02d:%02d:%02d\n", now->tm_hour, now->tm_min, now->tm_sec);
    gotoxy(80,16);
printf("************Bonjour  %s %s  ************\n", nom, prenom);
    gotoxy(80,17);
    printf("1 - Afficher votre informations \n");
        gotoxy(80,18);
    printf("2 - Faire reascription \n");
        gotoxy(80,19);
    printf("3-Quitter le platforme\n");
        gotoxy(80,20);
     printf("choissit un de ces choix:");
    scanf("%d",&n);
    switch (n){
case 2:
rinscription(nom,prenom,b,CNE);
break;
case 1:
deliEtu(nom, prenom,b,CNE);
break;
case 3:
return 0;
default:
    printf("ce choix n'existe pas ");

    }

}
void accueil_admin(){
 time_t t;
    struct tm*now;
    time(&t);
    now = localtime(&t);
    printf("\t\t\t\t\t\t\t\t\t           _           _                          \n");
    printf("\t\t\t\t\t\t\t\t\t  __ _  __| |_ __ ___ (_)_ __                     \n");
    printf("\t\t\t\t\t\t\t\t\t / _` |/ _` | '_ ` _ \\| | '_ \\                    \n");
    printf("\t\t\t\t\t\t\t\t\t| (_| | (_| | | | | | | | | | |                   \n");
    printf("\t\t\t\t\t\t\t\t\t \\__,_|\\__,_|_|_|_| |_|_|_| |_|                   \n");
    printf("\t\t\t\t\t\t\t\t\t _ __ | | __ _| |_ / _| ___  _ __ _ __ ___   ___  \n");
    printf("\t\t\t\t\t\t\t\t\t| '_ \\| |/ _` | __| |_ / _ \\| '__| '_ ` _ \\ / _ \\ \n");
    printf("\t\t\t\t\t\t\t\t\t| |_) | | (_| | |_|  _| (_) | |  | | | | | |  __/ \n");
    printf("\t\t\t\t\t\t\t\t\t| .__/|_|\\__,_|\\__|_|  \\___/|_|  |_| |_| |_|\\___| \n");
    printf("\t\t\t\t\t\t\t\t\t|_|                                              \n");

    gotoxy(90,10);
     printf("la derniere connexion : %02d:%02d:%02d\n", now->tm_hour, now->tm_min, now->tm_sec);
    gotoxy(80,16);
     printf("************Bonjour  Monsieur Adminstrateur ************\n");
     gotoxy(80,17);
    printf("1 - Afficher les infornations d'un etudiant\n");
    gotoxy(80,18);
    printf("2 - ajouter un etudiant\n");
    gotoxy(80,19);
    printf("3 - Afficher les deliberations \n");
    gotoxy(80,20);
    printf("4 - supprimer un etudiants \n");
gotoxy(80,21);
    printf("5 - Quitter\n");
    gotoxy(80,22);
    printf("choissit un de ces choix:");

    scanf("%d",&n);
    switch (n){
case 1:
reherche();
break;
case 2:
ajoute();
break;
case 3:
 deliberation(choixR());
 break;
case 4:
deleteStudent();
break;
case 5:

return 0;
break;
default:
    printf("ce choix n'existe pas ");

    }
}







