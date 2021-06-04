/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_under_100.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsanaoui <bsanaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 18:20:20 by bsanaoui          #+#    #+#             */
/*   Updated: 2021/06/04 18:21:12 by bsanaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	random_under_100(t_stack *a, t_stack *b)
{
	t_chunk	chunk_a;

	chunk_a.bottom = -1;
	push_a_to_b(a, b, &chunk_a);
	push_b_to_a(a, b);
	if (!is_sorted(*a))
	{
		push_a_to_b(a, b, &chunk_a);
		push_b_to_a(a, b);
		send_top_to_bott(a, &chunk_a);
	}
}
