#include <stdio.h>
#include <stdlib.h>
#include "methods.h"
#include "methods.c"



int main(int argc, char *argv[])
{
    printf("Hello brother !, how are you today ?\n");


    int stop = 0;
    int option;
    char ch1[20], ch2[20];
    LOF_fileP fichierLOF;
    int blockNB, posNB, existe;
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
                    printf("\nEntrez le matricule de l'etudiant a supprimer : ");
                    scanf("%d",&n);
                    DeleteStudent(fichierLOF, ch1, n, ch2);
                    printf("\nVous pouvez verifier la suppression dans votre fichier : %s\n", ch2);
                    break;
                case 3:
                    printf("\nEntrez le matricule de l'etudiant que vous cherchez : ");
                    scanf("%d",&n);
                    SearchStudent(fichierLOF, ch1, n, &blockNB, &posNB, &existe);
                    if (existe == 1)
                        printf("\nETUDIANT TROUVE :\nBlock : %d\nPosition : %d\n", blockNB, posNB);
                    else
                        printf("\nCETTE ETUDIANT N'EXISTE PAS\n");
                    break;
                case 4:

                    break;
                case 5:

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
                printf("\nYOU CHOOSED A WRONG OPTION !\n");
                break;
        }
    } while (stop == 0);
    







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


    // createLOF(fichierLOF, "test.bin", n);
    // extractLOF(fichierLOF, "test.bin", "test.txt");
   

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

    // closeLOF(fichierLOF);

    //--------- SearchStudent test ---------
    // LOF_fileP fichierLOF;
    // int n;
    // printf("Combien d'etudiant voulez vous inserez : ");
    // scanf("%d",&n);

    // int blockNB, posNB, existe;
    // createLOF(fichierLOF, "test.bin", n);
    // extractLOF(fichierLOF, "test.bin", "test.txt");
    // printf("Quelle est la valeur que vous recherchez : ");
    // scanf("%d",&n);
    // SearchStudent(fichierLOF, "test.bin", n, &blockNB, &posNB, &existe);
    // if (existe == 1)
    //     printf("\nETUDIANT TROUVE :\nBlock : %d\nPosition : %d\n\n", blockNB, posNB);
    // else
    //     printf("\nCETTE ETUDIANT N'EXISTE PAS\n\n");


    //------------- DELETE STUDENT METHOD ------------
    // printf("\nMatricule a supprimer : ");
    // scanf("%d",&n);
    // DeleteStudent(fichierLOF, "test.bin", n, "test.txt");


    //----------- READ AND WRITE INDEX TABLE METHODS -------
    // fichierLOF = openLOF(fichierLOF, "test.bin", 'o');
    // int x = readHeader(fichierLOF, 3);
    // int y;
    // IndexP tab = InitTabIndex(fichierLOF, &y);
    // printf("\nlength == %d\n", y);
    // writeIndexTab(fichierLOF, tab, y, x);
    // IndexP tab2;
    // readIndexTab(fichierLOF, tab2, y, x);
    // for (int i = 0; i < x; i++)
    // {
    //     printf("\n%3d %3d\n", tab2[i].blockID, tab2[i].lastKey);
    // }
    // closeLOF(fichierLOF);

    //---------------- FONCTIONS PAR ENCORE VÉRIFIÉS ---------------

    
    // LOF_fileP fichierLOF;
    // int n;
    // printf("Combien d'etudiant voulez vous inserez : ");
    // scanf("%d",&n);

    // createLOF(fichierLOF, "test.bin", n);
    // extractLOF(fichierLOF, "test.bin", "test.txt");

    
    

    return 0;
}
