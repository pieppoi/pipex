/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 10:26:01 by gcollet           #+#    #+#             */
/*   Updated: 2025/08/09 02:47:09 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	free_paths(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
		free(paths[i++]);
	free(paths);
}

char	*join_path(const char *dir, const char *cmd)
{
	char	*part_path;
	char	*full_path;

	part_path = ft_strjoin(dir, "/");
	full_path = ft_strjoin(part_path, cmd);
	free(part_path);
	return (full_path);
}

static char	*search_in_paths(char **paths, char *cmd)
{
	char	*path;
	int		i;

	i = 0;
	while (paths && paths[i])
	{
		path = join_path(paths[i], cmd);
		if (access(path, X_OK) == 0)
		{
			free_paths(paths);
			return (path);
		}
		free(path);
		i++;
	}
	free_paths(paths);
	return (0);
}

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	int		i;

	if (!cmd || !envp)
		return (0);
	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	if (!envp[i])
		return (0);
	paths = ft_split(envp[i] + 5, ':');
	if (!paths)
		return (0);
	return (search_in_paths(paths, cmd));
}

void	free_cmd(char **cmd)
{
	int	i;

	i = 0;
	while (cmd && cmd[i])
		free(cmd[i++]);
	free(cmd);
}
