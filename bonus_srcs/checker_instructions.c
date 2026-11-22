/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 17:47:41 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/21 17:53:57 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
	bytes_read = read(fd, buf, BUFFER_SIZE);
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


int	get_instructions(t_list **instructions)
{
	char		*instr;
	char		**all_instr;
	int			i;

	instr = NULL;
	instr = fill_instructions(0);
	all_instr = ft_split(instr, '\n');
	if (instr)
		free(instr);
	i = 0;
	while (all_instr[i])
	{
		bonus_add_instr(instructions, ft_strdup(all_instr[i]));
		if (!instructions)
		{
			msg_error();
			free_all(all_instr);
			ft_lstclear(instructions, del_list);
			return (1);
		}
		i++;
	}
	free_all(all_instr);
	free(all_instr);
	return (0);
}
