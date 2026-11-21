/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 16:46:15 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/21 17:51:32 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_all(char **tab)
{
	int	i;

	if (!tab)
		return ;
	if (!*tab)
		free(tab);
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
}

t_bool	has_no_flags(t_config *flags)
{
	if (flags->flag_bench != 0 || flags->flag_simple != 0
		|| flags->flag_medium != 0 || flags->flag_complex != 0
		|| flags->flag_adaptive != 0)
		return (FALSE);
	return (TRUE);
}
