/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:53:13 by shalfbea          #+#    #+#             */
/*   Updated: 2022/02/25 17:21:38 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	turning_back(t_stacks *stacks)
{
	t_list	*a;
	int		counter;

	counter = 0;
	a = stacks->a;
	if (DEBUG_OUTPUT)
		ft_putstr("=>Turning back\n");
	while (a)
	{
		if (a->data == stacks->min)
			break ;
		counter++;
		a = a->next;
	}
	if (counter > stacks->a_len / 2)
		counter = counter - stacks->a_len;
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

void	move_together(t_stacks *stacks, t_op_num *rotates)
{
	while (rotates->a > 0 && rotates->b > 0)
	{
		op_rr(stacks, 1);
		rotates->a -= 1;
		rotates->b -= 1;
	}
	while (rotates->a < 0 && rotates->b < 0)
	{
		op_rrr(stacks, 1);
		rotates->a += 1;
		rotates->b += 1;
	}
}

void	sorting(t_stacks *stacks)
{
	t_op_num	rotates;

	while (stacks->b_len > 0)
	{
		finding_special_values(stacks);
		rotates = element_to_move(stacks);
		move_together(stacks, &rotates);
		while (rotates.b > 0)
		{
			op_rb(stacks, 1);
			rotates.b -= 1;
		}
		while (rotates.b < 0)
		{
			op_rrb(stacks, 1);
			rotates.b += 1;
		}
		while (rotates.a > 0)
		{
			op_ra(stacks, 1);
			rotates.a -= 1;
		}
		while (rotates.a < 0)
		{
			op_rra(stacks, 1);
			rotates.a += 1;
		}
		op_pa(stacks, 1);
	}
	turning_back(stacks);
}
