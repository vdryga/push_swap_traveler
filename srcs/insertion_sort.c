/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 08:44:32 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/16 12:07:58 by vldryga          ###   ########.fr       */
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

int	search_max_value(t_list *a, int sorted)
{
	t_list	*end = ft_lstlast(a);
	int		max;

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

static void	search_right_insert(int sorted, t_pushswap *data)
{
	int	count;
	int value_a;
	int value_b;
	int sorted_min;
	int sorted_max;

	count = 0;
	while (sorted > count)
	{
		value_a = *(int *)data->stack_a->content;
		value_b = *(int *)data->stack_b->content;
		sorted_min = search_min_value(data->stack_a, sorted);
		sorted_max = search_max_value(data->stack_a, sorted);
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
		else if (value_a > value_b)
		{
			push_a(data);
			count++;
			multi_rotations(data, count, 'a');
			return ;
		}
		reverse_rotate_a(data);
	}
}

void	insertion_sort(t_pushswap *data, int size)
{
	int	sorted;
	int	value_a;
	int	value_a1;

	value_a = *(int *)data->stack_a->content;
	value_a1 = *(int *)data->stack_a->next->content;
	sorted = 0;
	if (value_a > value_a1)
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
