/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbernad <arbernad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 14:14:14 by arbernad          #+#    #+#             */
/*   Updated: 2026/11/16 21:58:13 by arbernad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	dist_from_bucket_bottom(t_list *stack, int bucket)
{
	t_list	*head;
	int		offset;

	if (stack->bucket != bucket)
		return (0);
	offset = 1;
	head = stack;
	stack = lstnnext(stack , 1);
	while (stack->bucket == bucket)
	{
		if (stack == head)
			return (0);
		stack = lstnnext(stack, 1);
		offset++;
	}
	return (offset);
}

static int	dist_from_bucket_top(t_list *stack, int bucket)
{
	t_list	*head;
	int		offset;

	if (lstnprev(stack, 1)->bucket != bucket)
		return (0);
	offset = -1;
	head = stack;
	stack = lstnprev(stack , 1);
	while (lstnprev(stack , 1)->bucket == bucket)
	{
		if (stack == head)
			return (0);
		stack = lstnprev(stack, 1);
		offset--;
	}
	return (offset);
}

int	bucket_dist_forward(t_list *stack, int bucket, int position)
{
	int		offset;

	offset = 0;
	while (stack && stack->bucket != bucket)
	{
		stack = lstnnext(stack, 1);
		offset++;
	}
	if (position == ANY || !stack)
		return (offset);
	if (position == BOTTOM)
		offset += dist_from_bucket_bottom(stack, bucket);
	else
		offset += dist_from_bucket_top(stack, bucket);
	return (offset);
}

int	bucket_dist_backward(t_list *stack, int bucket, int position)
{
	int		offset;

	offset = 0;
	while (stack && stack->bucket != bucket)
	{
		stack = lstnprev(stack, 1);
		offset--;
	}
	if (position == ANY || !stack)
		return (offset);
	if (position == BOTTOM)
		offset += dist_from_bucket_bottom(stack, bucket);
	else
		offset += dist_from_bucket_top(stack, bucket);
	return (offset);
}

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
