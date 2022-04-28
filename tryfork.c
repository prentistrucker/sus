#include <stdio.h>
#include <sys/types.h> //pid_t
#include <unistd.h>//
int main()
{
// make two process which run same
// program after this instruction

	fork();
	printf("Hello world!\n");
	return 0;
}