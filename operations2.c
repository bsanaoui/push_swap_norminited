/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsanaoui <bsanaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:10:36 by bsanaoui          #+#    #+#             */
/*   Updated: 2021/06/04 18:35:19 by bsanaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack, int is_one)
{
	int	tmp;
	int	i;

	i = stack->top;
	while (i > 0)
	{
		tmp = stack->data[i];
		stack->data[i] = stack->data[i - 1];
		stack->data[i - 1] = tmp;
		i--;
	}
	if (is_one)
		display_oper("r", (*stack));
}

void	rr_rotate(t_stack *a, t_stack *b)
{
	rotate(a, 0);
	rotate(b, 0);
	put_string("rr\n");
}

void	rev_rotate(t_stack *stack, int is_one)
{
	int	tmp;
	int	i;

	i = 0;
	while (i < stack->top)
	{
		tmp = stack->data[i];
		stack->data[i] = stack->data[i + 1];
		stack->data[i + 1] = tmp;
		i++;
	}
	if (is_one)
		display_oper("rr", (*stack));
}

void	rrr_rev_rotate(t_stack *a, t_stack *b)
{
	rev_rotate(a, 0);
	rev_rotate(b, 0);
	put_string("rrr\n");
}
