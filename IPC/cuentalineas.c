#include <unistd.h>
#include <ctype.h>
#include <stdio.h>
int main(){
    int count = 1;
    char minC;
    while(read(0,&minC,1)){
        if (minC == '\n'){
            count++;
        }
    }
    printf("Lineas:%d\n",count);
    return 0;
}