/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
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

static int	read_and_fill(char *buffer, int *i)
{
	char	c;
	int		r;

	r = read(0, &c, 1);
	while (r && c != '\n' && c != '\0')
	{
		if (c != '\n' && c != '\0')
			buffer[(*i)++] = c;
		r = read(0, &c, 1);
	}
	return (r);
}

int	get_next_line(char **line)
{
	char	*buffer;
	int		i;
	int		r;

	i = 0;
	buffer = (char *)malloc(10000);
	if (!buffer)
		return (-1);
	r = read_and_fill(buffer, &i);
	buffer[i] = '\n';
	buffer[++i] = '\0';
	*line = buffer;
	free(buffer);
	return (r);
} 
