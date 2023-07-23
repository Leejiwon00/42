#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
typedef struct s_info
{
	int		idx;
	int		**fd;
}	t_info;

void func(t_info *info)
{
	info->idx++;
}
int main()
{
	t_info info;

	int i = -1;
	info.fd = malloc(sizeof(int *) * 5);
	while (++i < 5)
		info.fd[i] = malloc(sizeof(int) * 2);
	i = -1;
	while (++i < 5)
	{
		if (pipe(info.fd[i]) < 0)
			exit(1);
	}
	i = -1;
	while (info.fd[++i])
		printf("%d %d\n", info.fd[i][0], info.fd[i][1]);


}