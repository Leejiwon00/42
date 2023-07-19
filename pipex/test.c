/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:53:14 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/07/19 18:49:55 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <unistd.h>
// #include <stdio.h>
// #include <sys/wait.h>
// #include <fcntl.h>
// #include <string.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	// int fd[2];
// 	// pid_t pid;
// 	// pipe(fd);
// 	// pid = fork();
// 	// if (pid == 0)
// 	// {
// 	// 	int fd1 = open("test.txt", O_RDWR|O_CREAT);
// 	dup2(fd1, STDOUT_FILENO);
// 	char *args[] = {"ls ", "j", "-l", NULL};

// 	execve("/bin/ls", args, NULL);
// 	//}
	
// }
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("a", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // 파일 디스크립터를 표준 입력으로 리다이렉션
    if (dup2(fd, STDIN_FILENO) == -1) {
        perror("dup2");
        close(fd);
        return 1;
    }

    close(fd);

    // execve 함수 사용
    char *const argv[] = {"sed", "s/w/@/", NULL};
    char *const envp[] = {NULL};
    execve("/usr/bin/sed", argv, envp);

    perror("execve");
    return 1;
}
