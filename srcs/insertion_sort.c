/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 08:44:32 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/18 17:13:48 by arbernad         ###   ########.fr       */
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
		curr = ft_abs(value - *(int *)a->content);
		if (curr < max && value < *(int *)a->content)
		{
			max = curr;
			index = *(int *)a->content;
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
	while (found != *(int *)data->stack_a->content)
	{
		reverse_rotate_a(data);
		count++;
	}
	push_a(data);
	multi_rotations(data, count + 1, 'a');
	return ;
}

static void	min_insert(t_pushswap *data, int min_sorted)
{
	int	count;

	count = 0;
	while (min_sorted != *(int *)data->stack_a->content)
	{
		reverse_rotate_a(data);
		count++;
	}
	push_a(data);
	multi_rotations(data, count + 1, 'a');
}

static void	search_right_insert(int sorted, t_pushswap *data)
{
	int	value_b;
	int	max_sorted;
	int	min_sorted;

	value_b = *(int *)data->stack_b->content;
	max_sorted = search_max_value(data->stack_a);
	min_sorted = search_min_value(data->stack_a, sorted);
	if (value_b > max_sorted)
	{
		push_a(data);
		rotate_a(data);
		return ;
	}
	if (value_b < min_sorted)
		min_insert(data, min_sorted);
	else
		middle_insert(data, sorted, value_b);
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
