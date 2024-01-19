#include <stdio.h>
#include <stdlib.h>
#include "methods.h"
#include "methods.c"



int main(int argc, char *argv[])
{
    printf("Hello brother !, how are you today ?\n");

    int id;
    int stop = 0;
    int option;
    char ch1[20], ch2[20];
    LOF_fileP fichierLOF;
    int blockNB, posNB, existe;
    do
    {
        main_menu:
        printf("\n\t---- MAIN MENU ----");
        printf("\n1- Create a new LOF file");
        printf("\n2- Edit an existing LOF file");
        printf("\n3- EXIT the program");
        printf("\n\nWhat option do you choose : ");
        if(scanf("%d", &option) == 1){
            switch (option)
            {
                case 1:
                    printf("\n\t---- Creating a new file ----");
                    printf("\nChoose a name for your file : ");
                    scanf("%s", ch1);
                    strcpy(ch2, ch1);
                    strcat(ch1, ".bin");
                    strcat(ch2, ".txt");
                    if (openLOF(fichierLOF, ch1, 'o') != NULL) {
                        printf("\nCE FICHIER EXISTE DEJA, CHOISSISSEZ UN AUTRE NOM !\n");
                        break;
                    }
                    int n;
                    printf("Combien d'etudiant voulez vous inserez : ");
                    scanf("%d",&n);
                    createLOF(fichierLOF, ch1, n);
                    extractLOF(fichierLOF, ch1, ch2);
                    printf("\nYour file was succesfully created, you can see the result inside the file : %s\n", ch2);
                    break;
                case 2:
                    printf("\n\t---- Editing an old file ----");
                    printf("\nWhat's the name of your file : ");
                    scanf("%s", ch1);
                    strcat(ch1, ".bin");
                    if (openLOF(fichierLOF, ch1, 'o') == NULL)
                    {
                        printf("\nYOUR FILE DOESN'T EXIST\n");
                        break;
                    }
                    printf("\n1- Insert a student");
                    printf("\n2- Delete a student");
                    printf("\n3- Search for a student");
                    printf("\n4- Modify a student");
                    printf("\n5- Return to MAIN MENU <--");
                    printf("\n\nWhat option do you choose : ");
                    scanf("%d", &option);
                    switch (option)
                    {
                    case 1:
                        /* code */
                        break;
                    case 2:
                            printf("enter student ID: ");
                            scanf("%d", &id);
                            DeleteStudent(fichierLOF,ch1,ch2,id);
                        break;
                    case 3:
                        char trompe;
                        do
                        {
                            printf("Entrez le matricule de l'etudiant que vous cherchez : ");
                            scanf("%d",&n);
                            SearchStudent(fichierLOF, "test.bin", n, &blockNB, &posNB, &existe);
                            if (existe == 1){
                                printf("\nETUDIANT TROUVE :\nBlock : %d\nPosition : %d\n", blockNB, posNB);
                                break;}
                            else{
                                printf("\nCETTE ETUDIANT N'EXISTE PAS\n");
                                printf("Vous vous etes trompes? (o/n): ");
                                scanf(" %c",&trompe);
                                }
                        } while (trompe == 'o' || trompe == 'O');
                    
                        break;
                    case 4:

                        break;
                    
                    case 5:
                        goto main_menu;
                        break;
                    
                    default:
                        printf("\nYOU CHOOSED A WRONG OPTION !\n");
                        break;
                    }
                    break;
                case 3:
                    stop = 1;
                    break;
                default:
                    printf("YOU CHOOSED A WRONG OPTION !\n");
                    break;
            }
        }else{
            printf("please enter a valid number!\n");
            while((getchar() != '\n'));
        }

    } while (stop == 0);
    

    // ----------Delete fun test ---------------------------------
    // LOF_fileP fichierLOF;
    // int n;
    // printf("Combien d'etudiant voulez vous inserez : ");
    // scanf("%d",&n);

    // int blockNB, posNB, existe;
    // createLOF(fichierLOF, "hichem.bin", n);
    // extractLOF(fichierLOF, "hichem.bin", "hichem.txt");
    // printf("Quelle est le matricule de l'etudiant que vous voulez le supprimer : ");
    // scanf("%d",&n);
    // DeleteStudent(fichierLOF, "hichem.bin", "hichem.txt",n);
    // printHeader(fichierLOF,"hichem.bin");

    
    // LOF_fileP fichierLOF;
    // int n;
    // StudentP student;
    // createStudent(student);
    // printStudent(student);
    // printf("Combien d'etudiant voulez vous inserez : ");
    // scanf("%d",&n);

    // int blockNB, posNB, existe;
    // createLOF(fichierLOF, "hichem.bin", n);

    // extractLOF(fichierLOF, "hichem.bin", "hichem.txt");
    // printf("Quelle est le matricule de l'etudiant que vous voulez le inserer : ");
    // scanf("%d",&n);
    // insertStudent(fichierLOF,"hichem.bin",student);
    // printf("block: %d, pos: %d \n",blockNB,posNB);
   
    
    // printHeader(fichierLOF,"hichem.bin");


    closeLOF(fichierLOF);
    return 0;
}
