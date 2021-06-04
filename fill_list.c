/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsanaoui <bsanaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:55:28 by bsanaoui          #+#    #+#             */
/*   Updated: 2021/06/04 16:57:03 by bsanaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(t_stack st)
{
	int	i;
	int	j;
	int	tmp;

	i = size(st);
	tmp = st.data[0];
	while (--i >= 0)
	{
		j = i;
		while (--j >= 0)
		{
			if (st.data[i] == st.data[j])
				return (0);
		}
	}
	return (1);
}

void	fill_list(t_stack *stack, int nb, char **s)
{
	if (nb > 1)
	{
		while (nb-- > 1)
		{
			if (!is_integer(s[nb]))
				ft_perror("");
			push(stack, ft_atoi(s[nb]));
		}
	}
	else
		exit(0);
	if (!check_duplicate(*stack))
		ft_perror("");
}
