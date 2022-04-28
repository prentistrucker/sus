#define _PROGRAM_NAME "whoami"     //whoami displays the username of the current user when this command is invoked.
#include<stdlib.h>

#include<pwd.h>         //The <pwd. h> header shall define the struct passwd, structure, which shall include atlest username and passward
#include<stdio.h>
int main(int argc,char *argv[])
{
	register struct passwd *pw;
	register uid_t uid;
	int c;
	uid=geteuid();
	pw=getpwuid(uid);
	if(pw)
	{
		puts(pw->pw_name);
		exit(EXIT_SUCCESS);
	}
	fprintf(stderr,"%s: cannot find username for UID %u\n", _PROGRAM_NAME,(unsigned) uid);
	exit(EXIT_FAILURE);
}
