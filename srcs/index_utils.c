/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 08:50:00 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/18 11:48:57 by arbernad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	smallest_idx_in_stack(t_list *stack)
{
	int	smallest;

	if (!stack)
		return (-1);
	smallest = stack->index;
	stack = stack->next;
	while (stack)
	{
		if (stack->index < smallest)
			smallest = stack->index;
		stack = stack->next;
	}
	return (smallest);
}

int	biggest_idx_in_stack(t_list *stack)
{
	int	biggest;

	if (!stack)
		return (-1);
	biggest = stack->index;
	stack = stack->next;
	while (stack)
	{
		if (stack->index > biggest)
			biggest = stack->index;
		stack = stack->next;
	}
	return (biggest);
}
