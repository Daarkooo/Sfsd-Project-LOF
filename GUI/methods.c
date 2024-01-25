#include "methods.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
        c = getchar();
} //fonction pour vider le flux d'entree

void printStudent(StudentP S) {

    printf("Name : %s", S->name);
    printf("Surname : %s", S->surname);
    printf("Matricule : %d \n\n" , S->matricule );
}


void studentCopy(StudentP S1, StudentP S2) {
    strcpy(S1->name, S2->name);
    // printf("Name v2---: %s", S2->name);
    strcpy(S1->surname, S2->surname);
    // printf("Surname v2---: %s", S2->surname);
    S1->matricule = S2->matricule;
    // printf("Matricule : %d \n\n" , S1->matricule );
    S1->deleted = S2->deleted;
} //copier le contenue de l'etudiant S2 dans l'etudiant S1

void createStudent(StudentP S) { 
    viderBuffer();
    printf("Name : ");
    fgets(S->name, sizeof(S->name), stdin);
    printf("Surname : ");
    fgets(S->surname, sizeof(S->surname), stdin); //fgets accepte les espaces
    printf("Matricule : ");
    scanf("%d", &S->matricule);
    S->deleted=0;
}

void printBlock(blockP S) {
    printf("\t-----Student Information-----\t\n");
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


LOF_fileP openLOF(LOF_fileP f, char file_name[],char open_mode) {
    f = malloc(sizeof(LOF_file));

    if (open_mode == 'o') {  // On ouvre le fichier en mode OLD 'o' (le fichier est ancien et existe deja)
        f->file = fopen(file_name, "rb+");
        if (f->file == NULL){
            return NULL;
        }
        f->header = malloc(sizeof(header));
        size_t elements_read = fread(f->header, sizeof(header), 1, f->file); // size_t returns the number of elemets read
        if (elements_read != 1) {
            fclose(f->file);
            free(f->header);
            printf("Error reading header from file\n");
            return NULL;
    }
        rewind(f->file);
    } else if (open_mode == 'n')
    {   // On ouvre le fichier en mode NEW 'n' (le fichier est nouveau et n'existe pas, on le cree et on initialise l'entete)
        f->file = fopen(file_name, "wb+");
        // Initialisation du header a zero
        f->header = malloc(sizeof(header));
        f->header->firstBlock = 0;
        f->header->lastBlock = 0;
        f->header->nbBlocks = 0;
        f->header->nbStudents = 0;
        fwrite(f->header, sizeof(header), 1, f->file);
    } else 
        printf("You choosed a wrong opening mode\n");
    return f;
}//ouvrir le fichier logique

void closeLOF(LOF_fileP f){
    rewind(f->file);   // position le curseur au debut de fichier
    fwrite(f->header, sizeof(header),1,f->file); // la sauvegarde du header dans le fichier physique
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

void printHeader(LOF_fileP f, char file_name[]){
    // Ouvrir le fichier 
    f = openLOF(f, file_name, 'o');

    // Verification d'ouverture du fichier 
    if (f->file == NULL) {
        printf("Erreur lors de l'ouverture du fichier");
        return;
    }

    // Lire l'entête à partir du fichier
    fread(f->header, sizeof(header), 1, f->file);

    // Afficher le contenu de l'entête
    printf("First Block: %d\n", f->header->firstBlock);
    printf("Last Block: %d\n", f->header->lastBlock);
    printf("Number of Blocks: %d\n", f->header->nbBlocks);
    printf("Number of Students: %d\n", f->header->nbStudents);

    closeLOF(f);
};  //afficher le contenue de l'entete

void writeBlock(LOF_fileP f, int K, blockP buffer) {
    fseek(f->file,sizeof(header)+((K-1)*sizeof(block)),SEEK_SET);
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


void allocBlock(LOF_fileP f, int* K, blockP* buffer) {
    *buffer = malloc(sizeof(block));
    (*buffer)->NB = 0;
    (*buffer)->svt = -1;
    *K = readHeader(f, 3) + 1;
    writeHeader(f, 3, *K);  //incrementer le nombre de bloc dans le fichier
    Student s;      //declaration d'un etudiant de type NULL sans aucune valeur
    s.deleted = 1;
    strcpy(s.name, " ");
    strcpy(s.surname, " ");
    s.matricule = 0;
    for (int i = 0; i < FACT_B; i++)
        (*buffer)->tab[i] = s; //initialiser toute les position du bloc avec un etudiant NULL
}   //allouer un nouveau bloc et l'initialiser avec le contenue du tampom



void extractLOF(LOF_fileP f, char file_name[], char result[]){
    f = openLOF(f, file_name, 'o');
    f->tabIndex = InitTabIndex(f);
    FILE* studentWriter = fopen(result, "w"); 
    int numBlock = readHeader(f, 1);
    int i;
    int k=0;
    int num;
    while (numBlock != -1)
    {
        readBlock(f, numBlock, buffer);
        if(buffer->NB !=0){
            int i = 0;
            int j = 0;
            int num=1;
            fprintf(studentWriter, "\n\t----------BLOCK %d----------\n", numBlock);
            while (i < FACT_B && j < buffer->NB)
            {
                if (buffer->tab[i].deleted == 0)
                {
                    fprintf(studentWriter, "Student %d:\n", num);
                    fprintf(studentWriter, "\tNOM : %s\n\tPRENOM : %s\n\tMATRICULE (cle) : %d\n", buffer->tab[i].name, buffer->tab[i].surname, buffer->tab[i].matricule); // Afficher les informations du i-ème étudiant
                    j++;
                    num++;
                }
                
                i++;
            }
            k++;
        }
        numBlock = buffer->svt;
    }
    fprintf(studentWriter, "\n------------- INDEX ARRAY CONTENT -----------\n");
    for(int i=0;i<k;i++){
        fprintf(studentWriter, "%d - blockID %d - lastKey %d\n", i, f->tabIndex[i].blockID, f->tabIndex[i].lastKey);
    }

    closeLOF(f);
    fclose(studentWriter);
}

StudentP scanTab(StudentP t, int length) {
    t = malloc(sizeof(Student) * length);
    printf("Entrez les informations des %d etudiants : \n", length);
    for (int i = 0; i < length; i++) {
        printf("Etudiant %d :\n", i+1);
        createStudent(t + i);
    }
    return t;
}   //creation du tableau

void quickSortTab(StudentP tab, int start, int end) {
    if (start >= end)
        return;
    
    int pivot = tab[end].matricule;
    int i = start - 1;
    Student temp;
    for (int j = start; j < end; j++)
    {
        if (tab[j].matricule < pivot)
        {
            i++;
            studentCopy(&temp, tab + i);
            studentCopy(tab + i, tab + j);
            studentCopy(tab + j, &temp);
        }
    }
    i++;
    studentCopy(&temp, tab + i);
    studentCopy(tab + i, tab + end);
    studentCopy(tab + end, &temp);
    quickSortTab(tab, start, i - 1);
    quickSortTab(tab, i + 1, end); 
}   //trier le tableau en ordre croissant du matricule (la cle)

IndexP InitTabIndex(LOF_fileP f){
    int nb = readHeader(f, 3);
    IndexP tabIndex = malloc(sizeof(Index)*nb);
    int blockNum = readHeader(f, 1);
    int k=0; // k em case de la tabindex
    while(blockNum!=-1)
    {
        buffer = malloc(sizeof(block));
        readBlock(f, blockNum, buffer);
        int i=0;
        int j=0;
        while (i < FACT_B ){
            if (buffer->tab[i].deleted == 0)
            {
                j++;
            }
            if(j == buffer->NB){
                break;
            }
            i++;
        }
        (tabIndex + k)->blockID=blockNum;
        if(buffer->NB!=0){
            printf("not empty \n\n");
            (tabIndex + k)->lastKey=buffer->tab[i].matricule;
        }else{
            if(k==0){
                (tabIndex + k)->lastKey=0;
                printf("empty with k == 0 \n\n");
            }
            else{
                (tabIndex + k)->lastKey=(tabIndex+ k-1)->lastKey+1;
                printf("empty with k != 0 \n\n");
            }
        }
        k++;
        blockNum = buffer->svt;
    }
    
    return tabIndex;
}

void writeIndexTab(LOF_fileP f, IndexP tab, int length, int nbBlocks) {
    fseek(f->file, sizeof(header) + (sizeof(block)*nbBlocks), SEEK_SET);
    fwrite(tab, sizeof(Index), length, f->file);
    rewind(f->file);
}  //mettre le contenue du tampon dans le bloc numero K

void readIndexTab(LOF_fileP f, IndexP tab, int length, int nbBlocks) {
    fseek(f->file, sizeof(header) + (sizeof(block)*nbBlocks), SEEK_SET);
    fread(tab, sizeof(Index), length, f->file);
    rewind(f->file);
}  //mettre le contenue du bloc numero K dans

void createLOF(LOF_fileP f, char file_name[], StudentP StudentTab, int N) {
    int k;
    blockP NewBuffer;
    //cas ou N == 0
    if (N == 0)
    {
        f =openLOF(f, file_name, 'n');
        allocBlock(f, &k, &buffer);
        writeHeader(f, 1, 1);
        writeHeader(f, 2, 1);
        writeHeader(f, 4, 0);
        writeBlock(f, 1, buffer);
        return;
    }

    quickSortTab(StudentTab, 0, N-1); //trier les N enregistrements selon la cle (QuickSort)
    
    //insertion des enregistrement en mode FIFO :
    f = openLOF(f, file_name, 'n');
    allocBlock(f, &k, &buffer);
    writeHeader(f, 1, k);
    writeHeader(f, 2, k);   //considerer le nouveau buffer comme firstBlock et lastBlock

    int i = 0;
    int j = 0;
    while (i < N && i < FACT_B )   //remplire le premier bloc
    {
        studentCopy((buffer->tab) + j, StudentTab + i);
        i++;
        j++;
    }

    while (i < N)
    {
        if (j < FACT_B )  //tester si le compteur est inferieur a 50% de la capacite max du bloc
        {
            studentCopy((buffer->tab) + j, StudentTab + i);  //on reste dans le meme bloc  
            j++;
        }
        else
        {
            buffer->NB = j--;
            int oldSVT = buffer->svt;   //sauvegarder l'ancier bloc
            allocBlock(f, &k, &NewBuffer);
            writeHeader(f, 2, k);   //allouer un nouveau bloc et l'affecter comme lastBlock
            buffer->svt = k;    //mettre a jour le champ svt
            writeBlock(f, oldSVT, buffer);  //ecrire buffer dans l'ancien emplacement sauvegarder precedemment
            readBlock(f, buffer->svt, buffer);
            studentCopy((buffer->tab), StudentTab + i);  //affecter S a la premiere case du nouveau buffer
            j = 1;
        }
        i++;
    }
    free(StudentTab);
    buffer->NB = j--;
    buffer->svt = -1;   //mettre le svt du dernier bloc a -1 (nil)
    writeBlock(f, k, buffer);    //ecriture du dernier buffer dans le fichier
    writeHeader(f, 4, N);   //nombre d'enregistrement dans le fichier

    closeLOF(f);    //fermer le fichier    
}     //creation du fichier avec N enregistrement logique (chargement initial a 60% de la capacité max du bloc)


void insertStudent(LOF_fileP f, char file_name[], StudentP student) {
    int find,findIt,i,j,position,n_block,x,mat=1;
    printHeader(f, file_name);
    blockP newBlock;
    f->tabIndex = InitTabIndex(f);

    f = openLOF(f,file_name,'o');

    SearchStudent(f,file_name,student->matricule,&i,&j,&find); // on cherche le matricule si il existe

    while (find) { // si il existe on boucle jusqu'a lustilisateur saisit un matricule qui n'existe pas
        printf("Ce matricule existe deja.\n");
        printf("donner un autre: \n");
        createStudent(student);
        SearchStudent(f,file_name,student->matricule,&i,&j,&find);
    }

    SearchInsertionPosition(f,file_name,student->matricule,&i,&j);
    printf("block num : %d , position : %d\n", i,j);
    
    
    if(j==-1){ // le cas ou on a depasse le dernier etudiant du dernier block
        studentCopy(newBlock->tab, student);
        newBlock->NB++; // ----------------
        n_block=readHeader(f,2);
        readBlock(f,n_block,buffer);
        writeBlock(f,x,newBlock);
        buffer->svt = x;
        writeBlock(f,n_block,buffer);
        writeHeader(f,2,x); 
        goto end;
    }
    else{ 
        readBlock(f,i,buffer);
        
        if(buffer->tab[j].deleted){ // si la case est deja suprime (concept logique)
            studentCopy((buffer->tab) + j, student); // mettre le contenu de student dans le buffer qui porte le contenu de la case j du block i
            buffer->NB++;
            writeBlock(f,i,buffer);
        }
        else{ 
            
            
            if(buffer->NB!=FACT_B){ // faire le daclage interblock (block isn't full)
                int nbBlocks = buffer->NB;
            
                for(int p=nbBlocks; p>j; p--){
                    if(buffer->tab[p-1].deleted==1){
                        continue;
                    }
                    buffer->tab[p]=buffer->tab[p-1];
                }        
                last:       
                studentCopy((buffer->tab)+j, student);
                // buffer->tab[];

                // if(nbBlocks == FACT_B ){
                //     printf("\n we are here student copy directly \n");
                //     studentCopy((buffer->tab)+nbBlocks, student);
                // }
                buffer->NB++;

                writeBlock(f,i,buffer);
                goto end;

            }
            

            else{ // // faire le decalge (en 2 moitie)
                allocBlock(f, &x, &newBlock);
                int m=FACT_B/2 ; // la case du millieu de i em block ( le -1 cuz we start from 0 not 1)
                
                if (j<=m){ // si la case ou on vas inserer se trouve dans la premier moitie
                    newBlock->tab[0]=buffer->tab[m]; // mettre student de la case m dans la premiere case du nv block
                    newBlock->NB++;
                    for(int p=m;p>j;p--){
                        if(buffer->tab[p-1].deleted==1){
                            continue;
                        }
                        buffer->tab[p]= buffer->tab[p-1]; // decalage 
                    }
                    studentCopy((buffer->tab) + j, student);
                        for(int p=1;p<=m;p++){
                            if(buffer->tab[p+m].deleted==1){
                                continue;
                            }
                            newBlock->tab[p]=buffer->tab[p+m]; // remplire le rest du nv block ave la 2em moitie du iem block
                            buffer->tab[p+m].deleted=1; // la case deplace dans le nv block on la supprime du i em block
                            buffer->NB--;
                            newBlock->NB++;
                        }

                }
            
                else{ // si la case ou on vas inserer se trouve dans la deuxieme moitie
                    int indexnv=j-m-1;
                    studentCopy((newBlock->tab) + indexnv, student); // mettre le nv student dans la nv block direct
                    newBlock->NB++;
                    int p2=m+1;
                    for(int p=0;p<=m;p++){
                        if(p==indexnv ){ // passer a la prochaine case cuz we have already put our new student here
                            continue;
                        }
                        if(buffer->tab[p2].deleted==1){
                            p2++;
                            continue;
                        }
                        newBlock->tab[p]=buffer->tab[p2]; //
                        buffer->tab[p2].deleted=1; // la case deplace dans le nv block on la supprime du i em block
                        buffer->NB--;
                        newBlock->NB++;
                        p2++;
                    }
                }
            }
            
            newBlock->svt=buffer->svt; // le nv block on le chaine avc le svt du i em block
            buffer->svt=x;  // le i em block on le chaine avc le nv block 
            writeBlock(f,x,newBlock);
            writeBlock(f,i,buffer);
            end:
            writeHeader(f,4,readHeader(f,4)+1);// ====  nmbr de students
        }
    }
    
    closeLOF(f);
}//insertion d'un novelle enregistrement dans le fichier


void SearchInsertionPosition(LOF_fileP f, char file_name[], int matricule, int* BlockNB, int* PositionNB){
    f = openLOF(f,file_name,'o');
    f->tabIndex = InitTabIndex(f);

        int i=0;
        int numbBlock = readHeader(f, 1);
        *BlockNB = numbBlock;
        while (numbBlock != -1)
        {
            readBlock(f, numbBlock, buffer);
            i=0;
            if(buffer->svt != -1){
                while (i<FACT_B)
                {
                    if(buffer->tab[i].matricule<matricule){
                        i++;
                    }
                    else
                    {
                        break;
                    }
                }
                if(i<FACT_B){ 
                    *BlockNB = numbBlock;
                    *PositionNB = i;
                    return;
                }else{
                    *BlockNB = numbBlock+1;
                    *PositionNB = 0;

                }
            }

            else{
               while (buffer->tab[i].matricule<matricule &&  buffer->tab[i].matricule != f->tabIndex[numbBlock-1].lastKey ){
                    i++;
                }
                if( buffer->tab[i].matricule<matricule && buffer->tab[i].matricule==f->tabIndex[numbBlock-1].lastKey){
                    i++;
                    *BlockNB = numbBlock;
                }
                if(i>=FACT_B){
                    i = -1;
                    *BlockNB = numbBlock+1;
                }
                *PositionNB = i;
                return;
            }
            
            numbBlock = buffer->svt;

        }
 
        
        printf("\npositionNB of insertion= %d\n\n", i+1);
        
    closeLOF(f);  // close the file
}



void DeleteStudent(LOF_fileP f, char file_name[], int matricule) {
    f = openLOF(f,file_name, 'o');
    if(readHeader(f,4)!=0){
        int n_bloc,position,find,x;
        f->tabIndex=InitTabIndex(f);
        SearchStudent(f, file_name, matricule,&n_bloc,&position,&find); // la recherche
        if(find){ 
            position--;
            readBlock(f,n_bloc,buffer); // lire le n_bloc
            buffer->tab[position].deleted=1; // deleted = true
            buffer->NB--; // decrementer le nbr d'enregistrmnt logic dans le n_bloc
            x = readHeader(f, 4); // lire le nbr d'etudiant
            x--; 
            writeHeader(f,4,x); // decrementer le nbr d'etudiant dns le header
            writeBlock(f,n_bloc,buffer); // saving

            f->tabIndex=InitTabIndex(f);
            printf("\nVous pouvez verifier la suppression dans votre fichier :\n");
        }else{  // doesn't exist
                printf("\nCe matricule n'existe pas. \n");
        }
    }
    else{
        printf("\nCe fichier est vide! la suppression est impossible!!\n");
    }
    closeLOF(f);  // close the file

    // int n_bloc,position,find,x;
    // if(f->file){
    //     SearchStudent(f, file_name, matricule,&n_bloc,&position,&find); // la recherche
    //     if(find){ // s'il existe
    //         f = openLOF(f,file_name,'o');
    //         readBlock(f,n_bloc,buffer); // lire le n_bloc
    //         buffer->tab[position].deleted=1; // deleted = true
    //         buffer->NB--; // decrementer le nbr d'enregistrmnt logic dans le n_bloc
    //         x = readHeader(f, 4); // lire le nbr d'etudiant
    //         x--; 
    //         writeHeader(f,4,x); // decrementer le nbr d'etudiant dns le header
    //         writeBlock(f,n_bloc,buffer); // saving
    //         closeLOF(f);  // close the file
    //     }else{  // doesn't exist
    //         printf("ce matricule n'existe pas.");
    //     }
    // }
} //suppression de l'enregistrement si il existe


void SearchStudent(LOF_fileP f, char file_name[], int matricule, int* blockNB, int* positionNB, int* exist) {
    f = openLOF(f,file_name,'o');
    f->tabIndex = InitTabIndex(f);  //initialisation du tableau d'index
    *exist = 0; // Initialisation n'existe pas
    *blockNB = 0;
    *positionNB = 0;
    if (readHeader(f, 4) != 0)  //verfier si le fichier contient des etudiants
    {
        int start = 0;
        int end = readHeader(f, 3) - 1;
        while ((end - start) > 1 && !(*exist)) {    //tant que taille(tab) > 2 cases
            int m = (start + end) / 2;
            if (f->tabIndex[m].lastKey == matricule)    //la dernier cle du bloc est la cle qu'on cherche
            {
                *exist = 1;
                *blockNB = f->tabIndex[m].blockID;
                readBlock(f, *blockNB, buffer);
                int i = 0;
                while (i < FACT_B)
                {
                    if (buffer->tab[i].deleted == 0 && buffer->tab[i].matricule == matricule)
                        *positionNB = i + 1;
                    i++;
                }
            } else if (f->tabIndex[m].lastKey < matricule)  //la dernier cle du bloc est inferieur, on cherche dans les blocs suivants
            {
                start = m;
            } else {    //la dernier cle du bloc est superieur, on cherche dans les blocs precedents
                end = m;
            }
        }
        if (*exist == 0)    //si la cle qu'on cherche n'est pas la derniere valeur de son bloc
        {
            readBlock(f, f->tabIndex[end].blockID, buffer); //on cherche dans tab[fin]
            int i = 0;
            int j = 0;
            while (i < FACT_B && j < buffer->NB)
            {
                if (buffer->tab[i].deleted == 0) {
                    if (buffer->tab[i].matricule == matricule)
                    {
                        *exist = 1;
                        *blockNB = f->tabIndex[end].blockID;
                        *positionNB = i + 1;
                    }
                    j++;
                }
                i++;
            }
            if (start != end && *exist == 0)
            {
                readBlock(f, f->tabIndex[start].blockID, buffer); //si taille(tab = 2), et qu'on trouve pas dans tab[fin], on cherche dans tab[debut]
                i = 0;
                j = 0;
                while (i < FACT_B && j < buffer->NB)
                {
                    if (buffer->tab[i].deleted == 0) {
                        if (buffer->tab[i].matricule == matricule)
                        {
                            *exist = 1;
                            *blockNB = f->tabIndex[start].blockID;
                            *positionNB = i + 1;
                        }
                        j++;
                    }
                    i++;
                }
            }
        }
    }
    closeLOF(f);  // close the file
}  //retourne le bloc, position de l'enregistrement s'il est trouve

void ModifyStudent(LOF_fileP f, char file_name[] , StudentP student) {
    f = openLOF(f,file_name,'o');
    f->tabIndex = InitTabIndex(f);
    //les declaration necessaires pou la fonction de recherche
    int blockNum, positionNB;
    int exist;
    if(readHeader(f, 4) != 0){
        SearchStudent(f, file_name, student->matricule, &blockNum, &positionNB, &exist);//la recherche de l'etudiant si il exist ainsi ca position et le numero de bloc
        if (exist==1) {
            readBlock(f, blockNum, buffer); // mettre le contenue le buffer dans le fichier f
            studentCopy((buffer->tab) + positionNB-1, student);   //mettre les informations de student dans l'etudiant numero positionNB dans le buffer
            writeBlock(f, blockNum, buffer);    //mettre les nouvelles informations insserer dans le buffer dans le fichier f
        }else{
            printf("student doesn't exist!\n");
        }
    }else{
        printf("your file is empty, 0 student\n");
    }
    closeLOF(f);  // close the file
}   //modifier le contenue de l'enregistrement s'il existe
