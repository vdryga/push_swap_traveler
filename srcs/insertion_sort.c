/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 08:44:32 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/16 14:16:12 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_min_value(t_list *a, int sorted)
{
	t_list	*end = ft_lstlast(a);
	int		min;

	min = *(int *)end->content;
	while (sorted > 0)
	{
		if (min > *(int *)end->content)
			min = *(int *)end->content;
		end = end->prev;
		sorted--;
	}
	return (min);
}

int	search_max_value(t_list *a, int sorted, int size)
{
	t_list	*end;
	int		max;

	end = a;
	while (size > 0)
	{
		end = end->next;
		size--;
	}
	max = *(int *)end->content;
	while (sorted > 0)
	{
		if (max < *(int *)end->content)
			max = *(int *)end->content;
		end = end->prev;
		sorted--;
	}
	return (max);
}

static int search_closest_value(t_list *a, int value, int sorted_min, int *sorted, int size)
{
	int max = 2147483647;
	int	curr;
	int	index;

	if (value < sorted_min)
	{
		max = search_max_value(a, *sorted, size);
		return (max);
	}
	while (a)
	{
		curr = ft_abs(value - *(int *)a->content);
		if (curr < max && value > *(int *)a->content)
		{
			max = curr;
			index = *(int *)a->content;
		}
		a = a->next;
	}
	return (index);
}

static void	search_right_insert(int sorted, t_pushswap *data)
{
	int	count;
	int value_b;
	int sorted_min;
	int sorted_max;
	int	found;

	count = 0;
	value_b = *(int *)data->stack_b->content;
	sorted_min = search_min_value(data->stack_a, sorted);
	sorted_max = search_max_value(data->stack_a, sorted, data->a_size);
	if (sorted_min > value_b)
	{
		reverse_multi_rotations(data, sorted, 'a');
		push_a(data);
		multi_rotations(data, sorted + 1, 'a');
		return ;
	}
	else if (sorted_max < value_b)
	{
		push_a(data);
		rotate_a(data);
		return ;
	}
	found = search_closest_value(data->stack_a, value_b, sorted_min, &sorted, data->a_size);
	while (found != *(int *)data->stack_a)
	{
		reverse_rotate_a(data);
		count++;
	}
	push_a(data);
	while (count > 0)
	{
		rotate_a(data);
		count--;
	}
}

void	insertion_sort(t_pushswap *data, int size)
{
	int	sorted;

	sorted = 0;
	if (*(int *)data->stack_a->content > *(int *)data->stack_a->next->content)
	{
		swap_a(data);
		multi_rotations(data, 2, 'a');
	}
	else
		multi_rotations(data, 2, 'a');
	sorted = 2;
	while (sorted < size)
	{
		push_b(data);
		search_right_insert(sorted, data);
		sorted++;
	}
}
