#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
void main(){
int a[2];
pid_t childid;

pipe(a);
childid=fork();

if(childid!=0){
close(STDOUT_FILENO);
fcntl(a[1],F_DUPFD, STDOUT_FILENO);
close(a[0]);
execlp("ls","ls -l","-l",NULL);
}
else{
close(STDIN_FILENO);
fcntl(a[0],F_DUPFD,STDIN_FILENO);
close(a[1]);
execlp("wc","wc",NULL);
}
}
