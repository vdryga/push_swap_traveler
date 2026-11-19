/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 10:10:18 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/19 13:54:35 by arbernad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_instruction_list(t_pushswap *data)
{
	t_list	*instr;

	instr = data->instructions;
	while (instr)
	{
		ft_printf("%s\n", (char *)instr->content);
		instr = instr->next;
	}
}

static void	start_sorting(t_pushswap *data, t_config *info)
{
	if (info->disorder == 0 || data->a_size <= 1)
	{
		if (info->flag_bench)
			print_bench(data);
		free_data(data);
		exit(0);
	}
	if (info->flag_simple)
		insertion_sort(data, data->a_size);
	else if (info->flag_medium)
		bucket_sort(data);
	else if (info->flag_complex)
		radix(data);
	else
	{
		if (info->disorder < 0.2)
			insertion_sort(data, data->a_size);
		if (info->disorder >= 0.2 && info->disorder < 0.5)
			bucket_sort(data);
		if (info->disorder >= 0.5)
			radix(data);
	}
}

static int	error_checker(t_pushswap *data, char **av)
{
	data->stack_a = parser(av, data->config);
	if (!data->stack_a)
	{
		free_data(data);
		msg_error();
		return (1);
	}
	if (has_flag_error(data->config))
	{
		free_data(data);
		msg_error();
		return (1);
	}
	if (has_duplicate(data->stack_a))
	{
		free_data(data);
		msg_error();
		return (1);
	}
	return (0);
}

int	main(int argc, char **av)
{
	t_pushswap		*data;

	if (argc < 2)
		return (1);
	data = pushswap_init();
	if (!data)
		return (1);
	if (error_checker(data, av))
		return (1);
	data->a_size = ft_lstsize(data->stack_a);
	data->config->disorder = disorder(data->stack_a, data->a_size);
	indexer(data);
	if (data->config->disorder != 0)
		start_sorting(data, data->config);
	smallest_on_top(data);
	optimize_rotations(&data->instructions);
	print_instruction_list(data);
	if (data->config->flag_bench)
		print_bench(data);
	free_data(data);
	return (0);
}
