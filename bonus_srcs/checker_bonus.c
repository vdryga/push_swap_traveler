/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 10:35:51 by vldryga           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/11/18 10:20:12 by vldryga          ###   ########.fr       */
=======
/*   Updated: 2026/11/16 11:35:14 by arbernad         ###   ########.fr       */
>>>>>>> bucket_opti
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	free_all(t_pushswap *data)
{
	free(data->config);
	ft_lstclear(&data->stack_a, &del_list);
	ft_lstclear(&data->stack_b, &del_list);
	ft_lstclear(&data->instructions, &del_list);
	free(data);
}

t_bool	is_an_instruction(char *str)
{
	if (!ft_strcmp(str, "sa") || !ft_strcmp(str, "sb"))
		return (1);
	if (!ft_strcmp(str, "ra") || !ft_strcmp(str, "rb") || !ft_strcmp(str, "rr"))
		return (1);
	if (!ft_strcmp(str, "pa") || !ft_strcmp(str, "pb"))
		return (1);
	if (!ft_strcmp(str, "rra") || !ft_strcmp(str, "rrb") || !ft_strcmp(str, "rrr"))
		return (1);
	return (0);
}

static int	parse_instructions(t_list *head, t_pushswap *data)
{
		if (ft_strcmp(head->content, "sa"))
			swap_a(data);
		if (ft_strcmp(head->content, "sb"))
			swap_b(data);
		if (ft_strcmp(head->content, "ss"))
			ss(data);
		if (ft_strcmp(head->content, "ra"))
			rotate_a(data);
		if (ft_strcmp(head->content, "rb"))
			rotate_b(data);
		if (ft_strcmp(head->content, "rr"))
			rr(data);
		if (ft_strcmp(head->content, "pa"))
			push_a(data);
		if (ft_strcmp(head->content, "pb"))
			push_b(data);
		if (ft_strcmp(head->content, "rrb"))
			reverse_rotate_b(data);
		if (ft_strcmp(head->content, "rra"))
			reverse_rotate_a(data);
		if (ft_strcmp(head->content, "rrr"))
			rrr(data);
		else
<<<<<<< HEAD
			return (0);
		return (1);
=======
		{
			if (data->instructions)
				free_all(data);
			ft_printf("Error\n");
			return ;
		}
		i++;
	}
>>>>>>> bucket_opti
}

static int	execute_instructions(t_pushswap *data)
{
	t_list	*head;

	head = data->instructions;
	while (head)
	{
		if (!parse_instructions(data->instructions, data))
		{
			ft_lstclear(&data->instructions, del_list);
			return (0);
		}
		head = head->next;
	}
	if (!check_order(data->stack_a))
		return (0);
	return (1);
}


int	main(int ac, char **av)
{
	t_pushswap *data;
	char		*instr = NULL;

	if (ac < 2)
		return (1);
	data = pushswap_init();
	data->stack_a = parser(av, data->config);
	if (!data->stack_a)
		return (1);
	instr = get_next_line(0);
	while (instr)
	{
		bonus_add_instr(&data->instructions, instr);
		if (!data->instructions)
		{
			free_all(data);
			return (1);
		}
		instr = get_next_line(0);
	}
<<<<<<< HEAD
	if (!execute_instructions(data))
=======
	ft_printf("instr [%s]", instr);
	parse_instructions(data, instr);
	if (!data->instructions)
	{
>>>>>>> bucket_opti
		free_all(data);
	return (0);
}
