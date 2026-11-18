/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbernad <arbernad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 14:31:19 by arbernad          #+#    #+#             */
/*   Updated: 2026/11/18 15:00:15 by arbernad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// returns 0 on success, returns 1 on malloc error
void	rotate_a(t_pushswap *data)
{
	t_list	*node;

	node = data->stack_a;
	if (!node || !node->next)
		return ;
	data->stack_a = node->next;
	ft_lstadd_back(&data->stack_a, node);
	if (add_instr(&data->instructions, RA))
	{
		free_data(data);
		exit(1);
	}
}

void	rotate_b(t_pushswap *data)
{
	t_list	*node;

	node = data->stack_b;
	if (!node || !node->next)
		return ;
	data->stack_b = node->next;
	ft_lstadd_back(&data->stack_b, node);
	if (add_instr(&data->instructions, RB))
	{
		free_data(data);
		exit(1);
	}
}

void	reverse_rotate_a(t_pushswap *data)
{
	t_list	*node;

	node = ft_lstlast(data->stack_a);
	if (!node || !node->prev)
		return ;
	node->prev->next = NULL;
	ft_lstadd_front(&data->stack_a, node);
	if (add_instr(&data->instructions, RRA))
	{
		free_data(data);
		exit(1);
	}
}

void	reverse_rotate_b(t_pushswap *data)
{
	t_list	*node;

	node = ft_lstlast(data->stack_b);
	if (!node || !node->prev)
		return ;
	node->prev->next = NULL;
	ft_lstadd_front(&data->stack_b, node);
	if (add_instr(&data->instructions, RRB))
	{
		free_data(data);
		exit(1);
	}
}
