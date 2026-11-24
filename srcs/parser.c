/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 10:10:30 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/20 09:53:28 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_all(char **tab)
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
	else if (!ft_strcmp(str, "--adaptive"))
		flags->flag_adaptive = 1;
	else
		return (FALSE);
	return (TRUE);
}

static int	str_is_digit(char *str)
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
	int		j;
	char	**splitted;
	t_list	*new;

	splitted = ft_split(av[i], ' ');
	if (!splitted)
		return (NULL);
	j = 0;
	while (splitted[j])
	{
		if (!str_is_digit(splitted[j]) || ft_strlen(splitted[j]) == 0)
		{
			free_all(splitted);
			free(splitted);
			ft_lstclear(&head, del_list);
			return (NULL);
		}
		converted = (int *)malloc(sizeof(int));
		converted[0] = ft_atoi(splitted[j]);
		new = ft_lstnew(converted);
		ft_lstadd_back(&head, new);
		j++;
	}
	free_all(splitted);
	free(splitted);
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
		head = create_node_in_stack_a(head, av, i);
		i++;
	}
	if (check_errors(flags, head))
		return (NULL);
	return (head);
}
