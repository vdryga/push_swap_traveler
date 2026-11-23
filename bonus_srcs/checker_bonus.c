/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 10:35:51 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/23 11:20:23 by arbernad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	parse_instructions(t_list *head, t_pushswap *data)
{
	if (!ft_strcmp(head->content, "sa"))
		swap_a(data);
	else if (!ft_strcmp(head->content, "sb"))
		swap_b(data);
	else if (!ft_strcmp(head->content, "ss"))
		ss(data);
	else if (!ft_strcmp(head->content, "ra"))
		rotate_a(data);
	else if (!ft_strcmp(head->content, "rb"))
		rotate_b(data);
	else if (!ft_strcmp(head->content, "rr"))
		rr(data);
	else if (!ft_strcmp(head->content, "pa"))
		push_a(data);
	else if (!ft_strcmp(head->content, "pb"))
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

static int	skip(t_list *node, t_pushswap *data)
{
	if ((!ft_strcmp(node->content, "pa") && !data->stack_b)
		|| (!ft_strcmp(node->content, "pb") && !data->stack_a))
		return (1);
	return (0);
}

static int	execute_instructions(t_pushswap *data, t_list *instructions)
{
	t_list	*head;
	int		error;

	head = instructions;
	while (head)
	{
		if (!skip(head, data))
		{
			if (!parse_instructions(head, data))
				return (-1);
		}
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
