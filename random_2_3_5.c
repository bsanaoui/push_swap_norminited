#include "push_swap.h"

int	random_2(t_stack *a)
{
	if (a->data[1] > a->data[0])
		swap(a, 1);
	return (1);
}

int	random_3(t_stack *a)
{
	if (a->data[2] > a->data[1] && a->data[1] < a->data[0]
		&& a->data[0] > a->data[2])
		swap(a, 1);
	if (a->data[2] > a->data[1] && a->data[1] < a->data[0]
		&& a->data[0] < a->data[2])
		rotate(a, 1);
	if (a->data[2] < a->data[1] && a->data[1] > a->data[0]
		&& a->data[0] < a->data[2])
		rev_rotate(a, 1);
	if (a->data[2] < a->data[1] && a->data[1] > a->data[0]
		&& a->data[0] > a->data[2])
	{
		swap(a, 1);
		rotate(a, 1);
	}
	if (a->data[2] > a->data[1] && a->data[1] > a->data[0]
		&& a->data[0] < a->data[2])
	{
		swap(a, 1);
		rev_rotate(a, 1);
	}
	return (1);
}

int	random_4(t_stack *a, t_stack *b)
{
	int	min;
	int	index;

	min = get_min(*a);
	index = get_index(*a, min);
	push_nb_to_top_b(a, index, min);
	_push(b, a);
	random_3(a);
	_push(a, b);
	return (0);
}
