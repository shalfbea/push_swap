/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:24:40 by shalfbea          #+#    #+#             */
/*   Updated: 2022/03/08 18:29:25 by shalfbea         ###   ########.fr       */
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
	if(top > mid && mid < bot && bot > top)
		op_sa(stack, 1);
	else if(top > mid && mid > bot && bot < top)
	{
		op_sa(stack, 1);
		op_rra(stack, 1);
	}
	else if(top > mid && mid < bot && bot < top)
		op_ra(stack, 1);
	else if(top < mid && mid > bot && bot > top)
	{
		op_sa(stack, 1);
		op_ra(stack, 1);
	}
	else if(top < mid && mid > bot && bot < top)
		op_rra(stack, 1);
	return (1);
}

void	ss_path_back(t_stacks *stacks)
{
	int	min;
	int	counter;
	int	last_counted;
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
	/*
	while (counter > 0)
	{
		counter--;
		op_ra(stacks, 1);
	}
	while (counter < 0)
	{
		counter++;
		op_rra(stacks, 1);
	}
	*/
}

void	ss_pusher(t_stacks	*stacks)
{
	t_list	*a;
	int		counter;

	counter = 0;
	a = stacks->a;
	/*
	while (a->data < stacks->b->data)// && a->next->data > stacks->b->data)
	{
		counter++;
		a = a->next;
		if (a->next == NULL)
			break ;
	}
	*/
	counter = a_score(stacks, stacks->b->data);
	if (DEBUG_OUTPUT)
	{
		ft_putstr("counter : ");
		ft_putnbr(counter);
		ft_putstr("\n");
	}
	if (counter > stacks->a_len / 2)
		counter = counter - stacks->a_len ;
	ra_doer(stacks, counter);
	op_pa(stacks, 1);
	//ra_doer(stacks, counter);
}

void	min_situation(t_stacks *stacks)
{
	t_list	*a;
	int		min;
	int		counter;

	a = stacks->a->next;
	min = stacks->a->data;
	while (a)
	{
		if (a->data < min)
			min = a->data;
		a = a->next;
	}
	a = stacks->a;
	counter = 0;
	while (a->data != min)
	{
		counter++;
		a = a->next;
	}
	if (counter > stacks->a_len / 2)
		counter = counter - stacks->a_len ;
	ra_doer(stacks, counter);
	op_pa(stacks, 1);
}

void	max_situation(t_stacks *stacks)
{
	t_list	*a;
	int		max;
	int		counter;

	a = stacks->a->next;
	max = stacks->a->data;
	while (a)
	{
		if (a->data > max)
			max = a->data;
		a = a->next;
	}
	a = stacks->a;
	counter = 0;
	while (a->data != max)
	{
		counter++;
		a = a->next;
	}
	if (counter > stacks->a_len / 2)
		counter = counter - stacks->a_len ;
	ra_doer(stacks, counter + 1);
	op_pa(stacks, 1);
}

int	local_max(t_stacks *stacks, int	cur)
{
	t_list	*a;
	int		max;

	a = stacks->a->next;
	max = stacks->a->data;
	while (a)
	{
		if (a->data > max)
			max = a->data;
		a = a->next;
	}
	if (cur > max)
		return (max);
	return (-1);
}

int	local_min(t_stacks *stacks, int	cur)
{
	t_list	*a;
	int		min;

	a = stacks->a->next;
	min = stacks->a->data;
	while (a)
	{
		if (a->data < min)
			min = a->data;
		a = a->next;
	}
	if (cur < min)
		return (min);
	return (-1);
}

int	small_sort(t_stacks *stacks)
{
	if (stacks->a_len > 5)
		return (0);
	while (stacks->a_len > 3)
		op_pb(stacks, 1);
	sort_three(stacks);
	if (DEBUG_OUTPUT)
		ft_putstr("small sorting alg\n");
	while (stacks->b_len > 0)
	{
		if (local_min(stacks, stacks->b->data) != -1)
		//if (stacks->b->data == stacks->min)
			min_situation(stacks);
		//else if (stacks->b->data == stacks->max)
		else if (local_max(stacks, stacks->b->data) != -1)
			max_situation(stacks);
		else
			ss_pusher(stacks);
		if (DEBUG_OUTPUT)
			ft_putstr("next elem\n");
	}
	ss_path_back(stacks);
	return (1);
}