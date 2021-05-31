#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {

    char *filename = argv[1];
    char *type_newstudent = argv[2];
    char *data = argv[3];
    int i = 0;
    FILE *forigin;
    forigin = fopen(filename,"rb");

    STUDENT newstudent;
    
    while(fread(&newstudent, sizeof(newstudent),1,forigin) ){
        i++;
            if(strcmp(type_newstudent,"name")==0){
                if(strcmp(newstudent.name, data)==0){
                    printf("%s %s %d %d \n", newstudent.name,newstudent.lastname,newstudent.id,newstudent.semestre);
                }   
                else{
                    printf("Error: no se encontró el nombre en el alumno %d\n", i);
                }
            }
            else if (strcmp(type_newstudent,"lastname")==0){

                if(strcmp(newstudent.lastname, data)==0){
                    printf("%s %s %d %d \n", newstudent.name,newstudent.lastname,newstudent.id,newstudent.semestre);
                }
                else{
                    printf("Error: no se encontró el apellido en el alumno %d\n", i);
                }
                
            }  
            else if(strcmp(type_newstudent,"id")==0){
                char st[20];
                sprintf(st, "%d", newstudent.id);
                //printf("%s & %s \n", st, data);

                if(strcmp(st, data)==0){
                    printf("%s %s %d %d \n", newstudent.name,newstudent.lastname,newstudent.id,newstudent.semestre);
                }
                else{
                    printf("Error: no se encontró el semestre en el alumno %d\n", i);
                }
            } 
            else if(strcmp(type_newstudent,"semestre")==0){
                char st[20];
                sprintf(st, "%d", newstudent.semestre);
                
                if(strcmp(st,data)==0){
                    printf("%s %s %d %d \n", newstudent.name,newstudent.lastname,newstudent.id,newstudent.semestre);
                }
                else{
                    printf("Error: no se encontró el id en el alumno %d\n", i);
                }
            } 
            else{
                printf("Error: no se encontró el atributo\n");
                break;
            }
    }

    
    fclose(forigin);

}