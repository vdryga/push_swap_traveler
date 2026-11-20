#ifndef INPUT_GEN_H
# define INPUT_GEN_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum s_bool {
	FALSE,
	TRUE
}	t_bool;

typedef enum s_swap_flag {
	ORDER,
	DISORDER
}	t_swap_flag;

double	calc_disorder(int *list_a, unsigned int size);
int		*create_stack(int size);
int		*create_reversed_stack(int size);
void	reorganize(int *stack, int size, int target_disorder);
void	deorganize(int *stack, int size, int target_disorder);

#endif
