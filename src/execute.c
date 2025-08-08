/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 00:00:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2024/06/10 00:00:00 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
#include <stdlib.h>
#include <unistd.h>

static char	*get_cmd_path(char *argv, char **envp, char ***cmd)
{
	char	*path;

	*cmd = ft_split(argv, ' ');
	if (!*cmd || !(*cmd)[0] || !*(*cmd)[0])
	{
		free_cmd(*cmd);
		ft_error("command not found");
		exit(1);
	}
	path = find_path((*cmd)[0], envp);
	if (!path)
	{
		free_cmd(*cmd);
		ft_error("command not found");
		exit(127);
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
		ft_error("execve");
		exit(126);
	}
} 
