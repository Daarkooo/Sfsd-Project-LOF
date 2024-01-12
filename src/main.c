#include <stdio.h>
#include <stdlib.h>
#include "methods.h"
#include "methods.c"



int main(int argc, char *argv[])
{
    printf("Hello brother !, how are you today ?\n");


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
    LOF_fileP fichierLOF;
    int n;
    printf("Combien d'etudiant voulez vous inserez : ");
    scanf("%d",&n);

    createLOF(fichierLOF, "test.bin", n);


    printf("Combien d'etudiant voulez vous inserez : ");
    scanf("%d",&n);

    createLOF(fichierLOF, "test2.bin", n);

    printf("\n");    
    printHeader(fichierLOF, "test.bin");
    printf("\n");
    printHeader(fichierLOF, "test2.bin");

    extractLOF(fichierLOF, "test.bin", "student.txt");
    extractLOF(fichierLOF, "test2.bin", "student2.txt");

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


    //---------------- FONCTIONS PAR ENCORE VÉRIFIÉS ---------------



    

    return 0;
}
