#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

void main()
{
    int pipeCmdOneToTwo[2], pipeCmdTwoToThree[2];
    int pipeOneStatus, pipeTwoStatus;

    pid_t childOne, childTwo;

    pipeOneStatus = pipe(pipeCmdOneToTwo);
    pipeTwoStatus = pipe(pipeCmdTwoToThree);
        childOne = fork();
        if (childOne == 0)
        {
            close(pipeCmdTwoToThree[1]);
            close(pipeCmdOneToTwo[0]);
            close(pipeCmdOneToTwo[1]);

            close(STDIN_FILENO);
            dup2(pipeCmdTwoToThree[0], STDIN_FILENO);

            execlp("wc", "wc", NULL);
        }
        else
        {
            childTwo = fork();

            if (childTwo == 0)
            {
                close(pipeCmdOneToTwo[1]);
                close(pipeCmdTwoToThree[0]);
                close(STDIN_FILENO);
                dup2(pipeCmdOneToTwo[0], STDIN_FILENO);
                close(STDOUT_FILENO);
                dup2(pipeCmdTwoToThree[1], STDOUT_FILENO);
                execlp("grep", "grep ^d", "^d", NULL);
            }
            else
            {
                close(pipeCmdOneToTwo[0]);
                close(pipeCmdTwoToThree[1]);
                close(pipeCmdTwoToThree[0]);
                close(STDOUT_FILENO);
                dup2(pipeCmdOneToTwo[1], STDOUT_FILENO);
                execlp("ls", "ls -l", "-l", NULL);
            }
        }
    }

