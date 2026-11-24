/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbernad <abernade42@proton.me>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 07:56:10 by arbernad          #+#    #+#             */
/*   Updated: 2026/11/24 08:16:31 by arbernad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_pushswap *data)
{
	t_list *node;

	if (data->a_size < 3)
		return ;
	node = data->stack_a;
	while (node->index)
		node = lstnnext(node, 1);
	if (lstnnext(node, 1)->index != 1)
		swap_a(data);
	return ;
}
