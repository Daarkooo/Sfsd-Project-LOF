#include <stdlib.h>
#include <stdio.h>

int main(){
    FILE *myFIle = fopen("test.txt", "r");
    if(myFIle){ 

        // fgetc
    /*  char c;
        c= fgetc(myFIle);
        printf("%c", c);// here printing the 1 character
        c= fgetc(myFIle);
        printf("%c", c);// here printing the 2 character
        fclose(myFIle); */

        // fgets
    /*  char s[100];
        fgets(s, 3, myFIle); // every string has a special character at the end '/o' so the leng= length(string) + 1
        // in this example will print only the 2 first characters (the 3 character = '/o)
        printf("%s", s);  */

        // fscanf
    /*  int j,m,a;
        fscanf(myFIle, "%d/%d/%d", &j, &m, &a);  // 20/10/2024
        printf("j = %d, m = %d, a = %d\n", j, m, a);  */

        // feof() the end of the file
        char s[100];
        while (!feof(myFIle))  // printing line by line until the end (feof)
        {
            fgets(s, 100,myFIle);
            // if (feof(myFIle)) break; in case the last line got printed twice
            printf("%s",s);
        }  

    /*  char c;  // print character by character until the end (feof)
        while (!feof(myFIle))
        {
            c=fgetc(myFIle);
            printf("%c",c);
        }  */
        
        fclose(myFIle);

    }else{
        printf("error opening)\n");
    }
}