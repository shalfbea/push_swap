/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_marking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 19:08:16 by shalfbea          #+#    #+#             */
/*   Updated: 2022/02/22 21:00:17 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	a_score(t_list *a, int num)
{
	int	start;
	int	counter;
	int	last;

	counter = 0;
	last = ft_last_data(a);
	start = a->data;
	if (start > num && last < num)
		return (0);
	if (start < num && last > num)
		return (-1);
	while (a->next)
	{
		if (a->data < num && a->next->data > num)
			return (counter);
		counter++;
		a = a->next;
	}
	return (99999999);
}

void	score_marking(t_stacks *stacks)
{
	t_list	*b;
	int		cur_mid;
	int		counter;

	counter = 0;
	b = stacks->b;
	cur_mid = stacks->b_len / 2;
	while (b)
	{
		if (counter <= cur_mid)
			b->score_b = counter;
		else
			b->score_b = counter - stacks->b_len;
		b->score_a = a_score(stacks->a, b->data);
		b = b->next;
		counter++;
	}
}

int		resulting_score(t_stacks *stacks, t_list *b)
{
	int		min;

	min = ft_abs(b->score_a) + ft_abs(b->score_b);
	if ((b->score_a > 0 && b->score_b > 0 ) || ((b->score_a) < 0 && (b->score_b < 0)))
		min = ft_max2(ft_abs(b->score_a), ft_abs(b->score_b));
	else
	{
		if (b->score_b < 0)
		{
			if (stacks->b_len + b->score_b + b->score_a < min)
				min = ft_max2()
			if (ft_abs(b->score_b) + ft_abs(b->score_a - stacks->a_len) < min)
				min = ft_abs(b->score_b) + ft_abs(b->score_a - stacks->a_len);
		}
		else //score_b > 0 && score_a < 0
		{
			if (ft_abs(b->score_b) + ft_abs(b->score_a) < min)
		}
		//if (stacks->xx->score_a)
	}
}

t_list	*element_to_move(t_stacks *stacks)
{
	t_list	*found;
	t_list	*b;
	int		minimum_operations;

	score_marking(stacks);
	b = stacks->b;
	minimum_operations = abs(b->score_a) + abs(b->score_a);
	found = b;
	score_marking(stacks);
	while (b)
	{

		b = b->next;
	}
	return (found);
}
