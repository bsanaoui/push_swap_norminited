/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsanaoui <bsanaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 18:37:33 by bsanaoui          #+#    #+#             */
/*   Updated: 2021/06/04 18:41:32 by bsanaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_curr_chunk(t_chunks *chunks, int nb, int curr_chu)
{
	int	i;

	i = -1;
	while (++i < chunks[0].size)
	{
		if (chunks[i].nb == nb && chunks[i].i == curr_chu)
			return (1);
	}
	return (0);
}

void	reset_chunk(t_stack a, t_chunks **chunks)
{
	int	size_chunk;
	int	*buf;
	int	curr_chunk;
	int	i;

	buf = ft_sort(a);
	(*chunks) = (t_chunks *)(malloc(sizeof(t_chunks) * size(a)));
	size_chunk = size(a) / 11;
	i = -1;
	curr_chunk = 1;
	while (++i < size(a))
	{
		(*chunks)[i].nb = buf[i];
		(*chunks)[i].i = curr_chunk;
		if (((i - 1) % size_chunk) == 0)
			curr_chunk++;
	}
	chunks[0]->size = size(a);
	if (buf)
		free(buf);
}
