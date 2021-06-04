#include "push_swap.h"

int	get_index(t_stack st, int nb)
{
	int	i;

	i = -1;
	while (++i < size(st))
	{
		if (st.data[i] == nb)
			return (i);
	}
	return (-1);
}

void	push_nb_to_top_b(t_stack *st, int index, int nb)
{
	while (peek(*st) != nb)
	{
		if (index >= size(*st) / 2)
			rotate(st, 1);
		else
			rev_rotate(st, 1);
	}
}

void	get_max_min(t_stack st, int *min, int *max)
{
	int	*buf;

	buf = ft_sort(st);
	*min = buf[0];
	*max = buf[size(st) - 1];
	if (buf)
		free(buf);
}

int	b_to_a_random_5(t_stack *a, t_stack *b)
{
	if (size(*b) == 1)
		_push(a, b);
	if (size(*b) == 2)
	{
		if (b->data[0] > b->data[1])
			swap(b, 1);
		_push(a, b);
		_push(a, b);
	}
	return (0);
}

int	push_b_to_a(t_stack *a, t_stack *b)
{
	int	min;
	int	max;

	if (is_sorted(*a) && size(*b) == 0)
		return (0);
	if (size(*a) == 3 && size(*b) <= 2)
		return (b_to_a_random_5(a, b));
	while (size(*b) > 0)
	{
		get_max_min(*b, &min, &max);
		if (abs(get_index(*b, min) - (size(*b) / 2)) > abs(get_index(*b, max)
				- (size(*b) / 2)))
		{
			push_nb_to_top_b(b, get_index(*b, min), min);
			_push(a, b);
			rotate(a, 1);
		}
		{
			push_nb_to_top_b(b, get_index(*b, max), max);
			_push(a, b);
		}
	}
	return (0);
}
