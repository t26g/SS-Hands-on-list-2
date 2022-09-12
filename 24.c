#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
void main(){
key_t key;
int keyid;
key=ftok(".",1);
printf("key %d\n",key);
keyid=msgget(key, IPC_CREAT |IPC_EXCL |0700);
printf("keyID %d\n",keyid);
}
