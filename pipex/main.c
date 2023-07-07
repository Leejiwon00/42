#include "pipex.h"

// void    parse_envp(char **envp)
// {
//     int     i;
//     int     j;
//     char    *path;

//     i = 0;
//     path = 

// }

int main(int ac, char **av, char **envp)
{
    t_info info;

    int i=0;
    while(envp[i])
    {
        printf("%s", envp[i]);
        i++;
    }
           
//    if (ac == 5)
//    {
//         parse_envp(envp);
//    }
}