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

void	child_process(char **argv, char **envp, int *fd)
{
	int	filein;

	filein = open(argv[1], O_RDONLY, 0777);
	if (filein == -1)
	{
		perror("open infile");
		close(fd[0]);
		close(fd[1]);
		exit(1);
	}
	dup2(fd[1], STDOUT_FILENO);
	dup2(filein, STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(filein);
	execute(argv[2], envp);
}

void	parent_process(char **argv, char **envp, int *fd)
{
	int	fileout;

	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fileout == -1)
	{
		ft_error("open outfile");
		close(fd[0]);
		close(fd[1]);
		exit(1);
	}
	dup2(fd[0], STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(fileout);
	execute(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		status1;
	int		status2;

	if (argc != 5)
	{
		ft_putstr_fd("\033[31m./pipex infile cmd cmd outfile", 2);
		return (1);
	}
	if (pipe(fd) == -1)
		ft_error("pipe");
	pid1 = fork();
	if (pid1 == -1)
		ft_error("fork");
	if (pid1 == 0)
		child_process(argv, envp, fd);
	pid2 = fork();
	if (pid2 == -1)
		ft_error("fork");
	if (pid2 == 0)
		parent_process(argv, envp, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, &status1, 0);
	waitpid(pid2, &status2, 0);
	if (WIFEXITED(status2))
		return (WEXITSTATUS(status2));
	else if (WIFEXITED(status1))
		return (WEXITSTATUS(status1));
	return (1);
}
