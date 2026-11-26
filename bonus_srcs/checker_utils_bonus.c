/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 14:39:33 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/26 10:08:08 by arbernad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rr(t_pushswap *data)
{
	if (data->stack_a && data->stack_a->next)
		rotate_a(data);
	if (data->stack_b && data->stack_b->next)
		rotate_b(data);
}

void	rrr(t_pushswap *data)
{
	if (data->stack_a && data->stack_a->next)
		reverse_rotate_a(data);
	if (data->stack_b && data->stack_b->next)
		reverse_rotate_b(data);
}

void	ss(t_pushswap *data)
{
	swap_a(data);
	swap_b(data);
}

int	check_order(t_list *a)
{
	t_list	*head;
	int		curr;
	int		prev;

	head = a;
	prev = *(int *)a->content;
	while (head)
	{
		head = head->next;
		if (!head)
			return (1);
		curr = *(int *)head->content;
		if (prev > curr)
			return (0);
		prev = curr;
	}
	return (1);
}
