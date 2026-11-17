/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 08:49:19 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/17 14:16:09 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_info(t_pushswap *data, t_turk *info, int rot)
{
	t_list	*head;

	head = data->stack_a;
	while (rot > 0)
	{
		rot--;
		head = head->next;
	}
	info->b_max = search_max_index(data->stack_b);
	info->b_min = search_min_index(data->stack_b);
	info->a_value = head->index;
	info->current = data->stack_b->index;
}

int	search_closest_index(t_list *a, int value, t_turk *info)
{
	int	max;
	int	curr;
	int	index;

	max = 2147483647;
	if (value < info->b_min)
	{
		max = search_max_index(a);
		return (max);
	}
	while (a)
	{
		curr = ft_abs(value - a->index);
		if (curr < max && value > a->index)
		{
			max = curr;
			index = a->index;
		}
		a = a->next;
	}
	return (index);
}

static t_ops	*get_node(t_pushswap *data, int rot)
{
	t_list	*head;
	t_ops	*curr;

	head = data->stack_a;
	while (rot > 0)
	{
		rot--;
		head = head->next;
	}
	curr = &head->prevision;
	return (curr);
}

static void	fill_rotations(t_pushswap *data, t_ops *c, t_turk *info)
{
	int		closest;
	t_list	*a;

	closest = search_closest_index(data->stack_b, info->a_value, info);
	a = data->stack_b;
	while (closest != a->index)
	{
		c->rt_b++;
		a = a->next;
		info->current = a->index;
	}
	if (c->rt_a > (data->a_size / 2))
		count_reverse_a(data, c);
	if (c->rt_b > (data->b_size / 2))
		count_reverse_b(data, c);
	c->total = count_total(c);
}

int	count_moves_for_one(t_pushswap *data, t_turk *info, int rotations)
{
	t_ops	*c;

	c = get_node(data, rotations);
	init_t_ops(c);
	c->rt_a = rotations;
	init_info(data, info, rotations);
	fill_rotations(data, c, info);
	return (c->total);
}
