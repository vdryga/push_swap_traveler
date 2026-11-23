/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extraction_method.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbernad <arbernad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 13:05:05 by arbernad          #+#    #+#             */
/*   Updated: 2026/11/23 14:15:08 by arbernad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_smallest_offset(t_list *stack, int smallest_idx)
{
	t_list	*node;
	int		forward;
	int		backward;

	forward = 0;
	backward = 0;
	node = stack;
	while (node->index != smallest_idx)
	{
		forward++;
		node = lstnnext(node, 1);
	}
	while (stack->index != smallest_idx)
	{
		backward++;
		stack = lstnprev(stack, 1);
	}
	if (forward <= backward)
		return (forward);
	return (-backward);
}

void	extraction_method(t_pushswap *data)
{
	int	smallest;
	int	smallest_offset;

	smallest = 0;
	while (data->stack_a && data->stack_a->next)
	{
		smallest_offset = get_smallest_offset(data->stack_a, smallest);
		if (smallest_offset > 0)
			multi_rotations(data, smallest_offset, 'a');
		else if (smallest_offset < 0)
			reverse_multi_rotations(data, smallest_offset, 'a');
		push_b(data);
		smallest++;
	}
	while(data->stack_b)
		push_a(data);
}
