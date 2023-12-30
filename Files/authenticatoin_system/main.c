// using binary files

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char lastName[30],firstName[30],email[30],pswrd[30];
}ID;


int main(){
    int c;
    FILE *file = fopen("user.dat","ab");
    printf("1 - sign up\n");
    printf("2 - sign in\n");
    printf("Pick your choice: ");
    do
    {
        scanf("%d",&c);
        if(c!=1 && c!=2){
            printf("Please enter a valid choice (1-2): ");
        }
    } while (c!=1 && c!=2);
    ID user;
    getchar(); // for duplicate printing 
    if (c==1){
        printf("Enter your first name: ");
        fgets(user.firstName,30,stdin); // stdin is a predefined file stream associated with the standard input device, typically the keyboard
        printf("Enter your last name: ");
        fgets(user.lastName,30,stdin);
        printf("Enter your email: ");
        fgets(user.email,30,stdin);
        printf("Enter your password: ");
        fgets(user.pswrd,30,stdin);
        if(file){
            fwrite(&user,sizeof(user),1,file);
            printf("you have successfully registered.\n");
        }else{
            printf("opening error file");
        }
    }

    if(c==2){
        char email[30],psw[30];
        printf("Enter your email: ");
        fgets(email,30,stdin);
        printf("Enter your password: ");
        fgets(psw,30,stdin);
        FILE *file = fopen("user.dat", "rb");
        if (file){
            ID user;
            int find = 0;
            while(!feof(file)){
                fread(&user,sizeof(user),1,file);
                if(!strcmp(user.email,email) && !strcmp(user.pswrd,psw)){
                    find = 1;
                    break;
                }
            }
            if(find){
                printf("Welcome name lastname\n",user.firstName,user.lastName);
            }else{
                printf("Error, email or password are incorrect");
            }    
        }else{
            printf("opening error file");
        }
        
    }

    fclose(file);

    return 0;
}