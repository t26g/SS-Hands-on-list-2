#include <stdio.h>
#include <sys/shm.h>
void main()
{
    key_t key = ftok(".",1);
    int shmid = shmget(key,1024,0666|IPC_CREAT);
    printf("Shared memory id: %d\n",shmid);

    char *str = (char*) shmat(shmid,(void*)0,SHM_RDONLY);
    printf("Press Enter to read from shared memory: ");
    getchar();
    printf("Data read from shared memory: %s\n",str); 
    shmdt(str);
    shmctl(shmid, IPC_RMID, NULL);
}
