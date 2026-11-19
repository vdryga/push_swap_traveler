#include "input_gen.h"

double	calc_disorder(int *stack, unsigned int size)
{
	double				mistakes;
	double				total_pairs;
	unsigned int		i;
	unsigned int		j;

	if (size < 2)
		return (0.0f);
	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			total_pairs += 1;
			if (stack[i] > stack[j])
				mistakes += 1;
			j++;
		}
		i++;
	}
	return (mistakes / total_pairs);
}
