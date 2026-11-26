/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 10:10:30 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/26 10:30:32 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_parsed(char **split)
{
	int	i;

	i = 0;
	while (split && split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	single_node(char *split, t_list **head)
{
	int		*converted;
	t_list	*new;

	converted = (int *)malloc(sizeof(int));
	if (!converted)
		return (0);
	converted[0] = ft_atoi(split);
	new = ft_lstnew(converted);
	if (!new)
		return (0);
	ft_lstadd_back(head, new);
	return (1);
}

static t_list	*create_node_in_stack_a(t_list *head, char **av, int i, t_bool *error)
{
	int		j;
	char	**split;

	split = ft_split(av[i], ' ');
	if (!split)
	{
		*error = TRUE;
		return (NULL);
	}
	j = 0;
	while (split[j])
	{
		if (!str_is_digit(split[j]) || ft_strlen(split[j]) == 0 || !single_node(split[j], &head))
		{
			free_parsed(split);
			ft_lstclear(&head, del_list);
			*error = TRUE;
			return (NULL);
		}
		j++;
	}
	free_parsed(split);
	return (head);
}

t_list	*parser(char **av, t_config *flags)
{
	int		i;
	t_list	*head;
	t_bool	error;

	i = 1;
	head = NULL;
	error = FALSE;
	while (av && av[i])
	{
		if (set_flags(av[i], flags) == TRUE)
		{
			i++;
			continue ;
		}
		head = create_node_in_stack_a(head, av, i, &error);
		if (!head && error == TRUE)
			return (NULL);
		i++;
	}
	if (check_errors(flags, head))
		return (NULL);
	return (head);
}
