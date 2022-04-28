#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
void waitexample()
{
	int i, stat;
	pid_t pid[5];
	for(i=0; i<5; i++)
	{
		if((pid[i] = fork()) == 0)
		{
			sleep(1);   //<unistd.h>  sleep  current process for a specified time(seconds)
			exit(10 + i); //<stdlib.h> exit(int status) terminates the calling process immediately// status value returned to the parent process.
		}
	}
	// Using waitpid() and printing exit status of children.
	//for(i=0; i<5; i++)
	//{
		pid_t cpid = waitpid(pid[1], &stat, 0);
		if(WIFEXITED(stat))
			printf("Child %d terminated with status: %d\n",cpid, WEXITSTATUS(stat));
	//}
}

int main()
{
	waitexample();
	return 0;
}