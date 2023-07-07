#ifndef PIPEX_H
#define PIPEX_H

#include <io.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_info
{
    int fd[2];
    char *infile;
    char *outfile;
} t_info;

#endif