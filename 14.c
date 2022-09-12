#include<stdio.h>
#include<unistd.h>
void main(){
int a[2];
char buffer[20];
pipe(a);
write(a[1],"Tushar\n",7);
read(a[0],buffer,sizeof(buffer));
printf("%s",buffer);
}
