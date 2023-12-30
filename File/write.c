#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *myFile = fopen("test.txt", "w"); // in path u can put the folder name of the project/..... or absolute path
    // FILE *myFile = fopen("test2.txt", "a"); // a = append 
    if (myFile){ // if (myFile != NULL)
        int x=6;
        float y =4.6;
        // fputc('n', myFile);
        // fputc('o', myFile);
        fputs("Yo wsup!\n", myFile); // puts == printf

        fprintf(myFile, "the value of x = %d, the value of y = %.2f\n", x,y);
        
        fclose(myFile);
        fputs("test\n", myFile); // not added 

    } else { 
        printf("Error opening");
    }
}
