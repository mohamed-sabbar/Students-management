#ifndef RéINSCRIPTION_H_INCLUDED
#define RéINSCRIPTION_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#include <unistd.h>
typedef struct etudiant{
 char nom[50];
    char prenom[50];
    char cne[12];
    char cin[12];
    char dateNaissance[12];
    char villeNaissance[50];
}etudiant;
typedef struct etud {
    int CNE;
    char filliere[7][10];
    float moyenne;
} e;

void triAP2() {
    int max, i = 0;
    e etud[200], temp, etu;
    FILE *f = fopen("C:\\Users\\Mohamed Sabbar\\Desktop\\choix.txt", "rt");
    FILE *fc = fopen("C:\\Users\\Mohamed Sabbar\\Desktop\\choixclasse.txt", "wt");

    if (f == NULL || fc == NULL) {
        printf("Erreur d'ouverture !\n");
        exit(1);
    }

    while (fscanf(f, "%d %s %s %s %s %s %s %s %f",
                  &etu.CNE, etu.filliere[0], etu.filliere[1], etu.filliere[2],
                  etu.filliere[3], etu.filliere[4], etu.filliere[5], etu.filliere[6], &etu.moyenne) == 9 && i < 200) {
        etud[i] = etu;
        i++;
    }

    fclose(f);

    for (int j = 0; j < i - 1; j++) {
        max = j;
        for (int k = j + 1; k < i; k++) {
            if (etud[max].moyenne <= etud[k].moyenne)
                max = k;
        }
        temp = etud[max];
        etud[max] = etud[j];
        etud[j] = temp;
    }

    for (int j = 0; j < i; j++) {
        fprintf(fc, "%d %s %s %s %s %s %s %s %.2f\n", etud[j].CNE, etud[j].filliere[0], etud[j].filliere[1],
                etud[j].filliere[2], etud[j].filliere[3], etud[j].filliere[4], etud[j].filliere[5],
                etud[j].filliere[6], etud[j].moyenne);
    }

    fclose(fc);
    remove("C:\\Users\\Mohamed Sabbar\\Desktop\\choix.txt");
    rename("C:\\Users\\Mohamed Sabbar\\Desktop\\choixclasse.txt","C:\\Users\\Mohamed Sabbar\\Desktop\\choix.txt");
}
void leschoix(int l) {
    FILE *fp = fopen("C:\\Users\\Mohamed Sabbar\\Desktop\\choix.txt", "at+");
     FILE *fk;
    char test[] = "C:\\Users\\Mohamed Sabbar\\Desktop\\les nouveaux\\";
    rewind(fp);
    char filliere[7][5], c[10], cne[10];
    float note, n;
int i;
    if (l <= 7) {
        while (fscanf(fp, "%s %s %s %s %s %s %s %s %f", c, filliere[0], filliere[1], filliere[2], filliere[3], filliere[4], filliere[5], filliere[6], &note) == 9) {
            strcpy(test, "C:\\Users\\Mohamed Sabbar\\Desktop\\CI\\");
            strcat(test, filliere[l]);
            strcat(test, "\\CI1.txt");
            fk = fopen(test, "at+");
            rewind(fk);

             i = 0;
            while (fscanf(fk, "%s %f", cne, &n) == 2) {
                i++;
            }}

            if (i < 40) {
                fprintf(fk, "%s 0.000000\n", c);
            } else {
                choix_de_filliere(l + 1);
            }

            fclose(fk);

        fclose(fp);
    }
remove(fp);}


void choix_de_filliere(char cne[],float note){
    char c[10],choi[7][6];
    float f;int l=0;
    FILE* fp=fopen("C:\\Users\\Mohamed Sabbar\\Desktop\\choix.txt","at+");

struct tm deadline = {0};
deadline.tm_year = 2024 - 1900;
deadline.tm_mon = 0;
deadline.tm_mday = 4;
deadline.tm_hour = 3;
deadline.tm_min = 4;
deadline.tm_sec = 0;


time_t currentTime;
time(&currentTime);

if (difftime(currentTime, mktime(&deadline))< 0) {
rewind(fp);
    while(fscanf(fp,"%s %s %s %s %s %s %s %s %f",c,choi[0],choi[1],choi[2],choi[3],choi[4],choi[5],choi[6],&f)==9){

        if(strcmp(c,cne)==0){
                printf("\a");
            printf("                                                                   Vous avez deja faire choix de filliere ");
            fclose(fp);
        return 0;}}
fclose(fp);
FILE* fp=fopen("C:\\Users\\Mohamed Sabbar\\Desktop\\choix.txt","at+");
        printf("                                                                   ******************Saisie votre choix au dessus:************:\n");

    for(int i = 0; i < 7; i++) {
        printf("                                                                   Donne votre choix num %d : ", i + 1);
        scanf("%5s", choi[i]);
    }

    printf("                                                                   votre choix : ");
    for(int i = 0; i < 7; i++) {
        printf("%s ", choi[i]);
    }
    fprintf(fp,"%s",cne);
    for (int i=0;i<7;i++){
    fprintf(fp," %s",choi[i]);
}
fprintf(fp," %f\n",note);}
fclose(fp);
 if (difftime(currentTime, mktime(&deadline))> 0) {
        printf("\a");
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
    printf("                                                                    Le délai est dépassé\n");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);

  triAP2();
  leschoix(l);}

    }
void rinscription(char nom[], char prenom[],char b[],char cne[]){
        char c[10],a[5],fi[5],mot[10];

FILE *fp=fopen("C:\\Users\\Mohamed Sabbar\\Desktop\\les notes.txt","at+");
char path[]="C:\\Users\\Mohamed Sabbar\\Desktop\\CI\\";
char test[40];
FILE *fm,*fk,*fo;
float note, f;
char CNE[10],annee[5],filliere[5];
rewind(fp);
while(fscanf(fp,"%s %s %s %f",CNE,annee,filliere,&note)==4){
    if(strcmp(CNE,cne)==0){
            fclose(fp);
    if(((strcmp(annee,"CI1")==0)||(strcmp(annee,"CI2")==0)||(strcmp(annee,"CI3")==0))&& (note<12.000000)){
         HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);

        printf("                                                                   Vous etes ajourne ,votre note est une note eliminatoire en cycle d'ingenieur");
        printf("                                                                   Votre niveau est %s filliere %s",annee,filliere);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
    }
 else if((strcmp(annee,"CI3")==0)&& (note>=12.000000)){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    printf("                                                                   Felictations tu as passe votre 5 annnes en ensah,au revoir!!");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);

    strcat(path,filliere);
    strcat(path,"\\");
strcpy(test,path);
    strcat(test,"new.txt");
    strcat(path,annee);
    strcat(path,".txt");
    fm=fopen(path,"rt+");
    fk=fopen(test,"wt+");

    while(fscanf(fm,"%s %f",c,&f)==2){
        if((strcmp(cne,c)!=0) || (note !=f)){
            fprintf(fk,"%s %f\n",c,f);
        }
    }
 fclose(fm);
 fclose(fk);
 remove(path);
 rename(test,path);
 fp=fopen("C:\\Users\\Mohamed Sabbar\\Desktop\\etudiants.bin","ab+"); //probleme ici
 fm=fopen("C:\\Users\\Mohamed Sabbar\\Desktop\\y.bin","wb+");
etudiant e;
rewind(fp);
while(fread(&e,sizeof(e),1,fp)==1){
    if(strcmp(cne,e.cne)!=0){
        fwrite(&e,sizeof(e),1,fm);
    }
}
fclose(fp);
fclose(fm);
remove("C:\\Users\\Mohamed Sabbar\\Desktop\\etudiants.bin");
rename("C:\\Users\\Mohamed Sabbar\\Desktop\\y.bin","C:\\Users\\Mohamed Sabbar\\Desktop\\etudiants.bin");
 fp=fopen("C:\\Users\\Mohamed Sabbar\\Desktop\\les notes.txt","at+");
 fm=fopen("C:\\Users\\Mohamed Sabbar\\Desktop\\1.txt","wt+");
 rewind(fp);
while(fscanf(fp,"%s %s %s %f",c,a,fi,&f)==4){
    if(strcmp(c,cne)!=0){
        fprintf(fm,"%s %s %s %f\n",c,a,fi,f);
    }
}
fclose(fp);
fclose(fm);
remove("C:\\Users\\Mohamed Sabbar\\Desktop\\les notes.txt");
rename("C:\\Users\\Mohamed Sabbar\\Desktop\\1.txt","C:\\Users\\Mohamed Sabbar\\Desktop\\les notes.txt");
fp=fopen("C:\\Users\\Mohamed Sabbar\\Desktop\\motdepasse.txt","at+");
 fm=fopen("C:\\Users\\Mohamed Sabbar\\Desktop\\1.txt","wt+");
 rewind(fp);
while(fscanf(fp,"%s %s",c,mot)==2){
    if(strcmp(c,cne)!=0){
        fprintf(fm,"%s %s\n",c,mot);
    }
}
fclose(fp);
fclose(fm);
remove("C:\\Users\\Mohamed Sabbar\\Desktop\\motdepasse.txt");
rename("C:\\Users\\Mohamed Sabbar\\Desktop\\1.txt","C:\\Users\\Mohamed Sabbar\\Desktop\\motdepasse.txt"); }

 else if(((strcmp(annee,"CI2")==0 || strcmp(annee,"CI1")==0)&& (note>=12.000000))){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    printf("                                                                   Tu as valide votre annee scolaire avec succes \n !!");
    printf("                                                                   Votre niveau actuelle: ");
    if(strcmp(annee,"CI1")==0){
        printf("CI2");
        printf(",votre filliere %s: ",filliere);
        fp=fopen("C:\\Users\\Mohamed Sabbar\\Desktop\\les notes.txt","at+");
        fm=fopen("C:\\Users\\Mohamed Sabbar\\Desktop\\1.txt","wt+");
        rewind(fp);
        while(fscanf(fp,"%s %s %s %f",c,a,fi,&f)==4){
            if(strcmp(c,CNE)!=0){
                fprintf(fm,"%s %s %s %f\n",c,a,fi,f);
            }
        }
    fclose(fp);
    fclose(fm);
    remove("C:\\Users\\Mohamed Sabbar\\Desktop\\les notes.txt");
    rename("C:\\Users\\Mohamed Sabbar\\Desktop\\1.txt","C:\\Users\\Mohamed Sabbar\\Desktop\\les notes.txt");
    fp = fopen("C:\\Users\\Mohamed Sabbar\\Desktop\\les notes.txt", "at+");
fprintf(fp,"%s CI2 %s 0.000000",CNE,filliere);
 strcat(path,filliere);
    strcat(path,"\\");
strcpy(test,path);
    strcat(test,"new.txt");
    strcat(path,annee);
    strcat(path,".txt");
    fm=fopen(path,"rt+");
    fk=fopen(test,"wt+");

    while(fscanf(fm,"%s %f",c,&f)==2){
        if((strcmp(cne,c)!=0) || (note !=f)){
            fprintf(fk,"%s %f\n",c,f);
        }
    }
 fclose(fm);
 fclose(fk);
 remove(path);
 rename(test,path);
fclose(fp);
strcpy(path,"C:\\Users\\Mohamed Sabbar\\Desktop\\CI\\");
strcat(path,filliere);
strcat(path,"\\CI2.txt");
fp=fopen(path,"at+");
fprintf(fp,"%s 0.000000\n",CNE);
fclose(fp);
}
    else{
        printf("CI3");
        printf(",votre filliere: %s",filliere);
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);

        fp=fopen("C:\\Users\\Mohamed Sabbar\\Desktop\\les notes.txt","at+");
        fo=fopen("C:\\Users\\Mohamed Sabbar\\Desktop\\1.txt","wt+");
        rewind(fp);
        while(fscanf(fp,"%s %s %s %f",c,a,fi,&f)==4){
            if(strcmp(c,CNE)!=0){
                fprintf(fo,"%s %s %s %f\n",c,a,fi,f);
            }
        }
    fclose(fo);
    fclose(fp);
    remove("C:\\Users\\Mohamed Sabbar\\Desktop\\les notes.txt");
    rename("C:\\Users\\Mohamed Sabbar\\Desktop\\1.txt","C:\\Users\\Mohamed Sabbar\\Desktop\\les notes.txt");
    fp = fopen("C:\\Users\\Mohamed Sabbar\\Desktop\\les notes.txt", "at+");
fprintf(fp,"%s CI3 %s 0.000000 \n",CNE,filliere);
 strcat(path,filliere);
    strcat(path,"\\");
strcpy(test,path);
    strcat(test,"new.txt");
    strcat(path,annee);
    strcat(path,".txt");
    fm=fopen(path,"rt+");
    fk=fopen(test,"wt+");

    while(fscanf(fm,"%s %f",c,&f)==2){
        if((strcmp(cne,c)!=0) || (note !=f)){
            fprintf(fk,"%s %f\n",c,f);
        }
    }
 fclose(fm);
 fclose(fk);
 remove(path);
 rename(test,path);
fclose(fp);
strcpy(path,"C:\\Users\\Mohamed Sabbar\\Desktop\\CI\\");
strcat(path,filliere);
strcat(path,"\\CI3.txt");
fp=fopen(path,"at+");
fprintf(fp,"%s 0.000000 \n",CNE);
fclose(fp);}


}
if((strcmp(annee,"CP1")==0||strcmp(annee,"CP2")==0)&& note<10.000000){

printf("                                                                   Vous etes ajourne ,votre note est une note eliminatoire en cycle preparatoire \n");
        printf("                                                                   Votre niveau est %s ",annee);}
if((strcmp(annee,"CP1")==0&& note>10.000000)){
    printf("                                                                   Tu as succes dans ton premiere annee repertoire ");
    fp=fopen("C:\\Users\\Mohamed Sabbar\\AP\\CP1.txt","at+");
    fm=fopen("C:\\Users\\Mohamed Sabbar\\AP\\new.txt","wt+");
    rewind(fp);
    while(fscanf(fp,"%s %f",c,&f)==2){
        if((strcmp(cne,c)!=0)||(note!=f)){
            fprintf(fm,"%s %f\n",c,f);
        }
    }
    fclose(fp);
    fclose(fm);
    remove("C:\\Users\\Mohamed Sabbar\\AP\\CP1.txt");
    rename("C:\\Users\\Mohamed Sabbar\\AP\\new.txt","C:\\Users\\Mohamed Sabbar\\AP\\CP1.txt");
    fp=fopen("C:\\Users\\Mohamed Sabbar\\Desktop\\les notes.txt","at+");
        fo=fopen("C:\\Users\\Mohamed Sabbar\\Desktop\\1.txt","wt+");
        rewind(fp);
        while(fscanf(fp,"%s %s %s %f",c,a,fi,&f)==4){
            if(strcmp(c,CNE)!=0){
                fprintf(fo,"%s %s %s %f\n",c,a,fi,f);
            }
        }
    fclose(fo);
    fclose(fp);
    remove("C:\\Users\\Mohamed Sabbar\\Desktop\\les notes.txt");
    rename("C:\\Users\\Mohamed Sabbar\\Desktop\\1.txt","C:\\Users\\Mohamed Sabbar\\Desktop\\les notes.txt");
    fp = fopen("C:\\Users\\Mohamed Sabbar\\Desktop\\les notes.txt", "at+");
fprintf(fp,"%s CI3 %s 0.000000 \n",CNE,filliere);
}
if((strcmp(annee,"CP2")==0&& note>10.000000)){
        system("cls");
printf("                                                                   Tu as valide votre annee scolaire avec succes avec !! \n");
Etiquette:printf("                                                             Est-ce-que vous voulez faire le choix des fillieres [O//N]:");
fflush(stdin);
char reponse;
scanf("%c",&reponse);
while((reponse!='O')&&(reponse!='N')&&(reponse!='o')&&(reponse!='n')){
        printf("/a");
    printf("                                                                   Incorrect reponse !! \n");
    fflush(stdin);
    goto Etiquette;
    }
if(reponse=='N' ||reponse=='n'){
    printf("                                                                   D'accord , le dernier delai pour saisir votre choix est 4/12/2023 \n");}
else{
    choix_de_filliere(CNE,note);
}
}


}}
sleep(10);
system("cls");
accueil( nom,prenom,b,cne);}



#endif // RéINSCRIPTION_H_INCLUDED
