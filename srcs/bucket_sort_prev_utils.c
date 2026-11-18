/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort_prev_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbernad <arbernad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 11:27:02 by arbernad          #+#    #+#             */
/*   Updated: 2026/11/18 11:32:21 by arbernad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_target_bucket(t_list *stack, int bucket)
{
	int	closest;

	closest = -1;
	while (stack)
	{
		if (stack->bucket == bucket)
			return (bucket);
		else if (ft_abs(stack->bucket - bucket) < ft_abs(closest - bucket)
			|| closest == -1)
		{
			closest = stack->bucket;
		}
		stack = stack->next;
	}
	return (closest);
}

void	calc_prev_total(t_ops *ops, t_direction dir)
{
	if (dir == B_TO_A)
	{
		if (ops->rt_a <= ops->revrt_a)
			ops->revrt_a = 0;
		else
			ops->rt_a = 0;
	}
	ops->total = max(ops->rt_a, ops->rt_b) + max(ops->revrt_a, ops->revrt_b);
}

t_ops	prev_b_to_a_smallest(t_pushswap *data, int small, int pos)
{
	t_ops	ops;
	t_list	*node;

	node = data->stack_a;
	ft_bzero(&ops, sizeof(t_ops));
	if (pos >= 0)
		ops.rt_b = pos;
	else
		ops.revrt_b = -pos;
	while (node->index != small)
	{
		ops.rt_a++;
		node = lstnnext(node, 1);
	}
	node = data->stack_a;
	while (node->index != small)
	{
		ops.revrt_a++;
		node = lstnprev(node, 1);
	}
	calc_prev_total(&ops, B_TO_A);
	return (ops);
}

t_ops	prev_b_to_a_biggest(t_pushswap *data, int big, int pos)
{
	t_ops	ops;
	t_list	*node;

	node = data->stack_a;
	ft_bzero(&ops, sizeof(t_ops));
	if (pos >= 0)
		ops.rt_b = pos;
	else
		ops.revrt_b = -pos;
	while (lstnprev(node, 1)->index != big)
	{
		ops.rt_a++;
		node = lstnnext(node, 1);
	}
	node = data->stack_a;
	while (lstnprev(node, 1)->index != big)
	{
		ops.revrt_a++;
		node = lstnprev(node, 1);
	}
	calc_prev_total(&ops, B_TO_A);
	return (ops);
}

t_ops	prev_b_to_a_middle(t_pushswap *data, int idx, int pos)
{
	t_ops	ops;
	t_list	*node;

	ft_bzero(&ops, sizeof(t_ops));
	node = data->stack_a;
	if (pos >= 0)
		ops.rt_b = pos;
	else
		ops.revrt_b = -pos;
	while (node->index < idx || lstnprev(node, 1)->index > idx)
	{
		ops.rt_a++;
		node = lstnnext(node, 1);
	}
	node = data->stack_a;
	while (node->index < idx || lstnprev(node, 1)->index > idx)
	{
		ops.revrt_a++;
		node = lstnprev(node, 1);
	}
	calc_prev_total(&ops, B_TO_A);
	return (ops);
}
