/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsanaoui <bsanaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 18:21:36 by bsanaoui          #+#    #+#             */
/*   Updated: 2021/06/04 18:22:32 by bsanaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack, int lenght, int i)
{
	stack->data = (int *)malloc(sizeof(int) * lenght);
	stack->top = -1;
	stack->i = i;
}

void	push(t_stack *stack, int elem)
{
	stack->top++;
	stack->data[stack->top] = elem;
}

void	pop(t_stack *stack)
{
	if (stack->top < 0)
		ft_perror("");
	stack->top--;
}

int	peek(t_stack stack)
{
	if (stack.top < 0)
		ft_perror("");
	return (stack.data[stack.top]);
}

int	size(t_stack stack)
{
	return (stack.top + 1);
}
