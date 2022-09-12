#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <unistd.h>
void main()
{
    key_t queueKey;
    int queueIdentifier;
    ssize_t messageSize;
    struct msgbuf
    {
        long mtype;
        char someChar;
    } data;

    queueKey = ftok(".", 1);

    queueIdentifier = msgget(queueKey, IPC_CREAT | 0700);

    data.mtype = 1;

    messageSize = msgrcv(queueIdentifier, &data, sizeof(data), data.mtype, 0);

    printf("Received number: %c\n", data.someChar);
}
