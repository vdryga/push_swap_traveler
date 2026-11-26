/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 14:02:28 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/26 11:22:44 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "push_swap.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// checker_utils_bonus.c
void	ss(t_pushswap *data);
void	rr(t_pushswap *data);
void	rrr(t_pushswap *data);
int		check_order(t_list *a);

// bonus_utils.c
void	free_all(char **tab);
t_bool	has_no_flags(t_config *flags);

// checker_instructions.c
char	*create_the_dup(char **str);
char	*fill_instructions(int fd);
int		get_instructions(t_list **instructions, t_bool *error);
int		parse_swaps(t_list *head, t_pushswap *data);

// original_split.c
char	**original_split(char const *s, char c);

#endif
