/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 10:10:30 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/17 13:50:03 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	set_flags(char *str, t_config *flags)
{
	if (!ft_strcmp(str, "--bench"))
		flags->flag_bench = 1;
	else if (!ft_strcmp(str, "--simple"))
		flags->flag_simple = 1;
	else if (!ft_strcmp(str, "--medium"))
		flags->flag_medium = 1;
	else if (!ft_strcmp(str, "--complex"))
		flags->flag_complex = 1;
	else if (!ft_strcmp(str, "--adaptative"))
		flags->flag_adaptative = 1;
	else
		return (FALSE);
	return (TRUE);
}

static int	str_is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] && str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	check_errors(t_config *flags, t_list *head)
{
	if (has_flag_error(flags))
	{
		ft_lstclear(&head, del_list);
		return (1);
	}
	return (0);
}

static t_list	*create_node_in_stack_a(t_list *head, char **av, int i)
{
	int		*converted;
	t_list	*new;

	converted = (int *)malloc(sizeof(int));
	converted[0] = ft_atoi(av[i]);
	new = ft_lstnew(converted);
	ft_lstadd_back(&head, new);
	return (head);
}

t_list	*parser(char **av, t_config *flags)
{
	int		i;
	t_list	*head;

	i = 1;
	head = NULL;
	while (av[i] != NULL)
	{
		if (set_flags(av[i], flags) == TRUE)
		{
			i++;
			continue ;
		}
		if (!str_is_digit(av[i]) || ft_strlen(av[i]) == 0)
		{
			ft_lstclear(&head, del_list);
			return (NULL);
		}
		head = create_node_in_stack_a(head, av, i);
		i++;
	}
	if (check_errors(flags, head))
		return (NULL);
	return (head);
}
