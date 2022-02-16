/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotating.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 22:03:28 by shalfbea          #+#    #+#             */
/*   Updated: 2022/02/16 16:17:09 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** ra (rotate a): Shift up all elements of stack a by 1.
** The first element becomes the last one.
*/
void	op_ra(t_stacks *stacks, char mode)
{
	int	tmp;

	if (mode)
		ft_putstr("ra\n");
	if (stacks->a != NULL)
	{
		if (stacks->a->next != NULL)
		{
			tmp = ft_lst_pop_first(&(stacks->a));
			ft_lst_add_back(&(stacks->a), tmp);
		}
	}
	if (DEBUG_OUTPUT && mode)
		heaps_print(stacks);
}

/*
** rb (rotate b): Shift up all elements of stack b by 1.
** The first element becomes the last one.
*/
void	op_rb(t_stacks *stacks, char mode)
{
	int	tmp;

	if (mode)
		ft_putstr("rb\n");
	if (stacks->b != NULL)
	{
		if (stacks->b->next != NULL)
		{
			tmp = ft_lst_pop_first(&(stacks->b));
			ft_lst_add_back(&(stacks->b), tmp);
		}
	}
	if (DEBUG_OUTPUT && mode)
		heaps_print(stacks);
}

/*
** rr : ra and rb at the same time.
*/
void	op_rr(t_stacks *stacks, char mode)
{
	if (mode)
		ft_putstr("rr\n");
	op_ra(stacks, 0);
	op_rb(stacks, 0);
	if (DEBUG_OUTPUT && mode)
		heaps_print(stacks);
}
