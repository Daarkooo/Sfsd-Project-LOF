#include "methods.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void printStudent(StudentP S) {

    printf("Name : %s", S->name);
    printf("Surname : %s", S->surname);
    printf("Matricule : %d \n\n" , S->matricule );

}

void createStudent(StudentP S) { 
    char ch[5];
    fgets(ch, sizeof(ch), stdin);
    printf("Name : ");
    rewind(stdin);
    fgets(S->name, sizeof(S->name), stdin);
    printf("Surname : ");
    rewind(stdin);  //reinitialiser le tampon stdin
    fgets(S->surname, sizeof(S->surname), stdin); //fgets accepte les espaces
    printf("Matricule : ");
    scanf("%d", &S->matricule);
    S->deleted=0;
}

void printBlock(blockP S) {
    printf("\n\t-----Student Information-----\t\n");
    for (int i = 0; i < S->NB; i++) {
        printf("Student %d: \n", i + 1);
        printStudent((S->tab) + i);//afficher les information de le i eme etudiant
    }
    
} // afficher un block

void createBlock(blockP S) {
    printf("enter the number of students in this block : ");
    scanf("%d",&S->NB);
    printf("\n");
    for(int i=0 ; i<(S->NB) ; i++){
        printf("enter information for student number %d : \n",i+1);
        createStudent((S->tab) + i);
    }

}


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
    fread(f->header,sizeof(header),1,f->file); // la sauvegarde de l'entete de file dans header
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
    switch (K)
    {
    case 1:
        return f->header->firstBlock;
        break;
    case 2:
        return f->header->lastBlock;
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

void printHeader(LOF_fileP f, char file_name[20]){
 // Ouvrir le fichier 
    f->file = fopen(file_name, "rb");

    // Verification d'ouverture du fichier 
    if (f->file == NULL) {
        printf("Erreur lors de l'ouverture du fichier");
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

void writeBlock(LOF_fileP f, int K, blockP buffer) {
    fseek(f->file,sizeof(header)+((K-1)*sizeof(blockP)),SEEK_SET);
    fwrite(buffer,sizeof(blockP),1,f->file);
    rewind(f->file); // on se repositionne au debut de fichier 
}  //mettre le contenue du tampon dans le bloc numero K

void readBlock(LOF_fileP f, int K, blockP buffer){

    // Se deplacer a la position du bloc dans le fichier
    fseek(f->file, sizeof(header) + (K-1) * sizeof(block), SEEK_SET);
    // Lire le contenu du bloc dans le buffer
    fread(buffer, sizeof(block), 1, f->file);
    // on se repositionne au debut de fichier 
    rewind(f->file); 
};  //mettre le contenue du bloc numero K dans le buffer


void allocBlock(LOF_fileP f, int* K, blockP buffer) {
    buffer=malloc(sizeof(block));
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

void printLOF(LOF_fileP f, char file_name[20]){
  // Ouvrir le fichier 
    f->file = fopen(file_name, "rb");

    // Vérifier si l'ouverture du fichier a réussi
    if (f->file == NULL) {
        printf("Erreur lors de l'ouverture du fichier");
        return;
    }

    int blockNum = f->header->firstBlock;   // initialiser avec le numero du premier bloc
    
    while (blockNum != -1)
    {
        readBlock(f, blockNum, buffer);
        for (int i = 0; i < buffer->NB; i++) {
        printf("Block %d - Student %d:\n", blockNum, i + 1);
            printStudent((buffer->tab) + i); // Afficher les informations du i-ème étudiant
        }
        printf("\n");
        blockNum = buffer->svt;
    }
    
    // Fermer le fichier
    fclose(f->file);
}



void InitialLoading(char file_name[20]) {

}    //fonction de chargement initial car le fichier est ordonne



void createLOF(LOF_fileP f, char file_name[20], int N) {

}     //creation du fichier avec N enregistrement logique

void insertStudent(LOF_fileP f, char file_name[20], StudentP student) {
    int find,findIt,i,j,position,n_block,x,mat=1;
    blockP newBlock;

    openLOF(file_name,file_name,"r");
    // si le fichier existe
    SearchStudent(f,file_name,student->matricule,&i,&j,&find); // on cherche le matricule si il existe
    while (find) { // si il existe on boucle jusqu'a lustilisateur saisit un matricule qui n'existe pas
        printf("Ce matricule existe deja.\n");
        printf("donner un autre: ");
        createStudent(student);
        SearchStudent(f,file_name,student->matricule,&i,&j,&find);
    }
    SearchInsertionPosition(f,file_name,student->matricule,&i,&j);
    
    if(j==-1){ // le cas ou on a depasse le dernier etudiant du dernier block
        allocBlock(f,&x,newBlock); // allouer a nv block
        newBlock->tab[0] = student;
        n_block=readHeader(f,2);
        readBlock(f,n_block,buffer);
        buffer->svt = x;
        writeBlock(f,x,newBlock);
        writeHeader(f,2,x); // ====
        writeHeader(f,3,readHeader(f,3)+1); // mise a jour du header nmbr de blocks
        writeHeader(f,4,readHeader(f,4)+1);// ====  nmbr de students
    }else if (j==0 && i==readHeader(f,1)){ // le nv etudiant sera dans "la tete de liste"
        allocBlock(f,&x,newBlock);
        newBlock->table[0]=
        n_block=readHeader(f,1);
        readBlock(f,n_block,buffer);
        newBlock ->svt = readHeader(f,1);  // nv block -> premier block
        writeBlock(f,x,newBlock);
        writeHeader(f,1,x);
        writeHeader(f,3,readHeader(f,3)+1); // mise a jour du header nmbr de blocks
        writeHeader(f,4,readHeader(f,4)+1);// ====  nmbr de students
        allocBlock(f,&x,newBlock);
    }else{
        allocBlock(f,&x,newBlock);
        readBlock(f,i,buffer);
        if(buffer->tab[j].deleted){
            buffer->tab[j]=student;
            writeBlock(f,i,buffer);
            writeHeader(f,4,readHeader(f,4)+1);
        }else{
            for(int p=0;p<MAX_E;p++){
                // next time :)
            }
        }

    }
      //insertion d'un novelle enregistrement dans le fichier
}
/*void insertionAction(LOF_fileP f,int x, int n_block,blockP buffer,blockP newBlock, int act){
    allocBlock(f,&x,newBlock); // allouer a nv block
    n_block=readHeader(f,act);
    readBlock(f,n_block,buffer);
    buffer->svt = x;
    writeBlock(f,x,newBlock);
    writeHeader(f,act,x); // ====
    writeHeader(f,3,readHeader(f,3)+1); // mise a jour du header nmbr de blocks
    writeHeader(f,4,readHeader(f,4)+1);// ====  nmbr de students
}*/  // for reducing the ammount of code lines

void SearchInsertionPosition(LOF_fileP f, char file_name[20], int matricule, int* BlockNB, int* PositionNB){
    if((readHeader(f,4))!=0){
        int blockNum = readHeader(f,4);//initialiser avec le numero du premier bloc
        while (blockNum != -1) {
            readBlock(f, blockNum, buffer); // mettre le contenue de fichier f dans un buffer
            for (int i = 0; (i < MAX_E); i++) {
                if(buffer->tab[i].matricule > matricule ){ // trouver un matricule inferieur 
                    while (i>0){
                        if(buffer->tab[i].deleted==0){ //  trouver la case supprimer (elle se trouve aprs le precedent etudint dans la vrai liste)
                            break;
                        }
                        i--;
                    }
                    *BlockNB = blockNum;
                    *PositionNB = i;
                    break;
                } 
            }
            if(buffer->svt==-1){
                *PositionNB = -1; // dans le cas ou on a depasse le dernier etudiant du dernier block 
            }   
            blockNum = buffer->svt;//le numero de bloc suivant
        }   
    }//verification de tout les blocs 
}// la recherche de la position ideale pour l'insertion


void DeleteStudent(LOF_fileP f, char file_name[20], int matricule) {
    int n_bloc,position,find,x;
    if(f->file){
        SearchStudent(f, file_name, matricule,&n_bloc,&position,&find); // la recherche
        if(find){ // s'il existe
            openLOF(f,file_name,"r");
            readBlock(f,n_bloc,buffer); // lire le n_bloc
            buffer->tab[position].deleted=1; // deleted = true
            buffer->NB--; // decrementer le nbr d'enregistrmnt logic dans le n_bloc
            x = readHeader(file_name,4); // lire le nbr d'etudiant
            x--; 
            writeHeader(f,4,x); // decrementer le nbr d'etudiant dns le header
            writeBlock(f,n_bloc,buffer); // saving
            closeLOF(f,file_name);  // close the file
        }else{  // doesn't exist
            printf("ce matricule n'existe pas.");
        }
    }
} //suppression de l'enregistrement si il existe



void SearchStudent(LOF_fileP f, char file_name[20], int matricule, int* BlockNB, int* PositionNB, int* exist) {

*exist = 0; // Initialisation n'exist pas
if(f->header->nbStudents!=0){


    int blockNum = f->header->firstBlock;//initialiser avec le numero du premier bloc
    while (blockNum != -1) {
        readBlock(f, blockNum, buffer); // mettre le contenue de fichier f dans un buffer
        for (int i = 0; (i < MAX_E); i++) {
            if( buffer->tab[i].deleted!=1){
                continue;
            }
            if ((buffer->tab[i].matricule == matricule)) {
                
            
                *BlockNB = blockNum;
                *PositionNB = i;//la position de ploc numero i
                *exist = 1; // Student exist
                return;
            }
            }
            blockNum = buffer->svt;//le numero de bloc suivant
        }//verification de tout les "students" dans un bloc
         
        
    }//verification de tout les blocs 
}  //retourne le bloc, position de l'enregistrement s'il est trouve

void ModifyStudent(LOF_fileP f, char file_name[20], int matricule, StudentP student) {
    //les declaration necessaires pou la fonction de recherche
  int blockNum, positionNB;
    int exist;
    if(f->header->nbStudents!=0){
    SearchStudent(f, file_name, matricule, &blockNum, &positionNB, &exist);//la recherche de l'etudiant si il exist ainsi ca position et le numero de bloc

    if (exist==1) {
       
        readBlock(f, blockNum, buffer);// mettre le contenue le buffer dans le fichier f
        buffer->tab[positionNB] = *student;//mettre les informations de student dans l'etudiant numero positionNB dans le buffer
        writeBlock(f, blockNum, buffer);//mettre les nouvelles informations insserer dans le buffer dans le fichier f
    } 
    }
}   //modifier le contenue de l'enregistrement s'il existe
