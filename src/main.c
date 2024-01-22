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
                            // while(1){
                            //     printf("Quelle est le matricule de l'etudiant que vous voulez l'inserer: ");
                            //     scanf("%d",&n);  

                            //     SearchInsertionPosition(fichierLOF, ch1, n,&blockNB, &posNB);
                            //     printf("block nb = %d - pos = %d\n",blockNB,posNB);
                            // }
                            fichierLOF = openLOF(fichierLOF, ch1, 'o');
                            while (1)
                            {
                                student = malloc(sizeof(Student)); 
                                printf("create student\n");
                                createStudent(student);

                                insertStudent(fichierLOF, ch1, student);
                
                                extractLOF(fichierLOF, ch1, ch2);
                                printHeader(fichierLOF, ch1);
                            }
                            
                        break;
                    case 2:
                            printf("\nEntrez le matricule de l'etudiant a supprimer : ");
                            scanf("%d",&n);
                            DeleteStudent(fichierLOF, ch1, n);
                            extractLOF(fichierLOF, ch1, ch2);
                        break;
                    case 3:
                        
                        do
                        {
                            printf("Entrez le matricule de l'etudiant que vous cherchez : ");
                            scanf("%d",&n);
                            SearchStudent(fichierLOF, ch1, n, &blockNB, &posNB, &existe);
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
    // LOF_fileP fichierLOF= openLOF(fichierLOF,"hichem.bin",'o');
    // printf("First Block: %d\n", fichierLOF->header->firstBlock);
    // printf("Last Block: %d\n", fichierLOF->header->lastBlock);
    // printf("Number of Blocks: %d\n", fichierLOF->header->nbBlocks);
    // printf("Number of Students: %d\n", fichierLOF->header->nbStudents);

    // int n;
    // printf("Quelle est le matricule de l'etudiant que vous voulez le supprimer : ");
    // scanf("%d",&n);
    // DeleteStudent(fichierLOF, "hichem.bin",n);
    // extractLOF(fichierLOF, "hichem.bin", "hichem.txt");



    // LOF_fileP fichierLOF;
    // fichierLOF = openLOF(fichierLOF, "test.bin", 'o');
    // // createLOF(fichierLOF, "test.bin",8);
    // extractLOF(fichierLOF, "test.bin","test.txt");
    // printHeader(fichierLOF,"test.bin");
    // int n;
    // printf("Quelle est le matricule de l'etudiant que vous voulez le supprimer : ");
    // scanf("%d",&n);
    // DeleteStudent(fichierLOF, "test.bin",n);
    // extractLOF(fichierLOF, "test.bin", "test.txt");

    
    // ----------InsertSearchPosition fun test ---------------------------------
    // int n;

    // StudentP student;
    //  LOF_fileP fichierLOF; 
    // int blockNB, posNB;
    // // createLOF(fichierLOF,"test.bin",3);
    // fichierLOF = openLOF(fichierLOF,"test.bin",'o');
    // printHeader(fichierLOF,"test.bin");
    // while (1)
    // {
    //     printf("matricule : ");
    //     scanf("%d",&n);
    //     printf("searching..\n");
    //     SearchInsertionPosition(fichierLOF,"test.bin",n, &blockNB, &posNB);
    //     extractLOF(fichierLOF, "test.bin", "test.txt");

    //     printf("block: %d, position: %d \n",blockNB,posNB);
    // }
    
   
    // ----------Insert function --------------------------------
    //    LOF_fileP fichierLOF = openLOF(fichierLOF,"hichem.bin",'o');
        // int n;
        // LOF_fileP fichierLOF;

        // StudentP student;

        // // int blockNB, posNB;
        // // // scanf("%d",&n);
        // // // createLOF(fichierLOF, "test.bin", 5);
        //  fichierLOF = openLOF(fichierLOF, "random.bin", 'o');
        // // // extractLOF(fichierLOF, "test.bin", "test.txt");
        // // // printHeader(fichierLOF,"hichem.bin");
        // while(1){
        // //     // printf("Quelle est le matricule de l'etudiant que vous voulez l'inserer: ");
        // //     // scanf("%d",&n);  

        // //     // DeleteStudent(fichierLOF,"test.bin",n);
        // //     // extractLOF(fichierLOF, "test.bin", "test.txt");
        //     printf("create student\n");
        //     createStudent(student);
        //     printStudent(student);
        // //     // SearchInsertionPosition(fichierLOF, "test.bin", n,&blockNB, &posNB);
        //     insertStudent(fichierLOF, "random.bin", student);
        // //     // printf("block nb = %d - pos = %d\n",blockNB,posNB);
        //     extractLOF(fichierLOF, "random.bin", "random.txt");
        //     // printf("\nprinting header: \n");
        //     // printHeader(fichierLOF,"test.bin");
        // }


        // closeLOF(fichierLOF);
        return 0;
}
