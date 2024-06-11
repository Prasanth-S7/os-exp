#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define sharedMemSize 50
void main(){
    // int shmid;
    // key_t key;
    char* shared_memory;
    // key=5677;
    // if(shmid == shmget(key,sharedMemSize, IPC_CREAT | 0666)>0)
    // {
    //     perror("shmget");
    //     exit(1);
    // }
    // if((shared_memory = shmat(shmid, NULL, 0))==(char*)-1){
    //     perror("shmat");
    //     exit(1);
    // }
    sprintf(shared_memory, "welcome to shared memory");
    sleep(2);
    exit(0);
}