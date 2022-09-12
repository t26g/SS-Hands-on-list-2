#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>
void main(){
int fifoStatus;
long maxFiles;
long sizeOfPipe;
fifoStatus = mkfifo("fifo23",S_IRWXU);
maxFiles = sysconf(_SC_OPEN_MAX);
printf("Maximum number of files that can be opened is: %ld\n", maxFiles);
sizeOfPipe = pathconf("fifo23", _PC_PIPE_BUF);
printf("Maximum size of pipe: %ld\n", sizeOfPipe);
}
