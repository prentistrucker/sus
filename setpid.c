#define _POSIX_SOURCE
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
void main() {
	pid_t pid;
	int p1[2], p2[2];
	char c='?';
	if (pipe(p1) != 0)   // to send the output of one command/program/process to another command/program/process for further processing.  pipe is a connection between two processes,
		perror("pipe() #1 error");
	else if (pipe(p2) != 0)
		perror("pipe() #2 error");
	else
		if ((pid = fork()) == 0) {
			printf("child's process group id is %d\n", (int) getpgrp());
			write(p2[1], &c, 1);
			puts("child is waiting for parent to complete task");
			read(p1[0], &c, 1);
			printf("child's process group id is now %d\n", (int) getpgrp());
			exit(0);
		}
	else {
		printf("parent's process group id is %d\n", (int) getpgrp());
		read(p2[0], &c, 1);
		printf("parent is performing setpgid() on pid %d\n", (int) pid);
		if (setpgid(pid, 0) != 0)
			perror("setpgid() error");
		write(p1[1], &c, 1);
		printf("parent's process group id is now %d\n", (int) getpgrp());
		sleep(5);
	}
}
//int pipe(int fds[2]);

//Parameters :
//fd[0] will be the fd(file descriptor) for the 
//read end of pipe.
//fd[1] will be the fd for the write end of pipe.
//Returns : 0 on Success.
//-1 on error.