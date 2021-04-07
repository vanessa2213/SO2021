#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

typedef struct m{
    char status;
    int data[4];
} MyData;

int main(){
    MyData *datos;
    int key = 27;
    int shmID = shmget(key,sizeof(MyData),IPC_CREAT | 0666);

    datos = (MyData *)shmat(shmID, NULL, 0);
    
    datos->status = 'n';
    datos->data[0] = 40;
    datos->data[1] = 30;
    datos->data[2] = 20;
    datos->data[3] = 50;
    datos->status = 'r';
    while (datos->status != 't'){
        sleep(1);
    }
    printf("Los datos se consumieron\n");
    return 0;
}