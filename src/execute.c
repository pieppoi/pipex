/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 00:00:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/08/09 03:02:01 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
#include <errno.h>

static void	exit_empty_command(char ***cmd)
{
	ft_putendl_fd("pipex: : command not found", STDERR_FILENO);
	free_cmd(*cmd);
	exit(127);
}

static void	exit_cmd_not_found(char **cmd)
{
	ft_putstr_fd("pipex: command not found: ", STDERR_FILENO);
	ft_putendl_fd(cmd[0], STDERR_FILENO);
	free_cmd(cmd);
	exit(127);
}

static void	exit_with_perror(char **cmd, int exit_code)
{
	if (cmd && cmd[0])
		perror(cmd[0]);
	else
		perror("pipex");
	free_cmd(cmd);
	exit(exit_code);
}

static char	*dup_cmd_path(char *cmd)
{
	char	*path;

	path = ft_strdup(cmd);
	if (!path)
		ft_error("malloc");
	return (path);
}

static char	*get_cmd_path(char *argv, char **envp, char ***cmd)
{
	char	*path;

	*cmd = ft_split(argv, ' ');
	if (!*cmd)
		ft_error("malloc");
	if (!(*cmd)[0] || !(*cmd)[0][0])
		exit_empty_command(cmd);
	if (ft_strchr((*cmd)[0], '/'))
	{
		if (access((*cmd)[0], F_OK) != 0)
			exit_with_perror(*cmd, 127);
		if (access((*cmd)[0], X_OK) != 0)
			exit_with_perror(*cmd, 126);
		return (dup_cmd_path((*cmd)[0]));
	}
	path = find_path((*cmd)[0], envp);
	if (!path)
		exit_cmd_not_found(*cmd);
	return (path);
}

void	execute(char *argv, char **envp)
{
	char	**cmd;
	char	*path;

	path = get_cmd_path(argv, envp, &cmd);
	if (execve(path, cmd, envp) == -1)
	{
		int	exit_code;

		exit_code = (errno == ENOENT) ? 127 : 126;
		free(path);
		exit_with_perror(cmd, exit_code);
	}
}
