/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:34:04 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/08/08 16:28:38 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	if (argc != 5)
	{
		ft_putstr_fd("Usage: ./pipex infile cmd1 cmd2 outfile\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}

	int fd_in = open(argv[1], O_RDONLY);
	if (fd_in < 0)
	{
		perror("Error opening input file");
		return (EXIT_FAILURE);
	}

	int fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_out < 0)
	{
		perror("Error opening output file");
		close(fd_in);
		return (EXIT_FAILURE);
	}

	// Here you would typically set up pipes and fork processes to execute cmd1 and cmd2
	// For simplicity, this example does not include the full implementation.

	close(fd_in);
	close(fd_out);
	return (EXIT_SUCCESS);
}
