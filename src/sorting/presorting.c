/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:32:06 by shalfbea          #+#    #+#             */
/*   Updated: 2022/03/10 19:21:13 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(t_list *i)
{
	t_list	*j;
	int		tmp;

	while (i->next)
	{
		j = i->next;
		while (j)
		{
			if (j->data < i->data)
			{
				tmp = i->data;
				i->data = j->data;
				j->data = tmp;
			}
			j = j->next;
		}
		i = i->next;
	}
}

void	median_find(t_stacks *stacks)
{
	t_list	*new_head;
	t_list	*new_cur;
	t_list	*a;
	int		counter;

	a = stacks->a;
	new_head = NULL;
	while (a)
	{
		ft_lst_add_back(&new_head, a->data);
		a = a->next;
	}
	bubble_sort(new_head);
	counter = 0;
	new_cur = new_head;
	while (new_cur)
	{
		if (counter == stacks->a_len / 2)
			stacks->median = new_cur->data;
		counter++;
		new_cur = new_cur->next;
	}
	ft_lstclear(&new_head);
}

void	finding_special_values(t_stacks *stacks, int median_needs)
{
	t_list	*a;

	a = stacks->a;
	if (!a)
		exitter(stacks, 1);
	stacks->min = a->data;
	stacks->max = a->data;
	if (median_needs)
		median_find(stacks);
	while (a)
	{
		if (a->data > stacks->max)
			stacks->max = a->data;
		if (a->data < stacks->min)
			stacks->min = a->data;
		a = a->next;
	}
}
