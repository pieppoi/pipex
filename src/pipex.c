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

typedef struct s_pipex
{
	int	argc;
	char	**argv;
	char	**envp;
	int	here_doc;
	int	infile;
	int	outfile;
	int	cmd_start;
	int	cmd_count;
}	t_pipex;

static int	is_here_doc(char **argv)
{
	if (!argv[1])
		return (0);
	return (ft_strncmp(argv[1], "here_doc", 9) == 0);
}

static int	is_limiter(const char *line, const char *limiter)
{
	size_t	len;

	len = ft_strlen(limiter);
	if (ft_strncmp(line, limiter, len) != 0)
		return (0);
	return (line[len] == '\n');
}

static int	create_here_doc(char *limiter)
{
	int		pipefd[2];
	char	*line;
	int		ret;
	int		stop;

	if (pipe(pipefd) == -1)
		ft_error("pipe");
	while (1)
	{
		ft_putstr_fd("heredoc> ", 1);
		line = NULL;
		ret = get_next_line(&line);
		if (ret == -1)
		{
			free(line);
			close(pipefd[0]);
			close(pipefd[1]);
			ft_error("get_next_line");
		}
		if (!line)
			continue ;
		stop = is_limiter(line, limiter);
		if (!stop)
			write(pipefd[1], line, ft_strlen(line));
		free(line);
		if (stop || ret == 0)
			break ;
	}
	close(pipefd[1]);
	return (pipefd[0]);
}

static void	open_files(t_pipex *px)
{
	int	flags;

	if (px->here_doc)
		px->infile = create_here_doc(px->argv[2]);
	else
	{
		px->infile = open(px->argv[1], O_RDONLY);
		if (px->infile < 0)
			ft_error(px->argv[1]);
	}
	flags = O_WRONLY | O_CREAT;
	if (px->here_doc)
		flags |= O_APPEND;
	else
		flags |= O_TRUNC;
	px->outfile = open(px->argv[px->argc - 1], flags, 0644);
	if (px->outfile < 0)
	{
		close(px->infile);
		ft_error(px->argv[px->argc - 1]);
	}
}

static void	init_pipex(t_pipex *px, int argc, char **argv, char **envp)
{
	ft_bzero(px, sizeof(t_pipex));
	px->argc = argc;
	px->argv = argv;
	px->envp = envp;
	px->here_doc = is_here_doc(argv);
	if ((!px->here_doc && argc < 5) || (px->here_doc && argc < 6))
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	px->cmd_start = px->here_doc ? 3 : 2;
	px->cmd_count = argc - px->cmd_start - 1;
	if (px->cmd_count < 1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	open_files(px);
}

static pid_t	launch_process(t_pipex *px, int input_fd, int output_fd,
				int next_read_fd, char *cmd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		ft_error("fork");
	if (pid == 0)
	{
		if (next_read_fd != -1 && next_read_fd != output_fd)
			close(next_read_fd);
		if (px->outfile >= 0 && px->outfile != output_fd)
			close(px->outfile);
		if (dup2(input_fd, STDIN_FILENO) == -1
			|| dup2(output_fd, STDOUT_FILENO) == -1)
			ft_error("dup2");
		close(input_fd);
		close(output_fd);
		execute(cmd, px->envp);
	}
	return (pid);
}

static int	execute_pipeline(t_pipex *px)
{
	pid_t	*pids;
	int	pipefd[2];
	int	prev_fd;
	int	i;
	int	status;
	int	exit_code;

	pids = (pid_t *)malloc(sizeof(pid_t) * px->cmd_count);
	if (!pids)
		ft_error("malloc");
	prev_fd = px->infile;
	i = 0;
	while (i < px->cmd_count)
	{
		if (i < px->cmd_count - 1 && pipe(pipefd) == -1)
			ft_error("pipe");
		pids[i] = launch_process(px, prev_fd,
				(i == px->cmd_count - 1) ? px->outfile : pipefd[1],
				(i == px->cmd_count - 1) ? -1 : pipefd[0],
				px->argv[px->cmd_start + i]);
		close(prev_fd);
		if (i == px->cmd_count - 1)
			close(px->outfile);
		else
		{
			close(pipefd[1]);
			prev_fd = pipefd[0];
		}
		i++;
	}
	exit_code = 0;
	i = 0;
	while (i < px->cmd_count)
	{
		waitpid(pids[i], &status, 0);
		if (pids[i] == pids[px->cmd_count - 1])
		{
			if (WIFEXITED(status))
				exit_code = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				exit_code = 128 + WTERMSIG(status);
		}
		i++;
	}
	free(pids);
	return (exit_code);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	px;

	init_pipex(&px, argc, argv, envp);
	return (execute_pipeline(&px));
}
