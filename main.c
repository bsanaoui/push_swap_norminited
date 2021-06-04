/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsanaoui <bsanaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:03:08 by bsanaoui          #+#    #+#             */
/*   Updated: 2021/06/04 17:05:28 by bsanaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *a, t_stack *b)
{
	if (size(*a) == 1)
		return ;
	if (!is_sorted(*a))
	{
		if (size(*a) == 2)
			random_2(a);
		else if (size(*a) == 3)
			random_3(a);
		else if (size(*a) == 4)
			random_4(a, b);
		else if (size(*a) >= 5 && size(*a) <= 100)
		{
			random_under_100(a, b);
		}
		else if (size(*a) > 100)
			random_plus_100(a, b);
	}
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	init_stack(&a, argc - 1, 1);
	init_stack(&b, argc - 1, 0);
	fill_list(&a, argc, argv);
	push_swap(&a, &b);
	if (a.data)
		free(a.data);
	if (b.data)
		free(b.data);
	return (0);
}
