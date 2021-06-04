/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsanaoui <bsanaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 18:31:51 by bsanaoui          #+#    #+#             */
/*   Updated: 2021/06/04 18:32:28 by bsanaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_perror(const char *s)
{
	write(1, "Error\n", 7);
	write(1, s, ft_strlen(s));
	exit(EXIT_FAILURE);
	return (0);
}

void	display_oper(char *kind, t_stack s)
{
	put_string(kind);
	if (s.i)
		put_string("a\n");
	else
		put_string("b\n");
}

void	put_string(char *s)
{
	write(1, s, ft_strlen(s));
}

int	get_max(t_stack st)
{
	int	max;
	int	i;

	max = st.data[0];
	i = size(st);
	while (--i >= 0)
	{
		if (st.data[i] > max)
			max = st.data[i];
	}
	return (max);
}

int	get_min(t_stack st)
{
	int	min;
	int	i;

	min = st.data[0];
	i = size(st);
	while (--i >= 0)
	{
		if (st.data[i] < min)
			min = st.data[i];
	}
	return (min);
}
