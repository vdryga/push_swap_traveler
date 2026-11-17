/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_search.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 14:10:41 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/17 14:16:29 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	count_reverse_a(t_pushswap *data, t_ops *c)
{
	c->revrt_a = data->a_size - c->rt_a;
	c->rt_a = 0;
}

void	count_reverse_b(t_pushswap *data, t_ops *c)
{
	c->revrt_b = data->b_size - c->rt_b;
	c->rt_b = 0;
}

int	count_total(t_ops *c)
{
	int	max_rt;
	int	max_rvrt;
	int	total;

	max_rt = max(c->rt_a, c->rt_b);
	max_rvrt = max(c->revrt_a, c->revrt_b);
	total = max_rt + max_rvrt + 1;
	return (total);
}
