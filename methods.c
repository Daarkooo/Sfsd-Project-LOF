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
    
} // afficher un block

void createBlock(blockP S) {
    printf("enter the numbre of students in this block \t");
    scanf("%d",&S->NB);
    
    for(int i=0 ; i<(S->NB) ; i++){
        printf("enter information for student numbre %d : \n",i+1);
        createStudent(&S->tab[i]);
    }
    

} // lire les informations d'un block

 void InitialLoading(char file_name[20]){

 };    //fonction de chargement initial car le fichier est ordonne

void openLOF(LOF_fileP f, char file_name[20], char open_mode){

};  //ouvrir le fichier logique

void closeLOF(LOF_fileP f, char file_name[20]){

} ; //fermer le fichier logique

void writeHeader(LOF_fileP f, int K, int val){

} ;//affecter la valeur val au K ème champ de l'entete

int readHeader(LOF_fileP f, int K){

};  //retourner le contenue du K ème champ de l'entete

void printHeader(LOF_fileP f, char file_name[20]){

};  //afficher le contenue de l'entete

void writeBlock(LOF_fileP f, int K, blockP buffer){

};  //mettre le contenue du tampon dans le bloc numero K

void readBlock(LOF_fileP f, int K, blockP buffer){

};  //mettre le contenue du bloc numero K dans le tampon

void allocBlock(LOF_fileP f, int* K, blockP buffer){

};   //allouer un nouveau bloc et l'initialiser avec le contenue du tampom

void printLOF(LOF_fileP f, char file_name[20]){

};     //afficher le contenue du fichier

/**********************fonctions prencipale demander **************************/


void insertStudent(LOF_fileP f, char file_name[20], StudentP student){

};  //insertion d'un novelle enregistrement dans le fichier

void DeleteStudent(LOF_fileP f, char file_name[20], int matricule){

}; //suppression de l'enregistrement si il existe

void SearchStudent(LOF_fileP f, char file_name[20], int matricule, int* BlockNB, int* PositionNB, int* exist){

};  //retourne le bloc, position de l'enregistrement s'il est trouve