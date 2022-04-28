#include<stdio.h>
#include<stdlib.h>
#include <fcntl.h>
int main()
{
	int fd1 = open("exp66.txt", O_RDONLY | O_CREAT);
	if(fd1 < 0)
	{
		perror("c1");
		exit(1);
	}
	printf("opened the fd = % d\n", fd1);
	// Using close system Call
	if(close(fd1) < 0)
	{
		perror("c1");
		exit(1);
	}
	printf("closed the fd.\n");
}