#include "methods.h"
#include <stdio.h>
#include <stdlib.h>


void printStudent(StudentP S) {

    printf("Name : %s \t", S->name);
    printf("Surname : %s \t", S->surname);
    printf("Matricule : %d \n" , S->matricule );

}

void createStudent(StudentP S) {

    printf("Name : \n");
    scanf("%19s",S->name);
    printf("Surname : \n");
    scanf("%19s",S->surname);
    printf("Matricule : \n");
    scanf("%d", &S->matricule);
    S->deleted=0;

}
void printBlock(blockP S) {
    printf("\nStudent Information:\n");
    for (int i = 0; i < S->NB; i++) {
        
        printf("Student %d: \n", i + 1);
        printStudent(&S->tab[i]);//afficher les information de le i eme etudiant


    }
}
void createBlock(blockP S) {
    printf("enter the numbre of students in this block \t");
    scanf("%d",&S->NB);
    
    for(int i=0 ; i<(S->NB) ; i++){
        printf("enter information for student numbre %d : \n",i+1);
        createStudent(&S->tab[i]);
    }
    


} // lire les informations d'un etudiant