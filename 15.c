#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
void main(){
int a[2];
char buffer[20];
pid_t childid;
pipe(a);
childid=fork();

if(childid!=0)
write(a[1],"Tushar\n",7);
else{
read(a[0],buffer,sizeof(buffer));
printf("%s",buffer);
}
}
