#include<stdio.h>
#include<stdlib.h>
#include <fcntl.h>
int main()
{
	int sz;
	char*c = (char*) calloc(100, sizeof(char));
	//int open(const char *pathname, int flags, mode_t mode);
	
	int fd = open("foo2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);  //It specifies the protection mode of the new file. 
															//0644 is the most typical value -- it says "I can read and write it; everyone else can only read it." 
	if(fd < 0)
	{
		perror("r1");
		exit(1);
	}
	sz = write(fd, "hello RCOE\n", strlen("hello RCOE\n"));
	printf("called write(%d, \"hello RCOE\\n\", %lu). It returned %d\n", fd,	strlen("hello RCOE\n"), sz);
	
	sz = read(fd, c, 10);
	printf("called read(%d, c, 10). returned that %d bytes were read.\n", fd, sz);
	c[sz] = '\0';
	printf("Those bytes are as follows: %s\n", c);
	
	
	close(fd);
}
