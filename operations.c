/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsanaoui <bsanaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:07:37 by bsanaoui          #+#    #+#             */
/*   Updated: 2021/06/04 17:07:40 by bsanaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	_push(t_stack *st1, t_stack *st2)
{
	push(st1, peek(*st2));
	pop(st2);
	display_oper("p", *st1);
}

void	swap(t_stack *stack, int is_one)
{
	int	tmp;

	if (size(*stack) >= 2)
	{
		tmp = stack->data[stack->top];
		stack->data[stack->top] = stack->data[stack->top - 1];
		stack->data[stack->top - 1] = tmp;
		if (is_one)
			display_oper("s", (*stack));
	}
	else
		ft_perror("");
}

void	ss_swap(t_stack *a, t_stack *b)
{
	swap(a, 0);
	swap(b, 0);
	put_string("ss\n");
}
