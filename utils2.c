/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsanaoui <bsanaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 18:32:40 by bsanaoui          #+#    #+#             */
/*   Updated: 2021/06/04 18:36:50 by bsanaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_sort(t_stack st)
{
	int	i;
	int	j;
	int	tmp;
	int	*buf;

	buf = (int *)malloc(sizeof(int) * size(st));
	i = -1;
	while (++i < size(st))
		buf[i] = st.data[i];
	i = -1;
	while (++i < size(st))
	{
		j = -1;
		while (++j < size(st))
		{
			if (buf[i] < buf[j])
			{
				tmp = buf[i];
				buf[i] = buf[j];
				buf[j] = tmp;
			}
		}
	}
	return (buf);
}

int	ft_median(int *buf, int size_st)
{
	int	median;

	median = buf[size_st / 2];
	if (buf)
		free(buf);
	return (median);
}

int	is_integer(char *s)
{
	int	i;

	i = -1;
	if (s[0] == '-')
	{
		if (s[1] == '\0')
			return (0);
		i++;
	}
	while (s[++i])
	{
		if ((s[i] < 48 || s[i] > 57))
			return (0);
	}
	return (1);
}

int	is_sorted(t_stack stack)
{
	int	i;

	i = -1;
	if (stack.top < 0)
		return (0);
	while (++i < stack.top)
	{
		if (stack.data[i] < stack.data[i + 1])
			return (0);
	}
	return (1);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
