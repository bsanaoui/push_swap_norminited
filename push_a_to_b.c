/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsanaoui <bsanaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:29:02 by bsanaoui          #+#    #+#             */
/*   Updated: 2021/06/04 17:31:07 by bsanaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_nb_to_top(t_stack *st, int index, int median)
{
	while (peek(*st) >= median)
	{
		if (index >= size(*st) / 2)
			rotate(st, 1);
		else
			rev_rotate(st, 1);
	}
}

void	send_top_to_bott(t_stack *a, t_chunk *chunk_a)
{
	if (is_sorted(*a))
		return ;
	while (peek(*a) != chunk_a->top && size(*a) > 0)
		rotate(a, 1);
}

void	push_last_chunk_to_b(t_stack *a, t_stack *b, t_chunk *chunk_a)
{
	while (peek(*a) != chunk_a->bottom && size(*a) > 0)
		_push(b, a);
	_push(b, a);
	chunk_a->top = peek(*a);
	chunk_a->bottom = a->data[0];
}

static int	push_a_to_b_1(t_stack *a, t_stack *b)
{
	int	median;
	int	i;

	median = ft_median(ft_sort(*a), size(*a));
	i = a->top;
	while (i >= 0)
	{
		if (size(*a) == 3 && (size(*b) == 1 || size(*b) == 2))
			return (random_3(a));
		if (a->data[i] < median)
		{
			if (i != a->top)
			{
				push_nb_to_top(a, i, median);
				i = a->top;
			}
			_push(b, a);
		}
		i--;
	}
	return (0);
}

int	push_a_to_b(t_stack *a, t_stack *b, t_chunk *chunk_a)
{
	if (is_sorted(*a) && !size(*b))
		return (0);
	if (chunk_a->bottom != -1)
	{
		send_top_to_bott(a, chunk_a);
		push_last_chunk_to_b(a, b, chunk_a);
		return (0);
	}
	if (push_a_to_b_1(a, b))
		return (0);
	chunk_a->top = peek(*a);
	chunk_a->bottom = a->data[0];
	return (0);
}
