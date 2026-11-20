/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 15:32:21 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/20 09:52:20 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> //à enlever !!!
# include "libft/libft.h"
# include "printf/ft_printf.h"

/**
 *  Bucket sort related macros
 *
 * 	Flags to be used in `bucket_offset_forward`
 * 	and `bucket_offset_backward` functions
 * 	`ANY` is equivalent to `TOP | BOTTOM`
 */
# define TOP 1
# define BOTTOM 2
# define ANY 3

# define INT_MAX 2147483647
# define INT_MIN -2147483648

enum
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
};

typedef enum s_direction
{
	A_TO_B,
	B_TO_A
}	t_direction;

typedef enum s_bool
{
	FALSE = 0,
	TRUE
}	t_bool;

typedef struct s_config
{
	t_bool	flag_simple;
	t_bool	flag_medium;
	t_bool	flag_complex;
	t_bool	flag_adaptive;
	t_bool	flag_bench;
	float	disorder;
}	t_config;

typedef struct s_pushswap
{
	t_config	*config;
	t_list		*stack_a;
	t_list		*stack_b;
	t_list		*instructions;
	int			a_size;
	int			b_size;
}	t_pushswap;

typedef struct s_turk
{
	int	b_max;
	int	b_min;
	int	a_value;
	int	current;
}	t_turk;

/**
 *	/!\ TO BE DELETED /!\
 * 	test_utils.c functions and bitflags
 */
#define PRINT_NB 1
#define PRINT_IDX 2
#define PRINT_BUCKET 4
#define PRINT_INSTRUCTIONS 8
#define PRINT_PREVISION_A 16
#define PRINT_PREVISION_B 32

void		print_stacks(t_pushswap *data, int bitflags);
void		print_config(t_config *config);
void		printf_stacks(t_pushswap *data);

// main.c
void		print_instruction_list(t_pushswap *data);

// frees.c
void		free_data(t_pushswap *data);

//push_swap.c
t_pushswap	*pushswap_init(void);

// parser.c
t_list		*parser(char **av, t_config *flags);
double		disorder(t_list *list_a, unsigned int size);

// error.c
t_bool		has_flag_error(t_config *config);
t_bool		has_duplicate(t_list *lst);
void		msg_error(void);
void		del_list(void *content);

// op_push_swap.c
void		swap_a(t_pushswap *data);
void		swap_b(t_pushswap *data);
void		push_a(t_pushswap *data);
void		push_b(t_pushswap *data);

// op_rotate.c
void		rotate_a(t_pushswap *data);
void		rotate_b(t_pushswap *data);
void		reverse_rotate_a(t_pushswap *data);
void		reverse_rotate_b(t_pushswap *data);

// op_utils.c
int			add_instr(t_list **instructions, int instr);
void		multi_rotations(t_pushswap *data, int rotations, char stack);
void		reverse_multi_rotations(t_pushswap *data, int rotations,
				char stack);
t_bool		is_rotation_str(char *str);

// rotation_list_utils.c
t_list		*create_rotation_list(t_ops *rotations);

// op_optimize.c
int			optimize_rotations(t_list **op_lst);

// lst_utils.c
t_list		*lstnnext(t_list *node, int offset);
t_list		*lstnprev(t_list *node, int offset);

// math_utils.c
int			ft_abs(int n);
int			ft_sqrt(int n);
int			max(int a, int b);
int			min(int a, int b);

// print_bench.c
void		print_bench(t_pushswap *data);

	/**
	*	BUCKET SORT
	*/

// bucket_sort.c
void		bucket_sort(t_pushswap *data);

// bucket_push_b.c
void		push_into_buckets(t_pushswap *data);

// bucket_init.c
void		bucket_init(t_pushswap *data);
void		push_fastest(t_pushswap *data, t_direction direction);

// bucket_sort_utils.c
int			bucket_dist_forward(t_list *stack, int bucket, int position);
int			bucket_dist_backward(t_list *stack, int bucket, int position);
int			smallest_idx_in_stack(t_list *stack);
int			biggest_idx_in_stack(t_list *stack);

// bucket_sort_prevision.c
t_ops		get_a_to_b_prevision(t_pushswap *data, int bucket,
				int starting_pos);
t_ops		get_b_to_a_prevision(t_pushswap *data, int idx, int starting_pos);

// bucket_sort_prev_utils.c
int			get_target_bucket(t_list *stack, int bucket);
void		calc_prev_total(t_ops *ops, t_direction dir);
t_ops		prev_b_to_a_smallest(t_pushswap *data, int small, int pos);
t_ops		prev_b_to_a_biggest(t_pushswap *data, int big, int pos);
t_ops		prev_b_to_a_middle(t_pushswap *data, int idx, int pos);

// indexer.c
void		indexer(t_pushswap *data);
void		smallest_on_top(t_pushswap *data);

// index_utils.c
int			search_min_index(t_list *a);
int			search_max_index(t_list *a);

//init_utils.c
t_config	*config_init(void);
t_pushswap	*pushswap_init(void);

// insertion_sort.c
void		insertion_sort(t_pushswap *data, int size);
t_bool		is_stack_a_sorted(t_pushswap *data);
t_bool		order_first_two(t_pushswap *data);

// insertion_sort_utils.c
int			search_min_value(t_list *a, int sorted);
int			search_max_value(t_list *a);

// radix.c
void		radix(t_pushswap *data);
int			search_biggest_index(t_list *a);

//turkish_sort.c
void		turk_sort(t_pushswap *data);

// turkish_utils.c
int			count_moves_for_one(t_pushswap *data, t_turk *info, int rotations);
void		count_reverse_a(t_pushswap *data, t_ops *c);
void		count_reverse_b(t_pushswap *data, t_ops *c);

#endif
