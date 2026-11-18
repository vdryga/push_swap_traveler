/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_push_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbernad <arbernad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 16:14:24 by arbernad          #+#    #+#             */
/*   Updated: 2026/11/18 11:23:39 by arbernad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_pushswap *data, t_ops *rotations)
{
	while (rotations->rt_a)
	{
		rotate_a(data);
		rotations->rt_a--;
	}
	while (rotations->rt_b)
	{
		rotate_b(data);
		rotations->rt_b--;
	}
	while (rotations->revrt_a)
	{
		reverse_rotate_a(data);
		rotations->revrt_a--;
	}
	while (rotations->revrt_b)
	{
		reverse_rotate_b(data);
		rotations->revrt_b--;
	}
}

/**
 * `direction` is either `A_TO_B` or `B_TO_A` as defined in push_swap.h
 */
void	push_fastest(t_pushswap *data, t_direction direction)
{
	t_list	*node;
	t_ops	*fastest;

	fastest = NULL;
	if (direction == A_TO_B)
		node = data->stack_a;
	else
		node = data->stack_b;
	while (node)
	{
		if (!fastest || fastest->total > node->prevision.total)
			fastest = &node->prevision;
		node = node->next;
	}
	rotate(data, fastest);
	if (direction == A_TO_B)
		push_b(data);
	else
		push_a(data);
}

void	push_into_buckets(t_pushswap *data)
{
	t_list	*node;
	int		i;

	while (data->stack_a)
	{
		i = 0;
		node = data->stack_a;
		while (node)
		{
			ft_bzero(&node->prevision, sizeof(t_ops));
			node->prevision = get_a_to_b_prevision(data, node->bucket, i);
			node = node->next;
			i++;
		}
		push_fastest(data, A_TO_B);
	}
}
