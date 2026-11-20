#include "input_gen.h"

static void	swap(int *a, int *b)
{
	int	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	random_swap(int *stack, int size, t_swap_flag flag)
{
	int	rand_idx = rand() % size;

	if (rand_idx == 0)
	{
		if ((flag == ORDER && stack[rand_idx] > stack[rand_idx + 1])
			|| (flag == DISORDER && stack[rand_idx] < stack[rand_idx + 1]))
			swap(&stack[rand_idx], &stack[rand_idx + 1]);
	}
	else if (rand_idx == size - 1)
	{
		if ((flag == ORDER && stack[rand_idx] < stack[rand_idx - 1])
			|| (flag == DISORDER && stack[rand_idx] > stack[rand_idx - 1]))
			swap(&stack[rand_idx], &stack[rand_idx - 1]);
	}
	else
	{
		if ((flag == ORDER && stack[rand_idx] > stack[rand_idx + 1])
			|| (flag == DISORDER && stack[rand_idx] < stack[rand_idx + 1]))
			swap(&stack[rand_idx], &stack[rand_idx + 1]);
		else if ((flag == ORDER && stack[rand_idx] < stack[rand_idx - 1])
			|| (flag == DISORDER && stack[rand_idx] > stack[rand_idx - 1]))
			swap(&stack[rand_idx], &stack[rand_idx - 1]);
	}
}

void	deorganize(int *stack, int size, int target_disorder)
{
	double		current_disorder;

	current_disorder = calc_disorder(stack, size);
	while ((int)(current_disorder * 100) < target_disorder)
	{
		random_swap(stack, size, DISORDER);
		current_disorder = calc_disorder(stack, size);
	}
}

void	reorganize(int*stack, int size, int target_disorder)
{
	double		current_disorder;

	current_disorder = calc_disorder(stack, size);
	while ((int)(current_disorder * 100) > target_disorder)
	{
		random_swap(stack, size, ORDER);
		current_disorder = calc_disorder(stack, size);
	}
}
