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
	if (!*cmd || !(*cmd)[0] || !*(*cmd)[0])
	{
		free_cmd(*cmd);
		ft_error_exit("command not found", 127);
	}
	if (ft_strchr((*cmd)[0], '/'))
	{
		if (access((*cmd)[0], X_OK) == 0)
			return (dup_cmd_path((*cmd)[0]));
		free_cmd(*cmd);
		ft_error_exit("command not found", 127);
	}
	path = find_path((*cmd)[0], envp);
	if (!path)
	{
		free_cmd(*cmd);
		ft_error_exit("command not found", 127);
	}
	return (path);
}

void	execute(char *argv, char **envp)
{
	char	**cmd;
	char	*path;

	path = get_cmd_path(argv, envp, &cmd);
	if (execve(path, cmd, envp) == -1)
	{
		free_cmd(cmd);
		free(path);
		ft_error_exit("execve", 126);
	}
}
