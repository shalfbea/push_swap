/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotating.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 22:26:48 by shalfbea          #+#    #+#             */
/*   Updated: 2022/02/28 17:57:31 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** rra (reverse rotate a): Shift down all elements of stack a by 1.
** The last element becomes the first one.
*/
void	op_rra(t_stacks *stacks, char mode)
{
	int	tmp;

	if (mode)
		ft_putstr("rra\n");
	if (stacks->a != NULL)
	{
		tmp = ft_lst_pop_last(&(stacks->a));
		ft_lst_add_front(&(stacks->a), tmp);
	}
	if (DEBUG_OUTPUT && mode)
		heaps_print(stacks);
}

/*
** rrb (reverse rotate b): Shift down all elements of stack b by 1.
** The last element becomes the first one.
*/
void	op_rrb(t_stacks *stacks, char mode)
{
	int	tmp;

	if (mode)
		ft_putstr("rrb\n");
	if (stacks->b != NULL)
	{
		tmp = ft_lst_pop_last(&(stacks->b));
		ft_lst_add_front(&(stacks->b), tmp);
	}
	if (DEBUG_OUTPUT && mode)
		heaps_print(stacks);
}

/*
** rrr : rra and rrb at the same time.
*/
void	op_rrr(t_stacks *stacks, char mode)
{
	if (mode)
		ft_putstr("rrr\n");
	op_rra(stacks, 0);
	op_rrb(stacks, 0);
	if (DEBUG_OUTPUT && mode)
		heaps_print(stacks);
}
