/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbernad <arbernad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 09:32:26 by arbernad          #+#    #+#             */
/*   Updated: 2026/11/20 10:30:46 by arbernad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_config(t_config *config)
{
	ft_printf("flag_simple:\t%d\n", config->flag_simple);
	ft_printf("flag_medium:\t%d\n", config->flag_medium);
	ft_printf("flag_complex:\t%d\n", config->flag_complex);
	ft_printf("flag_adaptative:\t%d\n", config->flag_adaptive);
	ft_printf("flag_bench:\t%d\n", config->flag_bench);
	ft_printf("disorder:\t%f\n\n", config->disorder);
}

/**
 * Debug function
 * Flags:
 * 	PRINT_NB, print element number
 * 	PRINT_IDX, print element index
 * 	PRINT_BUCKET, print element bucket number
 * 	PRINT_INSTRUCTIONS, print the instruction list after printing the stacks
 */
void	print_stacks(t_pushswap *data, int bitflags)
{
	t_list	*stack;

	ft_printf("\n===== STACKS =====\n\n");
	stack = data->stack_a;
	ft_printf("Stack A:\n");
	while (stack && bitflags & (PRINT_NB | PRINT_IDX | PRINT_BUCKET | PRINT_PREVISION_A))
	{
		if (bitflags & PRINT_NB)
			ft_printf("nb: %d\t", *(int *)stack->content);
		if (bitflags & PRINT_IDX)
			ft_printf("idx: %d\t", stack->index);
		if (bitflags & PRINT_BUCKET)
			ft_printf("bucket: %d\t", stack->bucket);
		if (bitflags & PRINT_PREVISION_A)
		{
			ft_printf("\nprevision: { total: %d", stack->prevision.total);
			if (stack->prevision.rt_a)
				ft_printf(", ra: %d", stack->prevision.rt_a);
			if (stack->prevision.rt_b)
				ft_printf(", rb: %d", stack->prevision.rt_b);
			if (stack->prevision.revrt_a)
				ft_printf(", rra: %d", stack->prevision.revrt_a);
			if (stack->prevision.revrt_b)
				ft_printf(", rrb: %d", stack->prevision.revrt_b);
			if (stack->prevision.psh_a)
				ft_printf(", pa: %d", stack->prevision.psh_a);
			if (stack->prevision.psh_b)
				ft_printf(", pb: %d", stack->prevision.psh_b);
			ft_printf(" }");
		}
		stack = stack->next;
		ft_printf("\n");
	}
	ft_printf("\n");

	stack = data->stack_b;
	ft_printf("Stack B:\n");
	while (stack && bitflags & (PRINT_NB | PRINT_IDX | PRINT_BUCKET | PRINT_PREVISION_B))
	{
		if (bitflags & PRINT_NB)
			ft_printf("nb: %d\t", *(int *)stack->content);
		if (bitflags & PRINT_IDX)
			ft_printf("idx: %d\t", stack->index);
		if (bitflags & PRINT_BUCKET)
			ft_printf("bucket: %d\t", stack->bucket);
		if (bitflags & PRINT_PREVISION_B)
		{
			ft_printf("\nprevision: { total: %d", stack->prevision.total);
			if (stack->prevision.rt_a)
				ft_printf(", ra: %d", stack->prevision.rt_a);
			if (stack->prevision.rt_b)
				ft_printf(", rb: %d", stack->prevision.rt_b);
			if (stack->prevision.revrt_a)
				ft_printf(", rra: %d", stack->prevision.revrt_a);
			if (stack->prevision.revrt_b)
				ft_printf(", rrb: %d", stack->prevision.revrt_b);
			if (stack->prevision.psh_a)
				ft_printf(", pa: %d", stack->prevision.psh_a);
			if (stack->prevision.psh_b)
				ft_printf(", pb: %d", stack->prevision.psh_b);
			ft_printf(" }");
		}
		stack = stack->next;
		ft_printf("\n");
	}
	ft_printf("\n");
	if (bitflags & PRINT_INSTRUCTIONS)
		print_instruction_list(data);
}

void	printf_stacks(t_pushswap *data)
{
	t_list	*head;

	head = data->stack_a;
	while (head)
	{
		ft_printf("[%d]", *(int *)head->content);
		head = head->next;
	}
	ft_printf("\n");
}
