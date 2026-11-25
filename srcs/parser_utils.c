/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbernad <arbernad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 09:41:48 by arbernad          #+#    #+#             */
/*   Updated: 2026/11/25 09:45:45 by arbernad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	set_flags(char *str, t_config *flags)
{
	if (!ft_strcmp(str, "--bench"))
		flags->flag_bench = 1;
	else if (!ft_strcmp(str, "--simple"))
		flags->flag_simple = 1;
	else if (!ft_strcmp(str, "--medium"))
		flags->flag_medium = 1;
	else if (!ft_strcmp(str, "--complex"))
		flags->flag_complex = 1;
	else if (!ft_strcmp(str, "--adaptive"))
		flags->flag_adaptive = 1;
	else
		return (FALSE);
	return (TRUE);
}

int	str_is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i]
		&& (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r')))
		i++;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] == '0')
		i++;
	if (ft_strlen(&str[i]) > 10
		|| ft_atoll(str) > INT_MAX || ft_atoll(str) < INT_MIN)
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_errors(t_config *flags, t_list *head)
{
	if (has_flag_error(flags))
	{
		ft_lstclear(&head, del_list);
		return (1);
	}
	return (0);
}
