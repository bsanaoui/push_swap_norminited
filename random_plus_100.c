/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_plus_100.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsanaoui <bsanaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 18:20:01 by bsanaoui          #+#    #+#             */
/*   Updated: 2021/06/04 18:20:02 by bsanaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_top_a(t_stack *st, int index, t_chunks *chunks, int curr_chu)
{
	while (!is_curr_chunk(chunks, peek(*st), curr_chu))
	{
		if (index >= size(*st) / 2)
			rotate(st, 1);
		else
			rev_rotate(st, 1);
	}
}

void	push_b_to_a_100(t_stack *a, t_stack *b)
{
	int	max;

	if (is_sorted(*a) && !size(*b))
		return ;
	while (size(*b))
	{
		max = get_max(*b);
		push_nb_to_top_b(b, get_index(*b, max), max);
		_push(a, b);
	}
}

void	push_a_to_b_100(t_stack *a, t_stack *b, t_chunks *chunks)
{
	int	i;
	int	curr_chu;

	curr_chu = 1;
	i = a->top;
	if (is_sorted(*a) && size(*b) == 0)
		return ;
	while (size(*a) && i >= 0)
	{
		if (is_curr_chunk(chunks, a->data[i], curr_chu))
		{
			push_to_top_a(a, i, chunks, curr_chu);
			_push(b, a);
			i = a->top;
		}
		else if (!i)
		{
			curr_chu++;
			i = a->top;
		}
		else
			i--;
	}
}

void	random_plus_100(t_stack *a, t_stack *b)
{
	t_chunks	*chunks;

	chunks = NULL;
	reset_chunk(*a, &chunks);
	push_a_to_b_100(a, b, chunks);
	push_b_to_a_100(a, b);
	if (chunks)
		free(chunks);
}
