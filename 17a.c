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
dup(a[1]);
close(a[0]);
execlp("ls","ls -l","-l",NULL);
}
else{
close(STDIN_FILENO);
dup(a[0]);
close(a[1]);
execlp("wc","wc",NULL);
}
}
