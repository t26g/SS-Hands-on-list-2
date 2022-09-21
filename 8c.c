#include <signal.h>
#include <stdio.h>
#include <unistd.h>
void callback()
{
    printf("Signal SIGFPE has been caught!\n");
    _exit(0);
}

void main()
{
    __sighandler_t signalStatus;
    signalStatus = signal(SIGFPE, (void *)callback);
    if (signalStatus == SIG_ERR)
        perror("Error while assigning signal handler!");
    else
        raise(SIGFPE);
}
