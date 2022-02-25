/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:24:40 by shalfbea          #+#    #+#             */
/*   Updated: 2022/02/23 18:28:04 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_three(t_stacks *stack)
{
	int		top;
	int		mid;
	int		bot;

	if (ft_lst_size(stack->a) != 3)
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
	else if(top > mid && mid < bot && bot > top)
	{
		op_sa(stack, 1);
		op_ra(stack, 1);
	}
	else if(top <   mid && mid < bot && bot < top)
		op_rra(stack, 1);
	return (1);
}
