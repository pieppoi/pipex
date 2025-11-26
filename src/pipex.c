/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 09:54:02 by gcollet           #+#    #+#             */
/*   Updated: 2025/08/09 11:29:20 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	child_process(char **argv, char **envp, int *fd, int infile)
{
	if (dup2(infile, STDIN_FILENO) == -1 || dup2(fd[1], STDOUT_FILENO) == -1)
		ft_error("dup2");
	close(infile);
	close(fd[0]);
	close(fd[1]);
	execute(argv[2], envp);
}

static void	parent_process(char **argv, char **envp, int *fd)
{
	int	outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
	{
		perror(argv[4]);
		close(fd[0]);
		close(fd[1]);
		exit(1);
	}
	if (dup2(fd[0], STDIN_FILENO) == -1 || dup2(outfile, STDOUT_FILENO) == -1)
		ft_error("dup2");
	close(outfile);
	close(fd[0]);
	close(fd[1]);
	execute(argv[3], envp);
}

static int	wait_children(pid_t pid1, pid_t pid2, int infile_error)
{
	int	status1;
	int	status2;
	int	exit_code;

	if (pid1 > 0)
		waitpid(pid1, &status1, 0);
	waitpid(pid2, &status2, 0);
	if (WIFEXITED(status2))
		exit_code = WEXITSTATUS(status2);
	else if (WIFSIGNALED(status2))
		exit_code = 128 + WTERMSIG(status2);
	else
		exit_code = 1;
	if (pid1 <= 0 && infile_error && exit_code == 0)
		return (1);
	if (pid2 <= 0 && pid1 > 0)
	{
		if (WIFEXITED(status1))
			return (WEXITSTATUS(status1));
		if (WIFSIGNALED(status1))
			return (128 + WTERMSIG(status1));
	}
	return (exit_code);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		infile;
	int		infile_error;

	if (argc != 5)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	infile = open(argv[1], O_RDONLY);
	infile_error = (infile == -1);
	if (infile_error)
		perror(argv[1]);
	if (pipe(fd) == -1)
		ft_error("pipe");
	pid1 = -1;
	if (!infile_error)
	{
		pid1 = fork();
		if (pid1 == -1)
			ft_error("fork");
		if (pid1 == 0)
			child_process(argv, envp, fd, infile);
		close(infile);
	}
	pid2 = fork();
	if (pid2 == -1)
		ft_error("fork");
	if (pid2 == 0)
		parent_process(argv, envp, fd);
	close(fd[0]);
	close(fd[1]);
	return (wait_children(pid1, pid2, infile_error));
}
