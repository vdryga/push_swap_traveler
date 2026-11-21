/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 10:35:51 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/21 16:18:23 by vldryga          ###   ########.fr       */
/*   Updated: 2026/11/18 10:20:12 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	parse_instructions(t_list *head, t_pushswap *data)
{
	if (!ft_strcmp(head->content, "sa"))
		swap_a(data);
	else if (!ft_strcmp(head->content, "sb") && data->stack_b)
		swap_b(data);
	else if (!ft_strcmp(head->content, "ss") && data->stack_b && data->stack_a)
		ss(data);
	else if (!ft_strcmp(head->content, "ra"))
		rotate_a(data);
	else if (!ft_strcmp(head->content, "rb"))
		rotate_b(data);
	else if (!ft_strcmp(head->content, "rr"))
		rr(data);
	else if (!ft_strcmp(head->content, "pa") && data->stack_b)
		push_a(data);
	else if (!ft_strcmp(head->content, "pb") && data->stack_a)
		push_b(data);
	else if (!ft_strcmp(head->content, "rrb"))
		reverse_rotate_b(data);
	else if (!ft_strcmp(head->content, "rra"))
		reverse_rotate_a(data);
	else if (!ft_strcmp(head->content, "rrr"))
		rrr(data);
	else
		return (0);
	return (1);
}

static int	execute_instructions(t_pushswap *data, t_list *instructions)
{
	t_list	*head;
	int		error;

	head = instructions;
	while (head)
	{
		if (!parse_instructions(head, data))
			return (-1);
		head = head->next;
	}
	if (data->stack_a && !data->stack_b)
	{
		error = check_order(data->stack_a);
		if (error == 0)
			return (0);
	}
	else
		return (0);
	return (1);
}

static char	*fill_instructions(int fd)
{
	char	*ret;
	char	*temp;
	char	buf[BUFFER_SIZE + 1];
	int		bytes_read;

	ret = NULL;
	temp = NULL;
	bytes_read = read(fd, buf, BUFFER_SIZE);
	while (ret || bytes_read > 0)
	{
		temp = ft_strdup(ret);
		free(ret);
		ret = ft_calloc(ft_strlen(buf) + ft_strlen(ret), sizeof(char));
		if (!ret)
		{
			free(temp);
			return (NULL);
		}
		ret = ft_strjoin(buf, temp);
		free(temp);
		ft_memset(buf, 0, BUFFER_SIZE + 1);
		bytes_read = read(fd, buf, BUFFER_SIZE);
	}
	return (ret);
}

static int	get_instructions(t_list **instructions)
{
	char		*instr;
	char		**all_instr;
	int			i;

	instr = NULL;
	instr = fill_instructions(0);
	all_instr = ft_split(instr, '\n');
	free(instr);
	i = 0;
	while (all_instr)
	{
		bonus_add_instr(instructions, all_instr[i]);
		if (!instructions)
		{
			msg_error();
			if (instr)
				free(instr);
			ft_lstclear(instructions, del_list);
			return (1);
		}
		i++;
	}
	return (0);
}

static void	check_result(t_pushswap *data, t_list **instructions)
{
	int	error;

	error = execute_instructions(data, *instructions);
	if (error == -1)
		msg_error();
	else if (error == 0)
		ft_printf(1, "KO\n");
	else
		ft_printf(1, "OK\n");
}

int	main(int ac, char **av)
{
	t_pushswap	*data;
	t_list		*instructions;

	if (ac < 2)
	{
		msg_error();
		return (1);
	}
	data = pushswap_init();
	data->stack_a = parser(av, data->config);
	if (!data->stack_a || has_duplicate(data->stack_a)
		|| !has_no_flags(data->config))
	{
		msg_error();
		free_data(data);
		return (1);
	}
	instructions = NULL;
	if (!get_instructions(&instructions))
		check_result(data, &instructions);
	ft_lstclear(&instructions, del_list);
	free_data(data);
	return (0);
}
