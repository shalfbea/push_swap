/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:53:13 by shalfbea          #+#    #+#             */
/*   Updated: 2022/02/21 19:07:59 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	finding_special_values(t_stacks *stacks)
{
	t_list	*a;
	int		counter;

	a = stacks->a;
	if (!a)
		exitter(stacks, 1);
	counter = 0;
	stacks->min = a->data;
	stacks->max = a->data;
	while (a)
	{
		counter++;
		if (a->data > stacks->max)
			stacks->max = a->data;
		if (a->data < stacks->max)
			stacks->min = a->data;
		if (counter == stacks->a_len / 2)
			stacks->median = a->data;
		a = a->next;
	}
}

void	first_push_to_b(t_stacks *stacks)
{
	int		counter;

	counter = 0;
	while (1)
	{
		if (stacks->a->data != stacks->min && stacks->a->data != stacks->max)
		{
			// Think about finding presort optimization here
			op_pb(stacks, 1);
			if (stacks->a->data > stacks->median)
				op_rb(stacks, 1);
		}
		else if (counter < 2)
		{
			//Think about optimization, when these 2 nums are near
			op_ra(stacks, 1);
			counter++;
		}
		else
			break;
	}
}

int	abs(int x)
{
	if (x < 0)
		return (-1*x);
	return (x);
}

int		a_score(t_list *a, int num)
{
	int	start;
	int	counter;
	int last;

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
