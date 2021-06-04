/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsanaoui <bsanaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:55:08 by bsanaoui          #+#    #+#             */
/*   Updated: 2021/06/04 18:16:39 by bsanaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	top;
	int	*data;
	int	i;
}		t_stack;

typedef struct s_chunk
{
	int	top;
	int	bottom;
}		t_chunk;

typedef struct s_chunks
{
	int	nb;
	int	i;
	int	size;
}		t_chunks;

void	init_stack(t_stack *stack, int lenght, int i);
void	push(t_stack *stack, int data);
void	pop(t_stack *stack);
int		peek(t_stack stack);
int		size(t_stack stack);
void	display(t_stack stack);
int		ft_strlen(const char *s);
void	ft_putnbr(int n);
int		ft_atoi(const char *str);
void	ft_putchar(char c);
void	put_string(char *s);
int		ft_perror(const char *s);
void	fill_list(t_stack *stack, int nb, char **s);
int		is_integer(char *s);
int		is_sorted(t_stack stack);
void	display_oper(char *kind, t_stack s);
int		ft_abs(int n);
int		get_max(t_stack st);
int		get_min(t_stack st);
int		get_index(t_stack st, int nb);
void	_push(t_stack *st1, t_stack *st2);
void	swap(t_stack *stack, int is_one);
void	ss_swap(t_stack *a, t_stack *b);
void	rotate(t_stack *stack, int is_one);
void	rr_rotate(t_stack *a, t_stack *b);
void	rev_rotate(t_stack *stack, int is_one);
void	rrr_rev_rotate(t_stack *a, t_stack *b);
int		*ft_sort(t_stack st);
int		ft_median(int *buf, int size_st);
int		random_3(t_stack *a);
int		random_2(t_stack *a);
int		random_4(t_stack *a, t_stack *b);
int		push_a_to_b(t_stack *a, t_stack *b, t_chunk *chunk_a);
int		push_b_to_a(t_stack *a, t_stack *b);
void	push_nb_to_top(t_stack *st, int index, int median);
void	send_top_to_bott(t_stack *a, t_chunk *chunk_a);
void	push_nb_to_top_b(t_stack *st, int index, int nb);
void	random_plus_100(t_stack *a, t_stack *b);
void	random_5(t_stack *a, t_stack *b);
void	random_under_100(t_stack *a, t_stack *b);
int		is_curr_chunk(t_chunks *chunks, int nb, int curr_chu);
void	reset_chunk(t_stack a, t_chunks **chunks);

#endif