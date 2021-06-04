/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operations2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsanaoui <bsanaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 15:33:12 by bsanaoui          #+#    #+#             */
/*   Updated: 2021/06/04 16:49:55 by bsanaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_rotate_ch(t_stack *a, t_stack *b)
{
	rotate(a, 0);
	rotate(b, 0);
}

void	rev_rotate_ch(t_stack *stack)
{
	int	tmp;
	int	i;

	i = 0;
	if (stack->top < 0)
		return ;
	while (i < stack->top)
	{
		tmp = stack->data[i];
		stack->data[i] = stack->data[i + 1];
		stack->data[i + 1] = tmp;
		i++;
	}
}

void	rrr_rev_rotate_ch(t_stack *a, t_stack *b)
{
	rev_rotate(a, 0);
	rev_rotate(b, 0);
}
