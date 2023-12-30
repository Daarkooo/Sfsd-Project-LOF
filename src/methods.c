#include "methods.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void printStudent(StudentP S) {

}

void createStudent(StudentP S) {

}


void printBlock(blockP S) {

} // afficher un etudiant

void createBlock(blockP S) {


} // lire les informations d'un etudiant



void openLOF(LOF_fileP f, char file_name[20],const char open_mode) {
    f = malloc(sizeof(LOF_file));
    if (open_mode == 'r') {  // On ouvre le fichier en mode lecture (le fichier existe deja)
        f->file = fopen(file_name, "rb");
        fread(f->header, sizeof(header), 1, f->file);
        return;
    }
    if (open_mode == 'w') {  // On ouvre le fichier en mode ecriture (le fichier existe pas, on le cree et on initialise l'entete)
        f->file = fopen(file_name, "wb");
        // Initialisation du header a zero
        f->header->firstBlock = 0;
        f->header->lastBlock = 0;
        f->header->nbBlocks = 0;
        f->header->nbStudents = 0;
        fwrite(f->header, sizeof(header), 1, f->file);
        return;
    }
}//ouvrir le fichier logique

void closeLOF(LOF_fileP f, char file_name[20]){
    rewind(f->file); // position le curseur au debut de fichier 
    fread(f->header,sizeof(header),1,f->file); // la sauvegarde du header 
    fclose(f->file);// la fermeture du fichier

}  //fermer le fichier logique

void writeHeader(LOF_fileP f, int K, int val) {
    switch (K)
    {
        case 1:
            f->header->firstBlock = val;
            break;
        case 2:
            f->header->lastBlock = val;
            break;
        case 3:
            f->header->nbBlocks = val;
            break;
        case 4:
            f->header->nbStudents = val;
            break;
        default:
            printf("Error in writing header, you chose a wrong number\n");
            break;
    }
}//affecter la valeur val au K ème champ de l'entete

int readHeader(LOF_fileP f, int K) {
    switch (k)
    {
    case 1:
        return f->header->firstBlock;
        break;
    case 2:
        return f->header->lasBlock;
        break;
    case 3:
        return f->header->nbBlocks;
        break;
    case 4:
        return f->header->nbStudents;
    default:
        printf("reading error, pick a valid number (1-4).\n");
        break;
    }
}  //retourner le contenue du K ème champ de l'entete

void printHeader(LOF_fileP f, char file_name[20]) {

}  //afficher le contenue de l'entete

void writeBlock(LOF_fileP f, int K, blockP buffer) {
    fseek(f->file,sizeof(header)+((K)*sizeof(blockP)),SEEK_SET);
    fwrite(buffer,sizeof(blockP),1,f->file);
    rewind(f->file); // on se repositionne au debut de fichier 
}  //mettre le contenue du tampon dans le bloc numero K

void readBlock(LOF_fileP f, int K, blockP buffer) {

}  //mettre le contenue du bloc numero K dans le tampon

void allocBlock(LOF_fileP f, int* K, blockP buffer) {
    buffer->NB = 0;
    buffer->svt = -1;
    *K = readHeader(f, 3) + 1;
    f->header->lastBlock = *K;
    Student s;      //declaration d'un etudiant de type NULL sans aucune valeur
    s.deleted = 1;
    strcpy(s.name, " ");
    strcpy(s.surname, " ");
    s.matricule = 0;
    for (int i = 0; i < MAX_E; i++)
        buffer->tab[i] = s; //initialiser toute les position du bloc avec un etudiant NULL
}   //allouer un nouveau bloc et l'initialiser avec le contenue du tampom

void printLOF(LOF_fileP f, char file_name[20]) {

}     //afficher le contenue du fichier


void InitialLoading(char file_name[20]) {

}    //fonction de chargement initial car le fichier est ordonne


void createLOF(LOF_fileP f, char file_name[20], int N) {

}     //creation du fichier avec N enregistrement logique

void insertStudent(LOF_fileP f, char file_name[20], StudentP student) {

}  //insertion d'un novelle enregistrement dans le fichier

void DeleteStudent(LOF_fileP f, char file_name[20], int matricule) {

} //suppression de l'enregistrement si il existe

void SearchStudent(LOF_fileP f, char file_name[20], int matricule, int* BlockNB, int* PositionNB, int* exist) {

}  //retourne le bloc, position de l'enregistrement s'il est trouve

void ModifyStudent(LOF_fileP f, char file_name[20], int matricule, StudentP student) {

}   //modifier le contenue de l'enregistrement s'il existe
