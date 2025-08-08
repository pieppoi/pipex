#include "pipex.h"

static char *find_cmd_path(char *cmd, char **envp)
{
    char *path_env = NULL;
    char **paths;
    char *full_path;
    int i;

    if (ft_strchr(cmd, '/'))
        return ft_strdup(cmd);
    i = 0;
    while (envp[i])
    {
        if (!ft_strncmp(envp[i], "PATH=", 5))
        {
            path_env = envp[i] + 5;
            break;
        }
        i++;
    }
    if (!path_env)
        return NULL;
    paths = ft_split(path_env, ':');
    i = 0;
    while (paths && paths[i])
    {
        full_path = ft_strjoin(paths[i], "/");
        char *tmp = full_path;
        full_path = ft_strjoin(full_path, cmd);
        free(tmp);
        if (access(full_path, X_OK) == 0)
        {
            i = 0;
            while (paths[i])
                free(paths[i++]);
            free(paths);
            return full_path;
        }
        free(full_path);
        i++;
    }
    i = 0;
    while (paths && paths[i])
        free(paths[i++]);
    free(paths);
    return NULL;
}

static void exec_cmd(char *cmd, char **envp)
{
    char **args = ft_split(cmd, ' ');
    char *cmd_path = find_cmd_path(args[0], envp);
    if (!cmd_path)
    {
        ft_putstr_fd("command not found: ", 2);
        ft_putstr_fd(args[0], 2);
        ft_putstr_fd("\n", 2);
        int i = 0;
        while (args[i])
            free(args[i++]);
        free(args);
        exit(1);
    }
    execve(cmd_path, args, envp);
    perror("execve");
    int i = 0;
    while (args[i])
        free(args[i++]);
    free(args);
    free(cmd_path);
    exit(1);
}

int main(int argc, char *argv[], char *envp[])
{
    int fd[2];
    int infile, outfile;
    pid_t pid1, pid2;

    if (argc != 5)
    {
        ft_putstr_fd("Usage: ", 2);
        ft_putstr_fd(argv[0], 2);
        ft_putstr_fd(" infile cmd1 cmd2 outfile\n", 2);
        return 1;
    }
    if (pipe(fd) == -1)
    {
        perror("pipe");
        return 1;
    }
    pid1 = fork();
    if (pid1 == -1)
    {
        perror("fork");
        return 1;
    }
    if (pid1 == 0)
    {
        infile = open(argv[1], O_RDONLY);
        if (infile < 0)
        {
            perror("open infile");
            exit(1);
        }
        dup2(infile, 0);
        dup2(fd[1], 1);
        close(fd[0]);
        close(fd[1]);
        close(infile);
        exec_cmd(argv[2], envp);
    }
    pid2 = fork();
    if (pid2 == -1)
    {
        perror("fork");
        return 1;
    }
    if (pid2 == 0)
    {
        outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (outfile < 0)
        {
            perror("open outfile");
            exit(1);
        }
        dup2(fd[0], 0);
        dup2(outfile, 1);
        close(fd[1]);
        close(fd[0]);
        close(outfile);
        exec_cmd(argv[3], envp);
    }
    close(fd[0]);
    close(fd[1]);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    return 0;
}