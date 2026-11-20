/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_optimize_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbernad <arbernad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 16:05:49 by arbernad          #+#    #+#             */
/*   Updated: 2026/11/20 16:06:02 by arbernad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_rotation(t_ops *rotations, char *str)
{
	if (!ft_strcmp(str, "ra"))
		rotations->rt_a++;
	else if (!ft_strcmp(str, "rb"))
		rotations->rt_b++;
	else if (!ft_strcmp(str, "rra"))
		rotations->revrt_a++;
	else if (!ft_strcmp(str, "rrb"))
		rotations->revrt_b++;
	else if (!ft_strcmp(str, "rr"))
		rotations->rt_ab++;
	else if (!ft_strcmp(str, "rrr"))
		rotations->revrt_ab++;
}
