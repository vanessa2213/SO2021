#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main(int argvnum, char **argv){
    char *path = argv[1]; 
    struct stat sb;
    if(stat(path, &sb) == -1){
        printf("Error el archivo no existe \n");
        return -1;
    }
    if(S_ISDIR(sb.st_mode)){
        printf("Es un directorio \n");
    } 
    if(S_ISREG(sb.st_mode)){
        printf("Es un archivo normal \n");
    }  
    return 1;
}

