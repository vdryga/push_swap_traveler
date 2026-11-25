/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 10:10:30 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/25 09:57:52 by arbernad         ###   ########.fr       */
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

static void	free_parsed(char **split, t_list *head)
{
	free_all(split);
	free(split);
	ft_lstclear(&head, del_list);
}

static t_list	*create_node_in_stack_a(t_list *head, char **av, int i)
{
	int		*converted;
	int		j;
	char	**split;
	t_list	*new;

	split = ft_split(av[i], ' ');
	if (!split)
		return (NULL);
	j = 0;
	while (split[j])
	{
		if (!str_is_digit(split[j]) || ft_strlen(split[j]) == 0)
		{
			free_parsed(split, head);
			return (NULL);
		}
		converted = (int *)malloc(sizeof(int));
		converted[0] = ft_atoi(split[j]);
		new = ft_lstnew(converted);
		ft_lstadd_back(&head, new);
		j++;
	}
	free_all(split);
	free(split);
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
