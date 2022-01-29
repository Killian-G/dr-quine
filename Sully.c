#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
int i = 5;
int main(){
char *file=malloc(1024);if(!file)return 1;
snprintf(file,1024,"Sully_%d.c",i-1);
char *file2=strdup(file);
file2[strlen(file2)-2]=0;
int fd=open(file,O_CREAT|O_WRONLY|O_TRUNC,S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);
char *s="#include<fcntl.h>%c#include<stdio.h>%c#include<stdlib.h>%c#include<unistd.h>%c#include<string.h>%cint i = %d;%cint main(){%cchar *file=malloc(1024);if(!file)return 1;%csnprintf(file,1024,%cSully_%%d.c%c,i-1);%cchar *file2=strdup(file);%cfile2[strlen(file2)-2]=0;%cint fd=open(file,O_CREAT|O_WRONLY|O_TRUNC,S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);%cchar *s=%c%s%c;%cdprintf(fd,s,10,10,10,10,10,i-1,10,10,10,34,34,10,10,10,10,34,s,34,10,10,34,34,34,34,34,34,10,10);%cexecl(%c/bin/clang%c,%c/bin/clang%c,file,%c-o%c,file2,NULL);%cif (i>0)execl(file2,file2,NULL);%c}%c";
dprintf(fd,s,10,10,10,10,10,i-1,10,10,10,34,34,10,10,10,10,34,s,34,10,10,34,34,34,34,34,34,10,10,10);
execl("/bin/clang","/bin/clang",file,"-o",file2,NULL);
if (i>0)execl(file2,file2,NULL);
}
