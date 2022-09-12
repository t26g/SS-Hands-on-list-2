#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

void main()
{
	mkfifo("fifo20",S_IRWXU);
	char buf[101];
	int fd = open("fifo20",O_WRONLY);
	fgets(buf,sizeof(buf),stdin);
	write(fd,buf,strlen(buf)+1);
	printf("Message Written To The Pipe.\n");
	close(fd);
}
