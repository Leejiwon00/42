#include <unistd.h>
#include <fcntl.h>
# include <sys/wait.h>
#include <stdio.h>
int  a = 0;
int main()
{
	char *arg[] = {"./minishell", NULL};
	char *argwho[] = {"/usr/bin/who", NULL};
	pid_t pid;
	
	//if (a==0){
	pid = fork();
	if (pid == 0)
	{
//		printf("!!!\n");
		execve(arg[0], arg, NULL);
	}
	wait(NULL);
	execve(argwho[0], argwho, NULL);
}