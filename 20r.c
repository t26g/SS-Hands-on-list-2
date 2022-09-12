#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main()
{
	char buf[101];
	int fd1 = open("fifo20",O_RDONLY);
	read(fd1,buf,sizeof(buf));
	printf("Message Read From The Pipe:: %s",buf);
	close(fd1);
}
