#include "methods.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void printStudent(StudentP S) {

    printf("Name : %s", S->name);
    printf("Surname : %s", S->surname);
    printf("Matricule : %d \n\n" , S->matricule );

}

void studentCopy(StudentP S1, StudentP S2) {
    strcpy(S1->name, S2->name);
    strcpy(S1->surname, S2->surname);
    S1->matricule = S2->matricule;
    S1->deleted = S2->deleted;
} //copier le contenue de l'etudiant S2 dans l'etudiant S1

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
    printf("enter the numbre of students in this block : ");
    scanf("%d",&S->NB);
    printf("\n");
    for(int i=0 ; i<(S->NB) ; i++){
        printf("enter information for student numbre %d : \n",i+1);
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

void closeLOF(LOF_fileP f){
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
    fwrite(buffer,sizeof(block),1,f->file);
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
    buffer = malloc(sizeof(block));
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



void scanTab(StudentP t, int length) {
    t = malloc(sizeof(Student) * length);
    printf("Entrez les informations des %d etudiants : \n", length);
    for (int i = 0; i < length; i++) {
        printf("Etudiant %d :\n", i+1);
        createStudent(t + i);
    }
}   //creation du tableau

void quickSortTab(StudentP tab, int start, int end) {
   if (start >= end)
        return;
    
    int pivot = tab[end].matricule;
    int i = start - 1;
    int temp;
    for (int j = start; j < end; j++)
    {
        if (tab[j].matricule < pivot)
        {
            i++;
            temp = tab[i].matricule;
            tab[i].matricule = tab[j].matricule;
            tab[j].matricule = temp;
        }
    }
    i++;
    temp = tab[i].matricule;
    tab[i].matricule = tab[end].matricule;
    tab[end].matricule = temp;
    quickSort(tab, start, i - 1);
    quickSort(tab, i + 1, end); 
}   //trier le tableau en ordre croissant du matricule (la cle)



void createLOF(LOF_fileP f, char file_name[20], int N) {
    StudentP StudentTab;  //*t est le tableau a remplire dés la lecture initial
    int k, BlockNB = 0;
    openLOF(f, file_name, 'w');
    allocBlock(f, &k, buffer);
    BlockNB++;
    buffer->svt = -1;
    writeHeader(f, 1, k);
    writeHeader(f, 2, k);
    int j = 0;
    scanTab(StudentTab, N); //scanner les N enregistrements
    quickSortTab(StudentTab, 0, N-1); //trier les N enregistrements selon la cle (QuickSort)
    //insertion des enregistrement en mode LIFO
    for (int i = N - 1; i >= 0; i--)
    {
        if (j <= MAX_E * LoadFact)  //tester si le compteur est inferieur a 60% de la capacite max du bloc
        {
            studentCopy((buffer->tab) + j, StudentTab + i);  //on reste dans le meme bloc  
            j++;
        }
        else
        {
            buffer->NB = j--;
            writeBlock(f, readHeader(f, 1), buffer);    //ecrire le buffer dans le fichier
            allocBlock(f, &k, buffer);
            BlockNB++;  //incrementer le nombre de bloc apres chaque allocation
            buffer->svt = readHeader(f, 1); //nouveau buffer pointe sur le bloc tete du fichier
            writeHeader(f, 1, k);   //nouveau buffer devient le nouveau bloc tete
            studentCopy((buffer->tab), StudentTab + i);  //affecter S a la premiere case du nouveau buffer
            j = 1;
        }
    }
    free(StudentTab);
    buffer->NB = j--;
    writeBlock(f, readHeader(f, 1), buffer);    //ecriture du dernier buffer dans le fichier
    writeHeader(f, 1, k);   //le nouveau buffer devient le bloc tete
    writeHeader(f, 3, BlockNB); //nombre de bloc allouer durant la creation
    writeHeader(f, 4, N);   //nombre d'enregistrement dans le fichier
    closeLOF(f);    //fermer le fichier
}     //creation du fichier avec N enregistrement logique (chargement initial a 60% de la capacité max du bloc)

void insertStudent(LOF_fileP f, char file_name[20], StudentP student) {

}  //insertion d'un novelle enregistrement dans le fichier

void DeleteStudent(LOF_fileP f, char file_name[20], int matricule) {

} //suppression de l'enregistrement si il existe

void SearchStudent(LOF_fileP f, char file_name[20], int matricule, int* BlockNB, int* PositionNB, int* exist) {

*exist = 0; // Initialisation n'exist pas
    if(readHeader(f, 4) != 0){
        int blockNum = readHeader(f, 1);    //initialiser avec le numero du premier bloc
        while (blockNum != -1) {
            readBlock(f, blockNum, buffer); // mettre le contenue de fichier f dans un buffer
            for (int i = 0; (i < MAX_E); i++) {
                if( buffer->tab[i].deleted != 1)
                    continue;

                if ((buffer->tab[i].matricule == matricule)) {
                    *BlockNB = blockNum;
                    *PositionNB = i;    //la position de bloc numero i
                    *exist = 1; // Student exists
                    return;
                }
            }
            blockNum = buffer->svt; //le numero de bloc suivant
        }   //verification de tout les "students" dans un bloc
    }   //verification de tout les blocs
}  //retourne le bloc, position de l'enregistrement s'il est trouve

void ModifyStudent(LOF_fileP f, char file_name[20], int matricule, StudentP student) {
    //les declaration necessaires pou la fonction de recherche
    int blockNum, positionNB;
    int exist;
    if(readHeader(f, 4) != 0){
        SearchStudent(f, file_name, matricule, &blockNum, &positionNB, &exist);//la recherche de l'etudiant si il exist ainsi ca position et le numero de bloc

        if (exist==1) {
            readBlock(f, blockNum, buffer); // mettre le contenue le buffer dans le fichier f
            studentCopy((buffer->tab) + positionNB, student);   //mettre les informations de student dans l'etudiant numero positionNB dans le buffer
            writeBlock(f, blockNum, buffer);    //mettre les nouvelles informations insserer dans le buffer dans le fichier f
        }
    }
}   //modifier le contenue de l'enregistrement s'il existe
