#include "input_gen.h"

int	*create_stack(int size)
{
	int	*stack = (int *)malloc(sizeof(int) * size);
	int	i = 0;

	while (i < size)
	{
		stack[i] = i;
		i++;
	}
	return stack;
}

int	*create_reversed_stack(int size)
{
	int	*stack = (int *)malloc(sizeof(int) * size);
	int	i = 0;

	while (i < size)
	{
		stack[i] = size - i - 1;
		i++;
	}
	return stack;
}
