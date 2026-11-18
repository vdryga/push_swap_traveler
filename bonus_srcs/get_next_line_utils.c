/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 16:06:03 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/18 11:24:28 by vldryga          ###   ########.fr       */
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

int	bonus_add_instr(t_list **instructions, char *instr)
{
	t_list	*node;
	int		len;

	if (!instr)
		return (1);
	len = ft_strlen(instr);
	if (instr[len - 1] == '\n')
		instr[len - 1] = '\0';
	node = ft_lstnew(instr);
	if (!node)
	{
		free(instr);
		return (1);
	}
	ft_lstadd_back(instructions, node);
	return (0);
}
