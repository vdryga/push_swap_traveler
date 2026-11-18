/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 15:21:53 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/18 16:36:00 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static char	*copy_ongoing(char *src, char *dest)
{
	int	i;

	i = 0;
	while (src && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
		dest[i] = '\n';
	return (dest);
}

static char	*fill_line(char *line, char *buffer, int len)
{
	char	*back;
	int		i;
	int		j;

	if (len == 0)
		return (NULL);
	if (is_a_new_line(buffer))
		len += 1;
	back = (char *)ft_calloc(len + 1, sizeof(char));
	if (!back)
		return (line);
	if (line && buffer)
	{
		back = copy_ongoing(line, back);
		free(line);
		back = copy_ongoing(buffer, line);
	}
	return (back);
}

static void	remove_next_line(char *buffer, int next)
{
	char	*after_line;
	int		i;

	if (next == (int)ft_strlen(buffer))
	{
		ft_memset(buffer, 0, BUFFER_SIZE);
		return ;
	}
	after_line = buffer + next;
	i = 0;
	if (after_line[i] == '\n')
		after_line += 1;
	while (after_line[i])
	{
		buffer[i] = after_line[i];
		i++;
	}
	ft_memset(buffer + i, 0, BUFFER_SIZE - i);
}

static char	*check_line(int fd, char *line, char *buf, int *browsed)
{
	if (buf[0] != '\0')
	{
		line = fill_line(line, buf, find_next_line(buf) + ft_strlen(line));
		if (!line)
		{
			remove_next_line(buf, find_next_line(buf));
			return (0);
		}
	}
	if (buf[0] == '\0')
	{
		*browsed = read(fd, buf, BUFFER_SIZE);
		line = fill_line(line, buf, find_next_line(buf) + ft_strlen(line));
		if (!line)
		{
			remove_next_line(buf, find_next_line(buf));
			return (0);
		}
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1] = {0};
	char		*line;
	int			browsed;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	browsed = 1;
	line = NULL;
	while (browsed > 0)
	{
		line = check_line(fd, line, buf, &browsed);
		if (!line)
			return (NULL);
		remove_next_line(buf, find_next_line(buf));
		if (is_a_new_line(line) || browsed == 0)
			return (line);
	}
	if (line)
		free(line);
	return (NULL);
}
