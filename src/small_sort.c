/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:24:40 by shalfbea          #+#    #+#             */
/*   Updated: 2022/02/25 19:48:00 by shalfbea         ###   ########.fr       */
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

char	ss_mode(t_stacks *stacks)
{
	t_list	*a;
	char	mode;

	mode = 1;
	a = stacks->a;
	while (a && mode)
	{
		if (stacks->b->data < a->data)
			mode = 0;
		a = a->next;
	}
	if (mode)
		return (1);
	mode = 1;
	a = stacks->a;
	while (a && mode)
	{
		if (stacks->b->data > a->data)
			mode = 0;
		a = a->next;
	}
	if (mode)
		return (-1);
	return (0);
}

int	ss_opt_path(t_stacks *stacks)
{
	t_list	*a;
	int		counter;
	int		res;

	counter = 0;
	a = stacks->a;
	while (a->data < stacks->b->data)
	{
		counter++;
		a = a->next;
		if (a == NULL)
			break;
	}
	if (counter > stacks->a_len / 2)
		counter = counter - stacks->a_len ;
	res = counter;
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
	if (res > 0)
		res += 1;
	else if (res < 0)
		res -= 1;
	return (res);
}

void	ss_path_back(t_stacks *stacks)
{
	int	min;
	int	counter;

	t_list	*a;

	a = stacks->a;
	min = a->data;
	while (a)
	{
		if (a->data < min)
			min = a->data;
		a = a->next;
	}
	a = stacks->a;
	counter = 0;
	while (a)
	{
		if (a->data == min)
			break;
		a = a->next;
		counter++;
	}
	if (counter > stacks->a_len / 2)
		counter = counter - stacks->a_len ;
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
}
int	small_sort(t_stacks *stacks)
{
	int	mode;

	if (stacks->a_len > 6)
		return (0);
	while (stacks->a_len > 3)
		op_pb(stacks, 1);
	sort_three(stacks);
	if (DEBUG_OUTPUT)
		ft_putstr("small sorting alg\n");
	while (stacks->b_len > 0)
	{
		mode = ss_mode(stacks);
		if (DEBUG_OUTPUT)
		{
			ft_putstr("\n mode: ");
			ft_putnbr(mode);
			ft_putstr("\n");
		}
		if (mode == 1)
		{
			op_pa(stacks, 1);
			op_ra(stacks, 1);
		}
		else if (mode == -1)
			op_pa(stacks, 1);
		else
		{
			mode = ss_opt_path(stacks);
			op_pa(stacks, 1);
			ss_path_back(stacks);
		}
	}
	//sorting(stacks);
	return (1);
}
