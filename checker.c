/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsanaoui <bsanaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:54:04 by bsanaoui          #+#    #+#             */
/*   Updated: 2021/06/08 17:28:56 by bsanaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	_push_ch(t_stack *st1, t_stack *st2);
void	swap_ch(t_stack *stack);
void	ss_swap_ch(t_stack *a, t_stack *b);
void	rotate_ch(t_stack *stack);
void	rr_rotate_ch(t_stack *a, t_stack *b);
void	rev_rotate_ch(t_stack *stack);
void	rrr_rev_rotate_ch(t_stack *a, t_stack *b);
int		get_next_line(char **line);

int	ft_is_equal(char *s1, char *s2)
{
	int	i;
	int	len;

	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	i = -1;
	len = ft_strlen(s1);
	while (++i < len)
	{
		if (s1[i] != s2[i])
			return (0);
	}
	return (1);
}

int	do_operations(t_stack *a, t_stack *b, char *line)
{
	if (ft_is_equal(line, "sa"))
		swap_ch(a);
	else if (ft_is_equal(line, "sb"))
		swap_ch(b);
	else if (ft_is_equal(line, "ss"))
		ss_swap_ch(a, b);
	else if (ft_is_equal(line, "pa"))
		_push_ch(a, b);
	else if (ft_is_equal(line, "pb"))
		_push_ch(b, a);
	else if (ft_is_equal(line, "ra"))
		rotate_ch(a);
	else if (ft_is_equal(line, "rb"))
		rotate_ch(b);
	else if (ft_is_equal(line, "rr"))
		rr_rotate_ch(a, b);
	else if (ft_is_equal(line, "rra"))
		rev_rotate_ch(a);
	else if (ft_is_equal(line, "rrb"))
		rev_rotate_ch(b);
	else if (ft_is_equal(line, "rrr"))
		rrr_rev_rotate_ch(a, b);
	else
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	char	*line;
	size_t	len;

	init_stack(&a, argc - 1, 1);
	init_stack(&b, argc - 1, 0);
	fill_list(&a, argc, argv);
	line = NULL;
	len = 0;
	while (get_next_line(&line))
	{
		if (!do_operations(&a, &b, line))
			ft_perror("");
		if (line)
			free(line);
	}
	if (is_sorted(a) && size(b) == 0)
		put_string("OK\n");
	else
		put_string("KO\n");
	if (line)
		free(line);
	return (0);
}
