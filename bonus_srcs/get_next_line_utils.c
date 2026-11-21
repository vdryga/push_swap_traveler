/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 16:06:03 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/21 14:39:50 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	find_next_line(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

char	*copy_ongoing(char *src, char *dest)
{
	int	i;

	i = 0;
	while (src && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	if (src && src[i] == '\n')
		dest[i] = '\n';
	return (dest);
}

int	bonus_add_instr(t_list **instructions, char *instr)
{
	t_list	*node;
	int		len;

	if (!instr)
		return (1);
	len = ft_strlen(instr);
	if (instr[len - 1] == '\n')
		ft_memset(instr + (len - 1), 0, 2);
	node = ft_lstnew(instr);
	if (!node)
	{
		free(instr);
		return (1);
	}
	ft_lstadd_back(instructions, node);
	return (0);
}
