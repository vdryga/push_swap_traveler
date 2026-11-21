/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 14:02:28 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/21 14:39:58 by vldryga          ###   ########.fr       */
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
t_bool	is_an_instruction(char *str);

// bonus_utils.c
void	free_all(t_pushswap *data);
t_bool	has_no_flags(t_config *flags);


// get_next_line_utils.c
int		bonus_add_instr(t_list **instructions, char *instr);
size_t	find_next_line(const char *str);
char	*copy_ongoing(char *src, char *dest);

// get_next_line.c
char	*get_next_line(int fd);

#endif
