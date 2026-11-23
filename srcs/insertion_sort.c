/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 08:44:32 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/23 13:38:05 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	search_closest_value(t_list *a, int value, int sorted)
{
	int	max;
	int	curr;
	int	index;

	max = 2147483647;
	a = ft_lstlast(a);
	while (sorted > 0)
	{
		curr = ft_abs(value - a->index);
		if (curr < max && value < a->index)
		{
			max = curr;
			index = a->index;
		}
		a = a->prev;
		sorted--;
	}
	return (index);
}

static void	middle_insert(t_pushswap *data, int sorted, int value_b)
{
	int	found;
	int	count;

	count = 0;
	found = search_closest_value(data->stack_a, value_b, sorted);
	while (found != data->stack_a->index)
	{
		reverse_rotate_a(data);
		count++;
	}
	push_a(data);
	if (!is_stack_a_sorted(data))
		multi_rotations(data, count + 1, 'a');
}

static void	min_insert(t_pushswap *data, int min_sorted)
{
	int	count;

	count = 0;
	while (min_sorted != data->stack_a->index)
	{
		reverse_rotate_a(data);
		count++;
	}
	push_a(data);
	if (!is_stack_a_sorted(data))
		multi_rotations(data, count + 1, 'a');
}

static void	search_right_insert(int sorted, t_pushswap *data)
{
	int	value_b;
	int	min_sorted;

	value_b = data->stack_b->index;
	min_sorted = search_min_value(data->stack_a, sorted);
	if (value_b < min_sorted)
		min_insert(data, min_sorted);
	else
		middle_insert(data, sorted, value_b);
}

void	insertion_sort(t_pushswap *data, int size)
{
	int	sorted;

	if (order_first_two(data))
		return ;
	sorted = 2;
	while (sorted < size)
	{
		if (data->stack_a->index > data->stack_a->next->index)
			swap_a(data);
		if (data->stack_a->index < lstnprev(data->stack_a, 1)->index)
		{
			push_b(data);
			search_right_insert(sorted, data);
			if (is_stack_a_sorted(data))
				return ;
		}
		else
			rotate_a(data);
		if (is_stack_a_sorted(data))
			return ;
		sorted++;
	}
}
