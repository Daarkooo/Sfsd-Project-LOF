#include <stdio.h>
#include <stdlib.h>

int main(){
 /* FILE *binaryFile = fopen("test.txt", "wb");
    if (binaryFile){
        double x[5] ={5.3,6.3,2.6,7.5,1.2};
        fwrite(&x, sizeof(double), 5, binaryFile);
        fclose(binaryFile);
    }else{
        printf("error opening");
    }
    return 0; */
    FILE *binaryFile = fopen("test.txt", "rb");
    if (binaryFile){
        double y[5];
        fread(y, sizeof(double), 3, binaryFile);   
        for (int i=0; i<5; i++){
            printf("%.1f\n", y[i]);
        }
    }else{
        printf("error opening");
    }
}