#include <signal.h>
#include <stdio.h>
#include <unistd.h>
int ret = 1;

void signalHandler(int sig){
	printf("\nRecibí señal %d\n", sig);
	if(sig == 2){
		ret = 0;
	}
}

int main(){
	signal(2, signalHandler); // CNTRL + C
	signal(15,signalHandler);
	while(ret){
		printf("Trabajando\n");
		sleep(1);
	}
	printf("Ya voy a terminar\n ");
	return 0;
    }