/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbernad <arbernad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 10:26:38 by arbernad          #+#    #+#             */
/*   Updated: 2026/11/18 15:07:44 by arbernad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_pushswap *data)
{
	t_list	*next_b;

	next_b = data->stack_b->next;
	if (data->stack_a)
	{
		if (data->stack_b->next)
			data->stack_b->next->prev = NULL;
		data->stack_b->next = data->stack_a;
		data->stack_a->prev = data->stack_b;
	}
	else
		data->stack_b->next = NULL;
	data->stack_a = data->stack_b;
	data->stack_a->prev = NULL;
	data->stack_b = next_b;
	if (next_b)
		next_b->prev = NULL;
	if (add_instr(&data->instructions, PA))
	{
		free_data(data);
		exit(1);
	}
	data->a_size++;
	data->b_size--;
}

void	push_b(t_pushswap *data)
{
	t_list	*next_a;

	next_a = data->stack_a->next;
	if (data->stack_b)
	{
		if (data->stack_a->next)
			data->stack_a->next->prev = NULL;
		data->stack_a->next = data->stack_b;
		data->stack_b->prev = data->stack_a;
	}
	else
		data->stack_a->next = NULL;
	data->stack_b = data->stack_a;
	data->stack_b->prev = NULL;
	data->stack_a = next_a;
	if (next_a)
		next_a->prev = NULL;
	if (add_instr(&data->instructions, PB))
	{
		free_data(data);
		exit(1);
	}
	data->a_size--;
	data->b_size++;
}

void	swap_a(t_pushswap *data)
{
	t_list	*second_node;

	second_node = data->stack_a->next;
	data->stack_a->next = second_node->next;
	data->stack_a->prev = second_node;
	second_node->next = data->stack_a;
	data->stack_a = second_node;
	second_node->prev = NULL;
	if (add_instr(&data->instructions, SA))
	{
		free_data(data);
		exit(1);
	}
}

void	swap_b(t_pushswap *data)
{
	t_list	*second_node;

	second_node = data->stack_b->next;
	data->stack_b->next = second_node->next;
	data->stack_b->prev = second_node;
	second_node->next = data->stack_b;
	data->stack_b = second_node;
	second_node->prev = NULL;
	if (add_instr(&data->instructions, SB))
	{
		free_data(data);
		exit(1);
	}
}
