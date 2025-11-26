/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 14:12:30 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/08/09 03:10:22 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include "libft/libft.h"

void	ft_error(const char *msg);
void	ft_error_exit(const char *msg, int exit_code);
char	*find_path(char *cmd, char **envp);
void	execute(char *argv, char **envp);
int		get_next_line(char **line);
void	free_paths(char **paths);
char	*join_path(const char *dir, const char *cmd);
void	free_cmd(char **cmd);

#endif