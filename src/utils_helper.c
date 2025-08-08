/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 00:00:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2024/06/10 00:00:00 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
#include <stdlib.h>

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

void	free_cmd(char **cmd)
{
	int	i;

	i = 0;
	while (cmd && cmd[i])
		free(cmd[i++]);
	free(cmd);
} 
