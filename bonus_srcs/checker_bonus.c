/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 10:35:51 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/23 10:04:41 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	parse_swaps(t_list *head, t_pushswap *data)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(data->stack_a);
	size_b = ft_lstsize(data->stack_b);
	if (!ft_strcmp(head->content, "sa") && (size_a >= 2))
	{
		swap_a(data);
		return (1);
	}
	else if (!ft_strcmp(head->content, "sb") && (size_b >= 2))
	{
		swap_b(data);
		return (1);
	}
	else if (!ft_strcmp(head->content, "ss") && (size_a >= 2 && size_b >= 2))
	{
		ss(data);
		return (1);
	}
	else
		return (0);
}

static int	parse_instructions(t_list *head, t_pushswap *data)
{
	if (parse_swaps(head, data))
		return (1);
	else if (!ft_strcmp(head->content, "ra") && data->stack_a)
		rotate_a(data);
	else if (!ft_strcmp(head->content, "rb") && data->stack_b)
		rotate_b(data);
	else if (!ft_strcmp(head->content, "rr") && data->stack_a && data->stack_b)
		rr(data);
	else if (!ft_strcmp(head->content, "pa") && data->stack_b)
		push_a(data);
	else if (!ft_strcmp(head->content, "pb") && data->stack_a)
		push_b(data);
	else if (!ft_strcmp(head->content, "rrb") && data->stack_b)
		reverse_rotate_b(data);
	else if (!ft_strcmp(head->content, "rra") && data->stack_a)
		reverse_rotate_a(data);
	else if (!ft_strcmp(head->content, "rrr") && data->stack_a && data->stack_b)
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
