#include <stdio.h>
#include <stdlib.h>
#include "methods.h"
#include "methods.c"



int main(int argc, char *argv[])
{
    printf("Hello brother !, how are you today ?\n");

    int id;
    int stop = 0;
    int option1;
    int option;
    char ch1[20], ch2[20];
    LOF_fileP fichierLOF;
    do
    {
        printf("\n\t---- MAIN MENU ----");
        printf("\n1- Create a new LOF file");
        printf("\n2- Edit an existing LOF file");
        printf("\n3- EXIT the program");
        printf("\n\nWhat option do you choose : ");
        scanf("%d", &option);
        switch (option)
        {
            case 1:
                printf("\n\t---- Creating a new file ----");
                printf("\nChoose a name for your file : ");
                scanf("%s", ch1);
                strcpy(ch2, ch1);
                strcat(ch1, ".bin");
                strcat(ch2, ".txt");
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
                printf("\n\nWhat option do you choose : ");
                scanf("%d", &option1);
                switch (option1)
                {
                    case 2:
                        printf("enter student ID: ");
                        scanf("%d", &id);
                        printf("%s\n", ch1);
                        DeleteStudent(fichierLOF,ch1,id);
                        break;

                    default:
                        break;
                }
                break;
            case 3:
                stop = 1;
                break;
            default:
                printf("\nYOU CHOOSED A WRONG OPTION !\n");
                break;
        }
    } while (stop == 0);
    
    // LOF_fileP fichierLOF;
    // int n;
    // IndexP tab;
    // printf("Combien d'etudiant voulez vous inserez : ");
    // scanf("%d",&n);

    // createLOF(fichierLOF, "test.bin", n);
    // fichierLOF = openLOF(fichierLOF,"test.bin",'o');
    // printTerminal(fichierLOF,"test.bin");
  
    // extractLOF(fichierLOF,"test.bin","test.txt");




    //------------------ FONCTIONS VÉRIFIÉS -------------------

    // StudentP s = malloc(sizeof(Student));
    // createStudent(s);
    // printStudent(s);
    // free(s);

    // blockP B = malloc(sizeof(block));
    // createBlock(B);
    // printBlock(B);
    // free(B);


    // LOF_fileP fichierLOF = openLOF(fichierLOF, "test.bin", 'n');

    // writeHeader(fichierLOF, 1, 5);
    // writeHeader(fichierLOF, 3, 8);

    // int X = readHeader(fichierLOF, 1);
    // int Y = readHeader(fichierLOF, 3);

    // printf("\n%d\n%d\n", X, Y);

    // //ALLOUER UN PREMIER BLOC :
    // int X;
    // allocBlock(fichierLOF, &X, &buffer);
    // createBlock(buffer);

    // writeBlock(fichierLOF, X, buffer);

    // //ALLOUER UN DEUXIEME BLOC :
    // int Y;
    // allocBlock(fichierLOF, &Y, &buffer);
    // createBlock(buffer);

    // writeBlock(fichierLOF, Y, buffer);

    // //AFFICHAGE DES DEUX BLOC ALOUEE :
    // readBlock(fichierLOF, X, buffer);
    // printBlock(buffer);
    // readBlock(fichierLOF, Y, buffer);
    // printBlock(buffer);
    

    // closeLOF(fichierLOF);

    // printHeader(fichierLOF, "test.bin");    


    // StudentP t;
    // t = scanTab(t, 4);

    // printf("\n---------- LE CONTENUE DU TABLEAU AVANT LE TRIE -------\n");
    // for (int i = 0; i < 4; i++)
    //     printStudent(t + i);
    
    // quickSortTab(t, 0, 3);

    // printf("\n---------- LE CONTENUE DU TABLEAU APRES LE QUICKSORT -------\n");
    // for (int i = 0; i < 4; i++)
    //     printStudent(t + i);


    //---------------------- CreateLOF and ExtractLOF methods ---------------------

    // LOF_fileP fichierLOF;
    // int n;
    // printf("Combien d'etudiant voulez vous inserez : ");
    // scanf("%d",&n);

    // LOF_fileP fichierLOF;
    // int n;
    // printf("Combien d'etudiant voulez vous inserez : ");
    // scanf("%d",&n);

    // createLOF(fichierLOF, "test.bin", n);







    // extractLOF(fichierLOF, "test.bin", "student.txt");
    // printf("Combien d'etudiant voulez vous inserez : ");
    // scanf("%d",&n);

    // createLOF(fichierLOF, "test2.bin", n);

    // printf("\n");    
    // printHeader(fichierLOF, "test.bin");
    // printf("\n");
    // printHeader(fichierLOF, "test2.bin");

    // extractLOF(fichierLOF, "test.bin", "student.txt");
    // extractLOF(fichierLOF, "test2.bin", "student2.txt");

    // printf("Combien d'etudiant voulez vous inserez : ");
    // scanf("%d",&n);

    // createLOF(fichierLOF, "test2.bin", n);

    // printf("\n");    
    // printHeader(fichierLOF, "test.bin");
    // printf("\n");
    // printHeader(fichierLOF, "test2.bin");

    // extractLOF(fichierLOF, "test.bin", "student.txt");
    // extractLOF(fichierLOF, "test2.bin", "student2.txt");

    // printHeader(fichierLOF, "test.bin");

    // fichierLOF = openLOF(fichierLOF, "test.bin", 'o');

    // int numBlock = readHeader(fichierLOF, 1);
    // int i = 1;
    // while (numBlock != -1)
    // {
    //     readBlock(fichierLOF, numBlock, buffer);
    //     printf("\nBLOCK NUMERO %d : \n", i);
    //     printBlock(buffer);
    //     printf("le suivant : %d\n", buffer->svt);
    //     numBlock = buffer->svt;
    //     i++;
    // }

    closeLOF(fichierLOF);


    //---------------- FONCTIONS PAR ENCORE VÉRIFIÉS ---------------



    

    return 0;
}
