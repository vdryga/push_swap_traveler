/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 14:39:33 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/21 17:51:28 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rr(t_pushswap *data)
{
	rotate_a(data);
	rotate_b(data);
}

void	rrr(t_pushswap *data)
{
	reverse_rotate_a(data);
	reverse_rotate_b(data);
}

void	ss(t_pushswap *data)
{
	swap_a(data);
	swap_b(data);
}

int	check_order(t_list *a)
{
	t_list	*head;
	int		curr;
	int		prev;

	head = a;
	prev = *(int *)a->content;
	while (a)
	{
		a = a->next;
		if (!a)
			return (1);
		curr = *(int *)a->content;
		if (prev > curr)
			return (0);
		prev = curr;
	}
	return (1);
}
