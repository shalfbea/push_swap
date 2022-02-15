/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotating.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 22:26:48 by shalfbea          #+#    #+#             */
/*   Updated: 2022/02/15 22:29:58 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** rra (reverse rotate a): Shift down all elements of stack a by 1.
** The last element becomes the first one.
*/
void	op_rra(t_list **a, t_list **b, char mode)
{
	if (mode)
		ft_putstr("rra\n");
	//dotsmth
	if (DEBUG_OUTPUT && mode)
		heaps_print(*a, *b);
}

/*
** rrb (reverse rotate b): Shift down all elements of stack b by 1.
** The last element becomes the first one.
*/
void	op_rrb(t_list **a, t_list **b, char mode)
{
	if (mode)
		ft_putstr("rrb\n");
	op_rra(a, b, 0);
	if (DEBUG_OUTPUT && mode)
		heaps_print(*a, *b);
}

/*
** rrr : rra and rrb at the same time.
*/
void	op_rrr(t_list **a, t_list **b, char mode)
{
	if (mode)
		ft_putstr("rrr\n");
	op_rra(a, b, 0);
	op_rrb(a, b, 0);
	if (DEBUG_OUTPUT && mode)
		heaps_print(*a, *b);
}
