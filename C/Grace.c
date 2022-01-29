#include<fcntl.h>
#include<stdio.h>
#define DEF1
#define DEF2
#define FT() int main(){\
int fd=open("Grace_kid.c",O_CREAT|O_WRONLY|O_TRUNC,S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);\
char *s="#include<fcntl.h>%c#include<stdio.h>%c#define DEF1%c#define DEF2%c#define FT() int main(){%c%cint fd=open(%cGrace_kid.c%c,O_CREAT|O_WRONLY|O_TRUNC,S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);%c%cchar *s=%c%s%c;%c%cdprintf(fd,s,10,10,10,10,92,10,34,34,92,10,34,s,34,92,10,92,10,10,47,10,9,10,47,10,10);%c%c}%c%c*%c%cThis is a comment%c*%c%cFT()";\
dprintf(fd,s,10,10,10,10,92,10,34,34,92,10,34,s,34,92,10,92,10,10,47,10,9,10,47,10,10);\
}
/*
	This is a comment
*/
FT()