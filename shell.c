#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024

int main(void)
{
    char *line = malloc(MAX_CMD_LEN);
    char *argv[] = {line, NULL};
    pid_t child_pid;
    int status;

    while (1)
    {
        write(STDOUT_FILENO, "#cisfun$ ", 9);
        if (read(STDIN_FILENO, line, MAX_CMD_LEN) <= 0)
        {
            write(STDOUT_FILENO, "\n", 1);
            break;
        }
        line[MAX_CMD_LEN - 1] = '\0'; /* ensure null termination */

        child_pid = fork();
        if (child_pid == -1)
        {
            perror("Error:");
            return (1);
        }
        if (child_pid == 0)
        {
            if (execve(line, argv, NULL) == -1)
                perror("./shell");
            exit(0);
        }
        else
        {
            wait(&status);
        }
    }
    free(line);
    return (0);
}
