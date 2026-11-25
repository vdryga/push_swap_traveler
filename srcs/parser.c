/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 10:10:30 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/25 12:36:32 by vldryga          ###   ########.fr       */
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

static void	single_node(char *split, t_list **head)
{
	int		*converted;
	t_list	*new;

	converted = (int *)malloc(sizeof(int));
	converted[0] = ft_atoi(split);
	new = ft_lstnew(converted);
	ft_lstadd_back(head, new);
}

static t_list	*create_node_in_stack_a(t_list *head, char **av, int i)
{
	int		j;
	char	**split;

	split = ft_split(av[i], ' ');
	if (!split)
		return (NULL);
	j = 0;
	while (split[j])
	{
		if (!str_is_digit(split[j]) || ft_strlen(split[j]) == 0)
		{
			free_parsed(split);
			ft_lstclear(&head, del_list);
			return (NULL);
		}
		single_node(split[j], &head);
		j++;
	}
	free_parsed(split);
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
		if (!head)
			return (NULL);
		i++;
	}
	if (check_errors(flags, head))
		return (NULL);
	return (head);
}
