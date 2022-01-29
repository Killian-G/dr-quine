#include <stdio.h>
void a(){}
/*
	Outside comment
*/
int main()
{
	/*
		Inside comment
	*/
	a();
	char *s = "#include <stdio.h>%cvoid a(){}%c%c*%c%cOutside comment%c*%c%cint main()%c{%c%c%c*%c%c%cInside comment%c%c*%c%c%ca();%c%cchar *s = %c%s%c;%c%cprintf(s,10,10,47,10,9,10,47,10,10,10,9,47,10,9,9,10,9,47,10,9,10,9,34,s,34,10,9,10,10);%c}%c";
	printf(s,10,10,47,10,9,10,47,10,10,10,9,47,10,9,9,10,9,47,10,9,10,9,34,s,34,10,9,10,10);
}
