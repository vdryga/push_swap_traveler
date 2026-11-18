/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbernad <arbernad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 10:23:02 by arbernad          #+#    #+#             */
/*   Updated: 2026/11/18 11:41:36 by arbernad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_buckets_in_stack_a(t_pushswap *data)
{
	t_list	*node;
	int		pos;

	while (data->stack_b)
	{
		node = data->stack_b;
		pos = 0;
		while (node)
		{
			ft_bzero(&node->prevision, sizeof(t_ops));
			node->prevision = get_b_to_a_prevision(data, node->index, pos);
			node = node->next;
			pos++;
		}
		push_fastest(data, B_TO_A);
	}
}

void	bucket_sort(t_pushswap *data)
{
	bucket_init(data);
	push_into_buckets(data);
	sort_buckets_in_stack_a(data);
}
