#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {

    char *filename = argv[1];
    char *type_newstudent = argv[2];
    char *data1 = argv[3];
    char *data2 = argv[4];
    int i = 0;
    FILE *forigin;
    forigin = fopen(filename,"r+");

    STUDENT newstudent;
    
    while(fread(&newstudent, sizeof(newstudent),1,forigin) ){
        i++;
            if(strcmp(type_newstudent,"name")==0){
                if(strcmp(newstudent.name, data1)==0){
                    printf("%s %s %d %d ", newstudent.name,newstudent.lastname,newstudent.id,newstudent.semestre);
                    printf("cambiado por: ");
                    strcpy(newstudent.name , data2);
                    fseek(forigin, -1* sizeof(newstudent), SEEK_CUR);
                    fwrite(&newstudent,sizeof(newstudent),1,forigin);
                    printf("%s %s %d %d \n", newstudent.name,newstudent.lastname,newstudent.id,newstudent.semestre);
                }   
                else{
                    printf("Error: no se encontró el nombre en el alumno %d\n", i);
                }
            }
            else if (strcmp(type_newstudent,"lastname")==0){

                if(strcmp(newstudent.lastname, data1)==0){
                    printf("%s %s %d %d ", newstudent.name,newstudent.lastname,newstudent.id,newstudent.semestre);
                    printf("cambiado por: ");
                    strcpy(newstudent.lastname , data2);
                    fseek(forigin, -1* sizeof(newstudent), SEEK_CUR);
                    fwrite(&newstudent,sizeof(newstudent),1,forigin);
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

                if(strcmp(st, data1)==0){
                    printf("%s %s %d %d ", newstudent.name,newstudent.lastname,newstudent.id,newstudent.semestre);
                    printf("cambiado por: ");
                    newstudent.id = atoi(data2);
                    fseek(forigin, -1* sizeof(newstudent), SEEK_CUR);
                    fwrite(&newstudent,sizeof(newstudent),1,forigin);
                    printf("%s %s %d %d \n", newstudent.name,newstudent.lastname,newstudent.id,newstudent.semestre);
                }
                else{
                    printf("Error: no se encontró el semestre en el alumno %d\n", i);
                }
            } 
            else if(strcmp(type_newstudent,"semestre")==0){
                char st[20];
                sprintf(st, "%d", newstudent.semestre);
                
                if(strcmp(st,data1)==0){
                    printf("%s %s %d %d ", newstudent.name,newstudent.lastname,newstudent.id,newstudent.semestre);
                    printf("cambiado por: ");
                    newstudent.semestre= atoi(data2);
                    fseek(forigin, -1* sizeof(newstudent), SEEK_CUR);
                    fwrite(&newstudent,sizeof(newstudent),1,forigin);
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