/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort_prevision.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbernad <arbernad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 12:49:00 by arbernad          #+#    #+#             */
/*   Updated: 2026/11/18 10:30:08 by arbernad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_target_bucket(t_list *stack, int bucket)
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

static void	calc_prev_total(t_ops *ops, t_direction dir)
{
	if (dir == B_TO_A)
	{
		if (ops->rt_a <= ops->revrt_a)
			ops->revrt_a = 0;
		else
			ops->rt_a = 0;;
	}
	ops->total = max(ops->rt_a, ops->rt_b) + max(ops->revrt_a, ops->revrt_b);
}

static t_ops	prevision_a_to_b(t_list *stack_b, int target, int flags, int pos)
{
	int		offset_f;
	int		offset_b;
	int		offset;
	t_ops	ops;

	ft_bzero(&ops, sizeof(t_ops));
	offset_f = bucket_dist_forward(stack_b, target, flags);
	offset_b = bucket_dist_backward(stack_b, target, flags);
	if (ft_abs(offset_f) < ft_abs(offset_b))
		offset = offset_f;
	else
		offset = offset_b;
	if (pos >= 0)
		ops.rt_a = pos;
	else
		ops.revrt_a = -pos;
	if (offset >= 0)
		ops.rt_b = offset;
	else
		ops.revrt_b = -offset;
	ops.total = max(ops.rt_a, ops.rt_b) + max(ops.revrt_a, ops.revrt_b);
	return (ops);
}

static t_ops	prev_b_to_a_smallest(t_pushswap *data, int small, int pos)
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

static t_ops	prev_b_to_a_biggest(t_pushswap *data, int big, int pos)
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

static t_ops	prev_b_to_a_middle(t_pushswap *data, int idx, int pos)
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

static t_ops	prevision_b_to_a(t_pushswap *data, int idx, int starting_pos)
{
	t_ops	ops;
	t_list	*node;
	int		smallest_a;
	int		biggest_a;

	node = data->stack_a;
	ft_bzero(&ops, sizeof(t_ops));
	if (starting_pos >= 0)
		ops.rt_b = starting_pos;
	else
		ops.revrt_b = -starting_pos;
	ops.total = max(ops.rt_b, ops.revrt_b);
	if (!node)
		return (ops);
	smallest_a = smallest_idx_in_stack(data->stack_a);
	biggest_a = biggest_idx_in_stack(data->stack_a);
	if (idx < smallest_a)
		ops = prev_b_to_a_smallest(data, smallest_a, starting_pos);
	else if (idx > biggest_a)
		ops = prev_b_to_a_biggest(data, biggest_a, starting_pos);
	else
		ops = prev_b_to_a_middle(data, idx, starting_pos);
	return (ops);
}

t_ops	get_b_to_a_prevision(t_pushswap *data, int idx, int starting_pos)
{
	t_ops	op1;
	t_ops	op2;

	op1 = prevision_b_to_a(data, idx, starting_pos);
	starting_pos -= data->b_size;
	op2 = prevision_b_to_a(data, idx, starting_pos);
	if (op1.total <= op2.total)
		return (op1);
	return (op2);
}

t_ops	get_a_to_b_prevision(t_pushswap *data, int bucket, int starting_pos)
{
	t_ops	op1;
	t_ops	op2;
	int		target_bucket;
	int		flag;

	target_bucket = get_target_bucket(data->stack_b, bucket);
	if (target_bucket == bucket || bucket == -1)
		flag = ANY;
	else if (target_bucket > bucket)
		flag = BOTTOM;
	else
		flag = TOP;
	op1 = prevision_a_to_b(data->stack_b, target_bucket, flag, starting_pos);
	starting_pos -= data->a_size;
	op2 = prevision_a_to_b(data->stack_b, target_bucket, flag, starting_pos);
	if (op1.total <= op2.total)
		return (op1);
	return (op2);
}
