#include <unistd.h>

int main()
{
	char *str[2];
	str[0] = "usr/bin/ls";
	str[1] = NULL;
	execve(str[0],str,NULL);
}