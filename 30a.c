#include <stdio.h>
#include <sys/shm.h>
void main()
{
    key_t key = ftok(".",1);
    int shmid = shmget(key,1024,0666|IPC_CREAT);
    printf("Shared memory id: %d\n",shmid);

    char *str = (char*) shmat(shmid,(void*)0,0);
    printf("Press Enter to write on shared memory: ");
    getchar();
    sprintf(str, "Tushar");
    printf("Data written in shared memory: %s\n",str); 
    shmdt(str);
}
