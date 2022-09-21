#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void callback()
{
    printf("Signal SIGSEGV has been caught!\n");
    _exit(0);
}

void main()
{
    __sighandler_t signalStatus;

    signalStatus = signal(SIGSEGV, (void *)callback);
    raise(SIGSEGV);
}
