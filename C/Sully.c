#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
int i = 5;
int main(){
char *str=malloc(1024);if(!str)return 1;
snprintf(str,1024,"Sully_%d.c",i-1);
int fd=open(str,O_CREAT|O_WRONLY|O_TRUNC,S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);
char *s="#include<fcntl.h>%c#include<stdio.h>%c#include<stdlib.h>%cint i = %d;%cint main(){%cchar *str=malloc(1024);if(!str)return 1;%csnprintf(str,1024,%cSully_%%d.c%c,i-1);%cint fd=open(str,O_CREAT|O_WRONLY|O_TRUNC,S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);%cchar *s=%c%s%c;%cdprintf(fd,s,10,10,10,i-1,10,10,10,34,34,10,10,34,s,34,10,10,34,34,10,10,34,34,10,10,10);%csnprintf(str,1024,%cclang Sully_%%d.c -o Sully_%%d%c,i-1,i-1);%csystem(str);%csnprintf(str,1024,%c./Sully_%%d%c,i-1);%cif (i>0)system(str);%c}%c";
dprintf(fd,s,10,10,10,i-1,10,10,10,34,34,10,10,34,s,34,10,10,34,34,10,10,34,34,10,10,10);
snprintf(str,1024,"clang Sully_%d.c -o Sully_%d",i-1,i-1);
system(str);
snprintf(str,1024,"./Sully_%d",i-1);
if (i>0)system(str);
}
