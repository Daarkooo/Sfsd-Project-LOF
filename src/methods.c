#include "methods.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
}

int readHeader(LOF_fileP f, int K){

};  //retourner le contenue du K ème champ de l'entete

void printHeader(LOF_fileP f, char file_name[20]){
 // Ouvrir le fichier 
    f->file = fopen(file_name, "rb");

    // Verification d'ouverture du fichier 
    if (f->file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    // Lire l'entête à partir du fichier
    fread(f->header, sizeof(header), 1, f->file);

    fclose(f->file);

    // Afficher le contenu de l'entête
    printf("First Block: %d\n", f->header->firstBlock);
    printf("Last Block: %d\n", f->header->lastBlock);
    printf("Number of Blocks: %d\n", f->header->nbBlocks);
    printf("Number of Students: %d\n", f->header->nbStudents);
};  //afficher le contenue de l'entete

void writeBlock(LOF_fileP f, int K, blockP buffer){

};  //mettre le contenue du tampon dans le bloc numero K

void readBlock(LOF_fileP f, int K, blockP buffer){

    // Calculer la position du bloc dans le fichier 
    long position = sizeof(header) + (K-1) * sizeof(block);

    // Se deplacer a la position du bloc dans le fichier
    fseek(f->file, position, SEEK_SET);

    // Lire le contenu du bloc dans le tampon
    fread(buffer, sizeof(block), 1, f->file);

};  //mettre le contenue du bloc numero K dans le tampon

void allocBlock(LOF_fileP f, int* K, blockP buffer){

};   //allouer un nouveau bloc et l'initialiser avec le contenue du tampom

void printLOF(LOF_fileP f, char file_name[20]){
  // Ouvrir le fichier 
    f->file = fopen(file_name, "rb");

    // Vérifier si l'ouverture du fichier a réussi
    if (f->file == NULL) {
        printf("Erreur lors de l'ouverture du fichier");
        return;
    }

    // Aller a la position du premier bloc dans le fichier
    fseek(f->file, sizeof(header), SEEK_SET);

    // Lire et afficher le contenu de chaque bloc dans le fichier
   block buffer;
    for (int blockNum = f->header->firstBlock; blockNum <= f->header->lastBlock; blockNum++) {
        // Lire le contenu du bloc dans le tampon
        fread(&buffer, sizeof(block), 1, f->file);

        // Afficher le contenu de chaque enregistrement logique (student) dans le bloc
        for (int i = 0; i < buffer.NB; i++) {
            printf("Block %d - Student %d:\n", blockNum, i + 1);
            printStudent(&buffer.tab[i]); // Afficher les informations du i-ème étudiant
        }
    }

    // Fermer le fichier
    fclose(f->file);

}


/**********************fonctions prencipale demander **************************/


void insertStudent(LOF_fileP f, char file_name[20], StudentP student){

};  //insertion d'un novelle enregistrement dans le fichier

void DeleteStudent(LOF_fileP f, char file_name[20], int matricule){

}; //suppression de l'enregistrement si il existe

void SearchStudent(LOF_fileP f, char file_name[20], int matricule, int* BlockNB, int* PositionNB, int* exist){

};  //retourne le bloc, position de l'enregistrement s'il est trouve
int readHeader(LOF_fileP f, int K){

};  //retourner le contenue du K ème champ de l'entete


