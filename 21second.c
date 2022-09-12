#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

void main()
{
        char buffer[100];
        int fd2=open("fifo21a",O_RDONLY);
        read(fd2,buffer,sizeof(buffer));
        printf("Message read by pipe 1:: %s\n",buffer);
        close(fd2);

	mkfifo("fifo21b",S_IRWXU);
	char buf[100];
	int fd1 = open("fifo21b",O_WRONLY);
	fgets(buf,sizeof(buf),stdin);
	write(fd1,buf,strlen(buf)+1);
	printf("Message Written To The Pipe 2.\n");
	close(fd1);
}
