/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbernad <arbernad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 10:23:02 by arbernad          #+#    #+#             */
/*   Updated: 2026/11/16 22:57:36 by arbernad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_buckets_in_stack_a(t_pushswap *data)
{
	t_list	*node;
	int		pos;

	while (data->stack_b)
	{
		pos = 0;
		node = data->stack_b;
		while (node)
		{
			node->prevision = get_b_to_a_prevision(data, node->index, pos);
			node = node->next;
			pos++; // when stack_a has 1 element and pos ==  492 (TESTargs.txt input)
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
