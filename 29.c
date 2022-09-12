#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <unistd.h>
void main(){
key_t key=ftok(".",1);
int keyid=msgget(key, IPC_CREAT | 0700);
int i=msgctl(keyid, IPC_RMID, 0);
if(i==-1)printf("error");
else printf("remove message queue\n");
}
