/*
Proyecto Pipes
26/04/2021

El programa de este proyecto te permitirá calcular el promedio de una función de una variable, en un rango. 
La salida del programa es el promedio de los puntos evaluados en la función. Para terminar el programa hay 
que indicar que no hay más datos que procesar, es decir,  presionar Ctrl + C. 

Group 3
José Luis Jiménez Arévalo  A01633245
Perla Vanessa Jaime Gaytán A00344428

*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>

void signalHandler(int sig);

pid_t child_PID, parent_PID;

// from parent to child, parent write, child read
int pp2c[2];
// from child to parent, child write, parent read
int pc2p[2];

int sig17 = 0;
int sig2 = 0;

void signalHandler(int sig){
    
	if(sig == 17 ){
        printf("\nRecibí señal de que el hijo termino...\n");
		sig17 = 1;
        if(sig2 == 1){
            printf("Terminando . . .\n");
            exit(0);
            
        }
        
	}
    else if(sig == 2){
        printf("\nRecibí señal Ctrl + C...\n");
        sig2 = 1;
        if(sig17 == 1){
            printf("Terminando . . .\n");
            exit(0);
            
        }
    }

}
int main()
{
    // from parent to child, parent write, child read
    int pp2c[2];
    // from child to parent, child write, parent read
    int pc2p[2];

    pipe(pp2c);
    pipe(pc2p);

    switch (fork()) {
        case -1: // fork failed
            break;
        case 0: // child
            // connect pp2c to stdin
            close(pp2c[1]);
            dup2(pp2c[0], STDIN_FILENO);
            close(pp2c[0]);
            // connect pc2p to stdout
            close(pc2p[0]);
            dup2(pc2p[1], STDOUT_FILENO);
            close(pc2p[1]);

            // exec "bc -l"
            execl("/usr/bin/bc","bc","-l", (char*)NULL);
          break;
        default: // parent
            // close unnecessary pipes
            close(pp2c[0]);
            close(pc2p[1]);
            // open pipes as stream
           // this is need to use fprintf/scanf to write/read from the pipes
            FILE *out = fdopen(pp2c[1], "w");
            FILE *in = fdopen(pc2p[0], "r");

            char function[64];
            int x[3], a, b, N, points, size;
            float step, r, sum;
            char word[32];
            signal(2, signalHandler); // CNTRL + C
            signal(17, signalHandler); //hijo termino
            // redirect input to child process
            while (1) {
                
                printf("Ingresa la función: ");
                scanf("%s", function);
                printf("Ingresa el rango y despúes los puntos separados por un espacio: ");
                scanf("%d %d %d", &x[0], &x[1], &x[2]);
                    
                N = (x[1] - x[0])+1;
                step = N / (float)x[2];

                float range[x[2]];
                
                for(int i = 0; i < x[2]; i++) {
                    range[i] = step + (step*i);
                }

                sum = 0.0;
                r = 0.0;
                for(int h = 0; h < x[2]; h++) {
                    fflush(stdin);
                    fprintf(out,"x=%f\n",range[h]);
                    fprintf(out, "%s\n", function);
                    fflush(out);
                    // read child process output
                    fscanf(in, "%f", &r);
                    fflush(in);
                    fflush(stdout);
                    
                    sum = sum + r;
                }
                printf("= %f\n", sum/(float)x[2]); 

            }
            wait(NULL);
    }
    
    return 0;
}