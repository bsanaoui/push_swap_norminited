/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsanaoui <bsanaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 15:33:12 by bsanaoui          #+#    #+#             */
/*   Updated: 2021/06/04 16:47:59 by bsanaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	_push_ch(t_stack *st1, t_stack *st2)
{
	if (st2->top < 0)
		return ;
	push(st1, peek(*st2));
	pop(st2);
}

void	swap_ch(t_stack *stack)
{
	int	tmp;

	if (stack->top < 0)
		return ;
	if (size(*stack) >= 1)
	{
		tmp = stack->data[stack->top];
		stack->data[stack->top] = stack->data[stack->top - 1];
		stack->data[stack->top - 1] = tmp;
	}
	else
		ft_perror("");
}

void	ss_swap_ch(t_stack *a, t_stack *b)
{
	swap(a, 0);
	swap(b, 0);
}

void	rotate_ch(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->top < 0)
		return ;
	i = stack->top;
	while (i > 0)
	{
		tmp = stack->data[i];
		stack->data[i] = stack->data[i - 1];
		stack->data[i - 1] = tmp;
		i--;
	}
}
