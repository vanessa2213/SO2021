#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main(int argvnum, char **argv){
    char *arch1 = argv[1]; 
    char *arch2 = argv[2];
    struct stat sb1;
    struct stat sb2;
    if(stat(arch1, &sb1) == -1){        //Si el archivo 1 no existe
        printf("Error el archivo no existe \n");
        return -1;
    }
    else{                               //Si el archivo 1 si existe
        if(S_ISREG(sb1.st_mode)){       //si el archivo 1 es un archivo normal 
            if(stat(arch2, &sb2) == -1){        //si el archivo 2 no existe
                link(arch1,  arch2);            //cambia de nombre el archivo 1 por el archivo 2 creando un nuevo archivo
                unlink(arch1);                  //borra el archivo 1
            }
            
            else{                       //si el archivo 2 ya existe
                if(S_ISREG(sb2.st_mode)){       //si el archivo 2 es un archivo normal
                    printf("Error el archivo 2 ya existe \n");
                    return -1;
                }
                if(S_ISDIR(sb2.st_mode)){       //si el archivo 2 es un directorio
                    printf("Archivo 2 es un directorio \n");
                    link(arch2, arch1);         //mover el archivo 1 al directorio
                    //unlink(arch1);              //borrar el archivo del directorio original
                } 
            }
        }
    }
      
    return 1;
}

