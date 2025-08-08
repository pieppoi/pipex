#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

void error_exit(const char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}

char **split_cmd(const char *cmd)
{
    // 簡易的な空白区切り分割（本格的には要改良）
    char **argv = malloc(64 * sizeof(char *));
    char *cmd_copy = strdup(cmd);
    char *token = strtok(cmd_copy, " ");
    int i = 0;
    while (token)
    {
        argv[i++] = strdup(token);
        token = strtok(NULL, " ");
    }
    argv[i] = NULL;
    free(cmd_copy);
    return argv;
}

int main(int argc, char **argv)
{
    if (argc != 5)
    {
        fprintf(stderr, "Usage: %s infile cmd1 cmd2 outfile\n", argv[0]);
        return 1;
    }

    int pipefd[2];
    if (pipe(pipefd) == -1)
        error_exit("pipe");

    pid_t pid1 = fork();
    if (pid1 < 0)
        error_exit("fork");
    if (pid1 == 0)
    {
        // 子1: infile -> cmd1 -> pipe
        int infile = open(argv[1], O_RDONLY);
        if (infile < 0)
            error_exit("open infile");
        dup2(infile, 0);
        dup2(pipefd[1], 1);
        close(infile);
        close(pipefd[0]);
        close(pipefd[1]);
        char **cmd1_argv = split_cmd(argv[2]);
        execvp(cmd1_argv[0], cmd1_argv);
        perror("execvp cmd1");
        exit(1);
    }

    pid_t pid2 = fork();
    if (pid2 < 0)
        error_exit("fork");
    if (pid2 == 0)
    {
        // 子2: pipe -> cmd2 -> outfile
        int outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (outfile < 0)
            error_exit("open outfile");
        dup2(pipefd[0], 0);
        dup2(outfile, 1);
        close(outfile);
        close(pipefd[0]);
        close(pipefd[1]);
        char **cmd2_argv = split_cmd(argv[3]);
        execvp(cmd2_argv[0], cmd2_argv);
        perror("execvp cmd2");
        exit(1);
    }

    close(pipefd[0]);
    close(pipefd[1]);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    return 0;
}