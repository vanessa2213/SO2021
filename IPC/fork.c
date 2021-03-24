#include <signal.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int ret = 1;

void signalHandler(int sig){
	int pidHijoTermino = wait(NULL);
	if(sig == 17){
        printf("Mi hijo termino %d\n", pidHijoTermino);
		ret = 0;
	}
}

int main(){
    signal(17, signalHandler);
    int pid = fork();
    

    if (pid == 0){
        //Proceso hijo
        printf("Soy el proceso hijo\n");

    }
    else{
        printf("Soy el proceso padre y mi hijo es %d\n", pid);
        //pidHijoTermino = wait(NULL)
        
        while(ret){
            printf("Trabajando \n");
            sleep(1);
        }
        printf("Termino\n");
    }
    
    return 0;

}