#include <stdio.h>
#include <stdlib.h>
#include "methods.h"
#include "methods.c"



int main(int argc, char *argv[])
{
    printf("Hello brother !, how are you today ?\n");

    int n;
    int stop = 0;
    int option;
    char ch1[20], ch2[20];
    LOF_fileP fichierLOF;
    int blockNB, posNB, existe;
    char trompe;
    StudentP student;

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
                    strcpy(ch2, ch1);
                    strcat(ch1, ".bin");
                    strcat(ch2, ".txt");
                    if (openLOF(fichierLOF, ch1, 'o') == NULL)
                    {
                        printf("\nYOUR FILE DOESN'T EXIST\n");
                        break;
                    }

                    edit_menu:
                    printf("\n1- Insert a student");
                    printf("\n2- Delete a student");
                    printf("\n3- Search for a student");
                    printf("\n4- Modify a student");
                    printf("\n5- Return to MAIN MENU <--");
                    printf("\n\nWhat option do you choose : ");
                    if(scanf("%d", &option) == 1){
                        switch (option)
                        {
                        case 1:
                                
                                fichierLOF = openLOF(fichierLOF, ch1, 'o');
                                student = malloc(sizeof(Student)); 
                                printf("create student\n");
                                createStudent(student);
                                // while (student->matricule != )
                                // {
                                //     /* code */
                                // }
                                
                                insertStudent(fichierLOF, ch1, student);
                                extractLOF(fichierLOF, ch1, ch2);
                                printHeader(fichierLOF, ch1);
                                
                            goto edit_menu;
                        case 2:
                                printf("\nEntrez le matricule de l'etudiant a supprimer : ");
                                scanf("%d",&n);
                                DeleteStudent(fichierLOF, ch1, n);
                                extractLOF(fichierLOF, ch1, ch2);

                                printHeader(fichierLOF, ch1);
                            goto edit_menu;
                        case 3:
                            
                            do
                            {
                                printf("Entrez le matricule de l'etudiant que vous cherchez : ");
                                scanf("%d",&n);
                                
                                
                                SearchStudent(fichierLOF, ch1, n, &blockNB, &posNB, &existe);
                                if (existe == 1){
                                    printf("\nETUDIANT TROUVE :\nBlockID : %d\nPosition : %d\n", blockNB, posNB);
                                    break;}
                                else{
                                    printf("\nCETTE ETUDIANT N'EXISTE PAS\n");
                                    printf("Vous vous etes trompes? (o/n): ");
                                    scanf(" %c",&trompe);
                                    }
                            } while (trompe == 'o' || trompe == 'O');

                            goto edit_menu;

                        case 4:
                            student = malloc(sizeof(Student)); 
                            printf("edit student\n");
                            createStudent(student);

                            ModifyStudent(fichierLOF,ch1,student);
                            extractLOF(fichierLOF, ch1, ch2);

                            goto edit_menu;
                        
                        case 5:
                            goto main_menu;
                        
                        default:
                            printf("\nYOU CHOOSED A WRONG OPTION !\n");
                            goto edit_menu;
                        }
                    }
                    else{
                        printf("please enter a valid number!\n");
                        while((getchar() != '\n'));
                        goto edit_menu;
                    }
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
    

    closeLOF(fichierLOF);
    return 0;

}