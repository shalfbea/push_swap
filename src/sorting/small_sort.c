/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:24:40 by shalfbea          #+#    #+#             */
/*   Updated: 2022/03/10 18:59:09 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_three(t_stacks *stack)
{
	int		top;
	int		mid;
	int		bot;

	if (stack->a_len != 3)
		return (0);
	top = stack->a->data;
	mid = stack->a->next->data;
	bot = stack->a->next->next->data;
	if (top > mid && mid < bot && bot > top)
		op_sa(stack, 1);
	else if (top > mid && mid > bot && bot < top)
	{
		op_sa(stack, 1);
		op_rra(stack, 1);
	}
	else if (top > mid && mid < bot && bot < top)
		op_ra(stack, 1);
	else if (top < mid && mid > bot && bot > top)
	{
		op_sa(stack, 1);
		op_ra(stack, 1);
	}
	else if (top < mid && mid > bot && bot < top)
		op_rra(stack, 1);
	return (1);
}
/*
void	ss_path_back(t_stacks *stacks)
{
	int		min;
	int		counter;
	int		last_counted;
	t_list	*a;

	a = stacks->a;
	min = a->data;
	last_counted = 0;
	counter = 0;
	while (a)
	{
		if (a->data < min)
		{
			min = a->data;
			last_counted = counter;
		}
		a = a->next;
		counter++;
	}
	counter = last_counted;
	if (counter > stacks->a_len / 2)
		counter = counter - stacks->a_len ;
	ra_doer(stacks, counter);
}
*/

void	ss_pusher(t_stacks *stacks, int mm, int mode)
{
	t_list	*a;
	int		counter;

	if (mode == -1)
	{
		counter = a_score(stacks, stacks->b->data);
		ra_doer(stacks, counter);
		op_pa(stacks, 1);
		return ;
	}
	a = stacks->a;
	counter = 0;
	while (a->data != mm)
	{
		counter++;
		a = a->next;
	}
	if (counter > stacks->a_len / 2)
		counter = counter - stacks->a_len ;
	ra_doer(stacks, counter + mode);
	op_pa(stacks, 1);
}

int	local_min_max(t_stacks *stacks, int mode)
{
	t_list	*a;
	int		min;
	int		max;

	a = stacks->a->next;
	min = stacks->a->data;
	max = stacks->a->data;
	while (a)
	{
		if (a->data < min)
			min = a->data;
		if (a->data > max)
			max = a->data;
		a = a->next;
	}
	if (mode)
		return (max);
	return (min);
}

int	small_sort(t_stacks *stacks)
{
	int	tmp;

	if (stacks->a_len > 5)
		return (0);
	while (stacks->a_len > 3)
		op_pb(stacks, 1);
	sort_three(stacks);
	while (stacks->b_len > 0)
	{
		tmp = local_min_max(stacks, 0);
		if (stacks->b->data < tmp)
			ss_pusher(stacks, tmp, 0);
		else
		{
			tmp = local_min_max(stacks, 1);
			if (stacks->b->data > tmp)
				ss_pusher(stacks, tmp, 1);
			else
				ss_pusher(stacks, tmp, -1);
		}

	}
	turning_back(stacks);
	return (1);
}
