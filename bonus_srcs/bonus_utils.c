/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 16:46:15 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/20 13:52:15 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_all(t_pushswap *data)
{
	free(data->config);
	ft_lstclear(&data->stack_a, &del_list);
	ft_lstclear(&data->stack_b, &del_list);
	ft_lstclear(&data->instructions, &del_list);
	free(data);
}

t_bool	has_no_flags(t_config *flags)
{
	if (flags->flag_bench != 0 || flags->flag_simple != 0
		|| flags->flag_medium != 0 || flags->flag_complex != 0
		|| flags->flag_adaptive != 0)
		return (FALSE);
	return (TRUE);
}
