/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap_push.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:41:17 by shalfbea          #+#    #+#             */
/*   Updated: 2022/02/21 15:42:45 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** sa (swap a): Swap the first 2 elements at the top of stack a.
** Do nothing if there is only one or no elements.
*/
void	op_sa(t_stacks *stacks, char mode)
{
	int	tmp;

	if (mode)
		ft_putstr("sa\n");
	if (stacks->a != NULL)
	{
		if (stacks->a->next != NULL)
		{
			tmp = stacks->a->data;
			stacks->a->data = stacks->a->next->data;
			stacks->a->next->data = tmp;
		}
	}
	if (mode && DEBUG_OUTPUT)
		heaps_print(stacks);
}

/*
** sb (swap b): Swap the first 2 elements at the top of stack b.
** Do nothing if there is only one or no elements.
*/
void	op_sb(t_stacks *stacks, char mode)
{
	int	tmp;

	if (mode)
		ft_putstr("sa\n");
	if (stacks->b != NULL)
	{
		if (stacks->b->next != NULL)
		{
			tmp = stacks->b->data;
			stacks->b->data = stacks->b->next->data;
			stacks->b->next->data = tmp;
		}
	}
	if (mode && DEBUG_OUTPUT)
		heaps_print(stacks);
}

/*
** ss : sa and sb at the same time.
*/
void	op_ss(t_stacks *stacks, char mode)
{
	if (mode)
		ft_putstr("ss\n");
	op_sa(stacks, 0);
	op_sa(stacks, 0);
	if (DEBUG_OUTPUT && mode)
		heaps_print(stacks);
}

/*
** pa (push a): Take the first element at the top of b
** and put it at the top of a.
** Do nothing if b is empty.
*/
void	op_pa(t_stacks *stacks, char mode)
{
	int		tmp;

	if (mode)
		ft_putstr("pa\n");
	if (stacks->b != NULL)
	{
		tmp = ft_lst_pop_first(&(stacks->b));
		ft_lst_add_front(&(stacks->a), tmp);
		stacks->a_len += 1;
		stacks->b_len -= 1;
	}
	if (DEBUG_OUTPUT && mode)
		heaps_print(stacks);
}

/*
** pb (push b): Take the first element at the top of a
** and put it at the top of b.
** Do nothing if a is empty.
*/
void	op_pb(t_stacks *stacks, char mode)
{
	int		tmp;

	if (mode)
		ft_putstr("pb\n");
	if (stacks->a != NULL)
	{
		tmp = ft_lst_pop_first(&(stacks->a));
		ft_lst_add_front(&(stacks->b), tmp);
		stacks->a_len -= 1;
		stacks->b_len += 1;
	}
	if (DEBUG_OUTPUT && mode)
		heaps_print(stacks);
}
