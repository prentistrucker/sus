#include<stdio.h>
#include<stdlib.h>
#include <fcntl.h>
int main()
{
	int fd, sz;
	char*c = (char*) calloc(100, sizeof(char));
	fd = open("exp33.txt", O_RDONLY);
	if(fd < 0) 
	{ 
		perror("r1"); exit(1); 
	}
	sz = read(fd, c, 12);
	printf("called read(% d, c, 10). returned that %d bytes were read.\n", fd, sz);
	c[sz] = '\0';
	printf("Those bytes are as follows: %s\n", c);
}
