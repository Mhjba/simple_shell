#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define MAXLINE 4096 /* max line length */

void parse(char *line, char **argv)
{
     while (*line != '\0') {       /* if not the end of line ....... */ 
          while (*line == ' ' || *line == '\t' || *line == '\n')
               *line++ = '\0';     /* replace white spaces with 0    */
          *argv++ = line;          /* save the argument position     */
          while (*line != '\0' && *line != ' ' && *line != '\t' && *line != '\n') 
               line++;             /* skip the argument until ...    */
     }
     *argv = '\0';                 /* mark the end of argument list  */
}

void execute(char **argv)
{
     pid_t  pid;
     int    status;

     if ((pid = fork()) < 0) {     /* fork a child process           */
          write(STDOUT_FILENO, "*** ERROR: forking child process failed\n", 44);
          exit(1);
     }
     else if (pid == 0) {          /* for the child process:         */
          if (execvp(*argv, argv) < 0) {     /* execute the command  */
               write(STDOUT_FILENO, "*** ERROR: exec failed\n", 24);
               exit(1);
          }
     }
     else {                                  /* for the parent:      */
          while (wait(&status) != pid)       /* wait for completion  */
               ;
     }
}

int main(void)
{
    char  line[MAXLINE];             /* the input line                 */
    char  *argv[64];              /* the command line argument      */

    while (1) {                   /* repeat until done ....         */
        write(STDOUT_FILENO, "Shell > ", 8);     /*   display a prompt             */
        fgets(line, MAXLINE, stdin);  /*   read in the command line     */
        write(STDOUT_FILENO, "\n", 1);
        parse(line, argv);       /*   parse the line               */
        if (strcmp(argv[0], "exit") == 0)  /* is it an "exit"?     */
            exit(0);            /*   exit if it is                */
        execute(argv);           /* otherwise, execute the command */
    }
}
