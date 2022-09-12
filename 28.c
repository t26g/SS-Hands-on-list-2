#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <unistd.h>

void main()
{
    key_t queueKey;
    int queueIdentifier;
    struct msqid_ds messageQueueInfo;
    int msgctlStatus;

    queueKey = ftok(".", 1);

    queueIdentifier = msgget(queueKey, IPC_CREAT | 0700);

    msgctl(queueIdentifier, IPC_STAT, &messageQueueInfo);

    printf("Press enter to change the permissions!\n");
    getchar();

    messageQueueInfo.msg_perm.mode = 0777;

    msgctlStatus = msgctl(queueIdentifier, IPC_SET, &messageQueueInfo);

    if (msgctlStatus == -1)
    {
        perror("Error while changing Message Queue permission!");
        _exit(0);
    }else
         printf("Permission changed\n");
}
