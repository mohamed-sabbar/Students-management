#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
bool deleteStudent() {
    system("cls");
    fflush(stdin);
    char cneToDelete[10];
    char passwd[10];
    printf("                                                                   \tdonne le CNE de etudiant pour supprimer :");
    gets(cneToDelete);
    FILE *inputFile = fopen("C:\\Users\\Mohamed Sabbar\\Desktop\\etudiants.bin", "rb");
    if (inputFile == NULL) {
        perror("Error opening file for reading");
        return false;
    }

    FILE *outputFile = fopen("C:\\Users\\Mohamed Sabbar\\Desktop\\temp.bin", "wb");
    if (outputFile == NULL) {
        perror("Error opening temp file for writing");
        fclose(inputFile);
        return false;
    }

    etudiant currentStudent;

    while (fread(&currentStudent, sizeof(currentStudent), 1, inputFile) == 1) {
        if (strcmp(currentStudent.cne, cneToDelete) != 0) {
            fwrite(&currentStudent, sizeof(etudiant), 1, outputFile);
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    if (remove("C:\\Users\\Mohamed Sabbar\\Desktop\\etudiants.bin") != 0) {
        perror("Error deleting original file");
        return false;
    }

    if (rename("C:\\Users\\Mohamed Sabbar\\Desktop\\temp.bin", "C:\\Users\\Mohamed Sabbar\\Desktop\\etudiants.bin") != 0) {
        perror("Error renaming temp file");
        return false;
    }

    FILE *fp = fopen("C:\\Users\\Mohamed Sabbar\\Desktop\\les notes.txt", "rt+");
    char path[] = "C:\\Users\\Mohamed Sabbar\\Desktop\\";
    char test[100];
    char c[20], annne[10], filliere[10];
    float note;

    while (fscanf(fp, "%s %s %s %f", c, annne, filliere, &note) == 4) {
        if (strcmp(cneToDelete, c) == 0) {


            fclose(fp);
            break;
        }
    }

    if ((strcmp(annne, "CP1") == 0) || (strcmp(annne, "CP2") == 0)) {
strcat(path, "AP");
        strcat(path, "\\");
        strcpy(test,path);
        strcat(path, annne);
        strcat(path, ".txt");
        strcat(test,"\\new.txt");

        fp = fopen(path, "at+");
        FILE *fm = fopen(test, "wt+");
        rewind(fp);
        while (fscanf(fp, "%s %f", c, &note) == 2) {
            if (strcmp(cneToDelete, c) != 0) {
                fprintf(fm, "%s %f\n", c, note);
            }



        }

        fclose(fp);
        fclose(fm);
   remove(path);

      rename(test, path);  }
       if((strcmp(annne, "CI2") == 0) || (strcmp(annne, "CI1"))|| (strcmp(annne, "CI3"))) {
        strcat(path, "CI");
        strcat(path, "\\");
        strcat(path, filliere);
        strcat(path, "\\");
        strcpy(test,path);
        strcat(test,"new.txt");
        strcat(path, annne);
        strcat(path, ".txt");
        fp = fopen(path, "at+");
        FILE *fm = fopen(test, "wt+");
        rewind(fp);
        while (fscanf(fp, "%s %f", c, &note) == 2) {
            if (strcmp(cneToDelete, c) != 0) {
                fprintf(fm, "%s %f\n", c, note);
            }
        }
        fclose(fp);
        fclose(fm);

 remove(path);

      rename(test, path);
    }


    fp = fopen("C:\\Users\\Mohamed Sabbar\\Desktop\\les notes.txt", "rt+");
    FILE *fm = fopen("C:\\Users\\Mohamed Sabbar\\Desktop\\1.txt", "wt+");
    while (fscanf(fp, "%s %s %s %f", c, annne, filliere, &note) == 4) {
        if (strcmp(cneToDelete, c) != 0) {
            fprintf(fm, "%s %s %s %f\n", c, annne, filliere, note);
        }
    }
    fclose(fp);
    fclose(fm);
    remove("C:\\Users\\Mohamed Sabbar\\Desktop\\les notes.txt");
    rename("C:\\Users\\Mohamed Sabbar\\Desktop\\1.txt", "C:\\Users\\Mohamed Sabbar\\Desktop\\les notes.txt");
 fp = fopen("C:\\Users\\Mohamed Sabbar\\Desktop\\motdepasse.txt", "rt+");
    fm = fopen("C:\\Users\\Mohamed Sabbar\\Desktop\\1.txt", "wt+");
    while (fscanf(fp, "%s %s", c,passwd) == 2) {
        if (strcmp(cneToDelete, c) != 0) {
            fprintf(fm, "%s %s\n", c, passwd);
        }
    }
    fclose(fp);
    fclose(fm);
    remove("C:\\Users\\Mohamed Sabbar\\Desktop\\motdepasse.txt");
    rename("C:\\Users\\Mohamed Sabbar\\Desktop\\1.txt", "C:\\Users\\Mohamed Sabbar\\Desktop\\motdepasse.txt");
printf("                                                                   \tetudiant de CNE %s est supprime avec succes !",cneToDelete);
sleep(10);
system("cls");
accueil_admin( );
    return true;
}
