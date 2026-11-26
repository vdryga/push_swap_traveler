/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 17:47:41 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/26 11:29:33 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	parse_swaps(t_list *head, t_pushswap *data)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(data->stack_a);
	size_b = ft_lstsize(data->stack_b);
	if (!ft_strcmp(head->content, "sa"))
	{
		swap_a(data);
		return (1);
	}
	else if (!ft_strcmp(head->content, "sb"))
	{
		swap_b(data);
		return (1);
	}
	else if (!ft_strcmp(head->content, "ss"))
	{
		ss(data);
		return (1);
	}
	else
		return (0);
}

char	*create_the_dup(char **str)
{
	char	*temp;

	temp = ft_strdup(*str);
	if (!temp)
	{
		free(*str);
		return (NULL);
	}
	free(*str);
	return (temp);
}

char	*fill_instructions(int fd)
{
	char		*ret;
	char		*temp;
	static char	buf[BUFFER_SIZE + 1] = {0};
	int			bytes_read;

	ret = NULL;
	temp = NULL;
	bytes_read = read(fd, buf, BUFFER_SIZE); //@inf : proteger le read.
	while (ret || bytes_read > 0)
	{
		temp = create_the_dup(&ret);
		ret = ft_strjoin(temp, buf);
		if (!ret)
		{
			free(temp);
			return (NULL);
		}
		if (temp)
			free(temp);
		ft_memset(buf, 0, BUFFER_SIZE + 1);
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == 0)
			break ;
	}
	return (ret);
}

static int	bonus_add_instr(t_list **instructions, char *instr)
{
	t_list	*node;
	int		len;

	if (!instr)
		return (1);
	len = ft_strlen(instr);
	if (len > 0 && instr[len - 1] == '\n')
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

static t_bool	add_an_instruction(t_list **instructions, char **all_instr, int i)
{
	bonus_add_instr(instructions, ft_strdup(all_instr[i]));
	if (!instructions)
	{
		msg_error();
		free_all(all_instr);
		ft_lstclear(instructions, del_list);
		return (TRUE);
	}
	return (FALSE);
}

int	get_instructions(t_list **instructions, t_bool *error)
{
	char		*instr;
	char		**all_instr;
	int			i;

	instr = NULL;
	instr = fill_instructions(0);
	if (!instr)
		return (1);
	all_instr = original_split(instr, '\n');
	if (instr)
		free(instr);
	i = 0;
	while (all_instr && all_instr[i])
	{
		if (add_an_instruction(instructions, all_instr, i))
		{
			*error = TRUE;
			return (0);
		}
		i++;
	}
	free_all(all_instr);
	return (0);
}
