/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 18:29:09 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/19 13:28:46 by arbernad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	is_stack_a_sorted(t_pushswap *data)
{
	t_list	*node;
	int		min;
	int		previous;

	min = search_min_value(data->stack_a, data->a_size);
	node = data->stack_a;
	while (*(int *)node->content != min)
		node = lstnnext(node, 1);
	node = lstnnext(node, 1);
	previous = min;
	while (*(int *)node->content != min)
	{
		if (previous > *(int *)node->content)
			return (FALSE);
		previous = *(int *)node->content;
		node = lstnnext(node, 1);
	}
	return (TRUE);
}

int	search_min_value(t_list *a, int sorted)
{
	t_list	*end;
	int		min;

	end = ft_lstlast(a);
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

int	search_max_value(t_list *a)
{
	t_list	*end;
	int		max;

	end = ft_lstlast(a);
	max = *(int *)end->content;
	return (max);
}

t_bool	order_first_two(t_pushswap *data)
{
	if (*(int *)data->stack_a->content > *(int *)data->stack_a->next->content)
	{
		swap_a(data);
		if (is_stack_a_sorted(data))
			return (TRUE);
		multi_rotations(data, 2, 'a');
	}
	else
		multi_rotations(data, 2, 'a');
	return (FALSE);
}
