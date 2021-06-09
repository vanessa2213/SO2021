
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    char *filename = argv[1];
    int desplazamientos = atoi(argv[2]);

    FILE *forigin;
    forigin = fopen(filename,"rb");
    char message[100], ch;
    int i;

    while( fread(&ch,sizeof(char),1,forigin) ) {
        
        
        if(ch >= 'a' && ch <= 'z'){
            ch = ch + desplazamientos;
            if(ch > 'z'){
                ch = ch - 'z' + 'a' - 1;
            }
            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch + desplazamientos;
            if(ch > 'Z'){
                ch = ch - 'Z' + 'A' - 1;
            }
            message[i] = ch;  
        
        }
        else if( ch == '\n'){
            message[i] = '\n'; 
        }
        i++;
        // printf("Encrypted message: %s \n", message);
    }
    printf("Encrypted message: %s \n", message);
    
    fclose(forigin);
    return 0;
  
}