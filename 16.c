#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
void main(){
int a[2];
int b[2];
char buffer[20];
pid_t childid;
pipe(a);
pipe(b);
childid=fork();

if(childid!=0){
write(a[1],"parent message\n",15);
read(b[0],buffer, sizeof(buffer));
printf("%s",buffer);
}
else{
read(a[0],buffer,sizeof(buffer));
write(b[1],"child message\n",14);
printf("%s",buffer);
}
}
