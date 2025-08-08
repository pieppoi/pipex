/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 14:12:30 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/08/09 02:38:01 by mkazuhik         ###   ########.fr       */
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

/* src/pipex.c */
void	child_process(char **argv, char **envp, int *fd);
void	parent_process(char **argv, char **envp, int *fd);
/* src/utils.c */
void	ft_error(const char *msg);
char	*find_path(char *cmd, char **envp);
void	execute(char *argv, char **envp);
int		get_next_line(char **line);
// プロトタイプ宣言追加
void	free_paths(char **paths);
char	*join_path(const char *dir, const char *cmd);
void	free_cmd(char **cmd);

#endif