/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   marking_seq.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 19:25:10 by shalfbea          #+#    #+#             */
/*   Updated: 2022/03/10 19:25:33 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	mark_stack(t_stacks *stacks, int data)
{
	t_list	*a;

	a = stacks->a;
	while (a)
	{
		if (a->data == data)
		{
			a->score_a = 1;
			break ;
		}
		a = a->next;
	}
}

void	marking_subseq(t_stacks *stacks, int *a, int *prev, int pos)
{
	while (pos != -1)
	{
		mark_stack(stacks, a[pos]);
		pos = prev[pos];
	}
}
