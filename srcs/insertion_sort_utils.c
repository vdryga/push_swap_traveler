/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 18:29:09 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/16 18:29:54 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_min_value(t_list *a, int sorted)
{
	t_list	*end;
	int		min;

	end = ft_lstlast(a);
	min = *(int *)end->content;
	while (sorted > 0)
	{
		if (min > *(int *)end->content)
			min = *(int *)end->content;
		end = end->prev;
		sorted--;
	}
	return (min);
}

int	search_max_value(t_list *a)
{
	t_list	*end;
	int		max;

	end = ft_lstlast(a);
	max = *(int *)end->content;
	return (max);
}
