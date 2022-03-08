/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:43:07 by shalfbea          #+#    #+#             */
/*   Updated: 2022/03/08 19:07:44 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	print_cur(int data, int prev_len, int max)
{
	while (++prev_len < max)
		ft_putstr(" ");
	prev_len = ft_putnbr(data);
	return (prev_len);
}

static void	print_lens(t_stacks *stacks)
{
	int	prev_len;

	ft_putstr("(");
	prev_len = ft_putnbr(stacks->a_len);
	ft_putstr(")");
	while (++prev_len < 9)
		ft_putstr(" ");
	ft_putstr("(");
	ft_putnbr(stacks->b_len);
	ft_putstr(")");
	ft_putstr("\n============\n");
}

static void	print_lines(t_list *a, t_list *b)
{
	int	prev_len;

	while (a || b)
	{
		if (a)
		{
			prev_len = ft_putnbr(a->data);
			a = a->next;
		}
		if (b)
		{
			prev_len = print_cur(b->data, prev_len, 11);
			if (SHOW_ME)
			{
				prev_len = print_cur(b->score_b, prev_len, 11);
				prev_len = print_cur(b->score_a, prev_len, 5);
				prev_len = print_cur(b->resulting_score, prev_len, 5);
			}
			b = b->next;
		}
		prev_len = 0;
		ft_putstr("\n");
	}
}

void	heaps_print(t_stacks *stacks)
{
	if (DEBUG_OUTPUT && SHOW_ME)
		element_to_move(stacks);
	ft_putstr("============\n");
	print_lines(stacks->a, stacks->b);
	print_lens(stacks);
}

void	print_array(int	*array, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putnbr(array[i]);
		ft_putstr(" ");
		i++;
	}
	ft_putstr("\n");
}
