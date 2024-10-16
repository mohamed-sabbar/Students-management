#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void saisirEtudiant(etudiant *etud) {
    system("cls");
    char path[]="C:\\Users\\Mohamed Sabbar\\Desktop\\";
    char niveau[10],filliere[10],motdepasse[10],specialite[10];
fflush(stdin);
    printf("                                                                   Nom: ");
    fgets(etud->nom, sizeof(etud->nom), stdin);
    etud->nom[strcspn(etud->nom, "\n")] = '\0'; // Supprimer le \n
    fflush(stdin);
    printf("                                                                   Prénom: ");
    fgets(etud->prenom, sizeof(etud->prenom), stdin);
    etud->prenom[strcspn(etud->prenom, "\n")] = '\0';
    fflush(stdin);
    printf("                                                                   CNE: ");
    fgets(etud->cne, sizeof(etud->cne), stdin);
    etud->cne[strcspn(etud->cne, "\n")] = '\0';
    fflush(stdin);
    printf("                                                                   CIN: ");
    fgets(etud->cin, sizeof(etud->cin), stdin);
    etud->cin[strcspn(etud->cin, "\n")] = '\0';
    fflush(stdin);
    printf("                                                                   Date de naissance: ");
    fgets(etud->dateNaissance, sizeof(etud->dateNaissance), stdin);
    etud->dateNaissance[strcspn(etud->dateNaissance, "\n")] = '\0';
    fflush(stdin);
    printf("                                                                   Ville de naissance: ");
    fgets(etud->villeNaissance, sizeof(etud->villeNaissance), stdin);
    etud->villeNaissance[strcspn(etud->villeNaissance, "\n")] = '\0';
        fflush(stdin);
    printf("                                                                   donne son annnee(AP\\CI) :" );
gets(niveau);
    fflush(stdin);
    if(strcmp(niveau,"AP")==0){
    printf("                                                                   donne son annee preparatoire (CP1 / CP2) :");
    gets(filliere);
    strcat(path,niveau);
    strcat(path,"\\");
    strcat(path,filliere);
    strcat(path,".txt");}
    else{
        strcat(path,niveau);
    strcat(path,"\\");

    printf("                                                                   donne la fillire :");
    gets(filliere);
    strcat(path,filliere);
    strcat(path,"\\CI1.txt");

    }

        fflush(stdin);
    printf("                                                                   donne le mot de passe:");
    gets(motdepasse);




    FILE *fp=fopen(path,"at+");
    fprintf(fp,"%s 0.000000\n",etud->cne);
    fclose(fp);
    fp=fopen("C:\\Users\\Mohamed Sabbar\\Desktop\\les notes.txt","at+");
    fprintf(fp,"%s %s %s 0.000000\n",etud->cne,niveau,filliere);
    fclose(fp);
    fp=fopen("C:\\Users\\Mohamed Sabbar\\Desktop\\motdepasse.txt","at+");
    fprintf(fp,"%s %s\n",etud->cne,motdepasse);
    fclose(fp);

}

void ecrireEtudiantDansFichier(const char *nomFichier, const etudiant *etud) {
    FILE *fichier = fopen(nomFichier, "ab");

    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    fwrite(etud, sizeof(etudiant), 1, fichier);

    fclose(fichier);
}

void ajoute() {
    etudiant nouvelEtudiant;

    saisirEtudiant(&nouvelEtudiant);

    ecrireEtudiantDansFichier("C:\\Users\\Mohamed Sabbar\\etudiants.bin", &nouvelEtudiant);

    printf("                                                                   L'étudiant a été ajouté au fichier avec succès.\n");

 sleep(10);
    system("cls");
accueil_admin( );
    return 0;
}
