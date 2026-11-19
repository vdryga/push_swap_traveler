#include "input_gen.h"

static void print_stack(int	*stack, int size)
{
	while (size)
	{
		printf("%d ", *stack);
		size--;
		stack++;
	}
	fflush(stdout);
}

int	main(int ac, char **av)
{

	int		*stack;
	int		disorder;
	int		size;

	if (ac < 3)
	{
		fprintf(stderr, "input_gen [INPUT_SIZE] [DISORDER]\n");
		fprintf(stderr, "Size must be > 0\nDisorder must be between 0 and 100\n");
		return (0);
	}
	srand ( time(NULL) );
	size = atoi(av[1]);
	disorder = atoi(av[2]);
	if (size <= 0 || disorder > 100 || disorder < 0)
	{
		fprintf(stderr, "input_gen [INPUT_SIZE] [DISORDER]\n");
		fprintf(stderr, "Size must be > 0\nDisorder must be between 0 and 100\n");
	}
	if (disorder < 50)
	{
		stack = create_stack(size);
		deorganize(stack, size, disorder);
	}
	else
	{
		stack = create_reversed_stack(size);
		reorganize(stack, size, disorder);
	}
	print_stack(stack, size);
	fprintf(stderr, "\nFinal disorder: %f\n", calc_disorder(stack, size) * 100.0f);
	free(stack);
	return (0);
}
