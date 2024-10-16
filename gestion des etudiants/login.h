#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"home.h"
#include<windows.h>

void createpassword(char passwd[]) {
   // system("color F0");
    printf("                                                                   \tdonne le mot de passe :");
    int i = 0;
    char c;
    while ((c = getch()) != 13 && i < 15 - 1) {
        *(passwd + i) = c;
        if (c == 8) {
            if (i > 0) {
                putch('\b');
                putch(' ');
                putch('\b');
                i--;
            }
            continue;
        }

        printf("*");
        i++;
    }
    *(passwd + i) = '\0';

;}
void identite(){
//system("color F0");
    char b[20],CNE[100],C[100],nom[20],prenom[20];
    char m_d_p[20],mot[20];
      FILE *fp,*fm;
do{
              //      system("color F0");

printf("\n");
printf("\n");
printf("                                                                   \tDonnez votre autorisation (etudiant//admin):");




    gets(b);
    if(strcmp(b,"etudiant")!=0 && strcmp(b,"admin")!=0){

            printf("\a");
            //system("color 0F");
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                   SetConsoleTextAttribute(hConsole, FOREGROUND_RED);



      printf("                                                                   \tEssaye une autre fois nouveau \n");
      SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);}


fflush(stdin);
}while(strcmp(b,"etudiant")!=0 && strcmp(b,"admin")!=0);
int i=0;
if(strcmp(b,"etudiant")==0){
    fp = fopen("C:\\Users\\Mohamed Sabbar\\Desktop\\etudiants.bin", "ab+");
 fm = fopen("C:\\Users\\Mohamed Sabbar\\Desktop\\motdepasse.txt", "at+");
Etiquete:
printf("                                                                   \tdonne votre CNE:  ");
gets(C);
createpassword(mot);
rewind(fm);
printf("\n");
while (fscanf(fm,"%s %s\n",CNE, m_d_p)==2 ) {
if (strcmp(C, CNE) == 0 && strcmp(m_d_p,mot) == 0) {
     i++;
        break;}}
    rewind(fp);
etudiant e;
 if(i==1){
        while(fread(&e, sizeof(etudiant), 1,fp) == 1){
            if(strcmp(e.cne, CNE) == 0){

            ++i;
           system("cls");
fclose(fp);
fclose(fm);

            accueil(e.nom,e.prenom,b,e.cne);
}}}

if(i==0) {
        printf("\a");
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
printf("                                                                   \tle mot de passe ou CNE incorrecte! ");
          SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

printf("\n");

            goto Etiquete;}

fclose(fp);
fclose(fm);}

if(strcmp(b,"admin")==0){


        fflush(stdin);

ettiquette : createpassword(mot);
    if(strcmp(mot,"ensah123")==0){
            system("cls");
accueil_admin();

    }
    else{
        printf("\n");
            printf("\a");

//system("color F0");
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    printf("                                                                   \tmot de passe incorrect !! \n");
          SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        goto ettiquette;
    }
}

}
