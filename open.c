#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>   //give open system call
#include<errno.h>
extern int errno;
int main()
{
	// if file does not have in directory // then file --.txt is created.
	int fd = open("exp55.txt", O_RDONLY | O_CREAT);  // int open(const char *pathname, int flags);  //O_RDONLY, O_WRONLY, or O_RDWR
	printf("fd = %d/n", fd);
	if(fd ==-1)
	{
		// print which type of error have in a code
		printf("Error Number % d\n", errno);
		// print program detail "Success or failure"
		perror("Program");
	}
	close(fd);
	return 0;

}