/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 14:12:30 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/08/08 16:23:57 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// # include "ft_printf/ft_printf.h"
void	ft_error(const char *msg);
# include <unistd.h>     // read, write, access, close, unlink, dup, dup2, execve, fork, pipe
# include <fcntl.h>      // open
# include <stdlib.h>     // malloc, free, exit
# include <stdio.h>      // perror
# include <string.h>     // strerror
# include <sys/wait.h>   // wait, waitpid


#endif