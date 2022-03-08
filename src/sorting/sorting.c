/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:53:13 by shalfbea          #+#    #+#             */
/*   Updated: 2022/03/08 15:11:22 by shalfbea         ###   ########.fr       */
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
		if (DEBUG_OUTPUT)
			ft_putstr("next value\n");
		//finding_special_values(stacks, 1);
		rotates = element_to_move(stacks);
		if (DEBUG_OUTPUT)
		{
			ft_putstr("\nWANNA PASS : ");
			ft_putnbr(rotates.num_to_pass);
			ft_putstr(" a: ");
			ft_putnbr(rotates.a);
			ft_putstr(" b: ");
			ft_putnbr(rotates.b);
			ft_putstr(" sum: ");
			ft_putnbr(rotates.insum);
			ft_putstr("\n");
		}
		move_together(stacks, &rotates);
		rb_doer(stacks, rotates.b);
		ra_doer(stacks, rotates.a);
		if (rotates.num_to_pass != stacks->b->data && DEBUG_OUTPUT)
		{
			ft_putstr("\n\n\nERROR!! PASSING ELEMENT WE DON'T WANNA TO!\n We wanted: ");
			ft_putnbr(rotates.num_to_pass);
			ft_putstr(" and we got :");
			ft_putnbr(stacks->b->data);
			ft_putstr("\n\n\n");
		}
		op_pa(stacks, 1);
	}
	turning_back(stacks);
}
