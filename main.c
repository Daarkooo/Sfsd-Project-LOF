#include <stdio.h>
#include <stdlib.h>
#include"methods.h"
#include"methods.c"

int main(){
   blockP S = malloc(sizeof(block));
    StudentP sp = malloc(sizeof(Student));

    //createStudent(sp);
    //printStudent(sp);
    createBlock(S);
    printBlock(S);

    return 0;
}
