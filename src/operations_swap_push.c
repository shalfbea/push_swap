/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap_push.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:41:17 by shalfbea          #+#    #+#             */
/*   Updated: 2022/02/15 22:07:58 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** sa (swap a): Swap the first 2 elements at the top of stack a.
** Do nothing if there is only one or no elements.
*/
void	op_sa(t_list *a, t_list *b, char mode)
{
	int	tmp;

	if (mode)
		ft_putstr("sa\n");
	if (a != NULL)
	{
		if (a->next != NULL)
		{
			tmp = a->data;
			a->data = a->next->data;
			a->next->data = tmp;
		}
	}
	if (mode && DEBUG_OUTPUT)
		heaps_print(a, b);
}

/*
** sb (swap b): Swap the first 2 elements at the top of stack b.
** Do nothing if there is only one or no elements.
*/
void	op_sb(t_list *a, t_list *b, char mode)
{
	if (mode)
		ft_putstr("sb\n");
	op_sa(a, b, 0);
	if (mode && DEBUG_OUTPUT)
		heaps_print(a, b);
}

/*
** ss : sa and sb at the same time.
*/
void	op_ss(t_list *a, t_list *b, char mode)
{
	if (mode)
		ft_putstr("ss\n");
	op_sa(a, b, 0);
	op_sa(a, b, 0);
	if (DEBUG_OUTPUT && mode)
		heaps_print(a, b);
}

/*
** pa (push a): Take the first element at the top of b and put it at the top of a.
** Do nothing if b is empty.
*/
void	op_pa(t_list **a, t_list **b, char mode)
{
	int		tmp;

	if (mode)
		ft_putstr("pa\n");
	if (*b != NULL)
	{
		tmp = (*b)->data;
		ft_lst_pop_first(b);
		ft_lst_add_front(a, tmp);
	}
	if (DEBUG_OUTPUT && mode)
		heaps_print(*a, *b);
}

/*
** pb (push b): Take the first element at the top of a and put it at the top of b.
** Do nothing if a is empty.
*/
void	op_pb(t_list **a, t_list **b, char mode)
{
	if (mode)
		ft_putstr("pb\n");
	op_pa(b, a, 0);
	if (DEBUG_OUTPUT && mode)
		heaps_print(*a, *b);
}
