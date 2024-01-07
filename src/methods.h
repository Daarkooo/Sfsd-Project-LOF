#ifndef METHODS_H_INCLUDED
#define METHODS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define MAX_E 10 // nombre maximum d'enregistrement dans un bloc
#define LoadFact 0.6    // facteur de chargement

// declaration de l'enregistrement logique
typedef struct Student
{
    char name[20];
    char surname[20];
    int matricule; // consideré comme la clé pour le tri
    int deleted;    //champ pour la supression logique
} Student, *StudentP;

void viderBuffer(); //fonction pour vider le flux d'entree

// methode lié a l'enregistrement logique
void printStudent(StudentP S); // afficher un etudiant
void studentCopy(StudentP S1, StudentP S2); //copier le contenue de l'etudiant S2 dans l'etudiant S1
void createStudent(StudentP S); // lire les informations d'un etudiant

//------------------------------------------------------------------------

// declaration du bloc
typedef struct block
{
    Student tab[MAX_E]; // tableau d'enregistrement logique
    int NB;             // nombre d'enregistrement logique (case) dans chaque bloc
    int svt;
} block, *blockP;


void printBlock(blockP S); // afficher un etudiant

void createBlock(blockP S); // lire les informations d'un etudiant

//------------------------------------------------------------------------

//declaration de la structure entete
typedef struct header
{
    int firstBlock; // le numero du premier bloc
    int lastBlock;  // le numero du dernier bloc
    int nbBlocks;   // le nombre de bloc dans le fichier
    int nbStudents; // le nombre d'enregistrement logique dans le fichier
}header, *headerP;

//declaration du fichier logique (LOF)
typedef struct LOF_file
{
    headerP header;  //pointeur sur l'entete
    FILE* file; //le fichier physique
}LOF_file, *LOF_fileP;


//declaration du tampon d'E/S
blockP buffer;

//--------------------------------------------------------------------------
//fonctions utilitaires durant le projet
LOF_fileP openLOF(LOF_fileP f, char file_name[20], char open_mode);  //ouvrir le fichier logique
void closeLOF(LOF_fileP f);  //fermer le fichier logique
void writeHeader(LOF_fileP f, int K, int val); //affecter la valeur val au K ème champ de l'entete
int readHeader(LOF_fileP f, int K);  //retourner le contenue du K ème champ de l'entete
void printHeader(LOF_fileP f, char file_name[20]);  //afficher le contenue de l'entete
void writeBlock(LOF_fileP f, int K, blockP buffer);  //mettre le contenue du tampon dans le bloc numero K
void readBlock(LOF_fileP f, int K, blockP buffer);  //mettre le contenue du bloc numero K dans le tampon
void allocBlock(LOF_fileP f, int* K, blockP buffer);   //allouer un nouveau bloc et l'initialiser avec le contenue du tampom
void printLOF(LOF_fileP f, char file_name[20]);     //afficher le contenue du fichier


//-----------------------------------------------------------------------------
//fonctions obligatoire pour le tableau initial
void scanTab(StudentP t, int length);   //creation du tableau
void quickSortTab(StudentP tab, int start, int end);   //trier le tableau en ordre croissant du matricule (la cle)


//------------------------------------------------------------------------------
//fonctions LOF specifiques pour ce projet
void createLOF(LOF_fileP f, char file_name[20], int N);     //creation du fichier avec N enregistrement logique
void insertStudent(LOF_fileP f, char file_name[20], StudentP student);  //insertion d'un novelle enregistrement dans le fichier
void SearchInsertionPosition(LOF_fileP f, char file_name[20], int matricule, int* BlockNB, int* PositionNB);// la recherche de la position ideale pour l'insertion
void DeleteStudent(LOF_fileP f, char file_name[20], int matricule); //suppression de l'enregistrement si il existe
void SearchStudent(LOF_fileP f, char file_name[20], int matricule, int* BlockNB, int* PositionNB, int* exist);  //retourne le bloc, position de l'enregistrement s'il est trouve
void ModifyStudent(LOF_fileP f, char file_name[20], int matricule, StudentP student);   //modifier le contenue de l'enregistrement s'il existe



#endif