//este archivo es el fichero fuente que al compilarse produce el ejecutable Ej1
#include  <stdio.h>
#include  <sys/types.h>
#include <string.h>


/* The index of the "read" end of the pipe */
#define READ 0

/* The index of the "write" end of the pipe */
#define WRITE 1

char *phrase = "Stuff this in your pipe and smoke it";
int fd[2], bytesRead;
char message [100]; /* Parent process message buffer */

void  ChildProcess(void);                /* child process prototype  */
void  ParentProcess(void);               /* parent process prototype */

void  main(void)
{
    pid_t  pid;    


  	pipe ( fd ); /*Create an unnamed pipe*/

    pid = fork();
    if (pid == 0) 
        ChildProcess();
    else 
        ParentProcess();
}

void  ChildProcess(void)
{
	close (fd[READ]); /* Close unused end*/
    write (fd[WRITE], phrase, strlen ( phrase) +1); /* include NULL*/
    close (fd[WRITE]); /* Close used end*/
    printf("Child:  Wrote '%s' to pipe!\n", phrase);
}

void  ParentProcess(void)
{
    /* Parent Reader */
    close (fd[WRITE]); /* Close unused end*/
    bytesRead = read ( fd[READ], message, 100);
    printf ( "Parent: Read %d bytes from pipe: %s\n", bytesRead, message);
    close ( fd[READ]); /* Close used end */
}