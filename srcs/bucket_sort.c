/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbernad <arbernad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 10:23:02 by arbernad          #+#    #+#             */
/*   Updated: 2026/11/17 21:23:09 by arbernad         ###   ########.fr       */
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
		// ft_printf("\n==================================\n\n");
		// print_stacks(data, PRINT_IDX | PRINT_PREVISION_B);
		push_fastest(data, B_TO_A);
	}
}

void	bucket_sort(t_pushswap *data)
{
	bucket_init(data);
	push_into_buckets(data);
	sort_buckets_in_stack_a(data);
}
