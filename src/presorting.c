/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:32:06 by shalfbea          #+#    #+#             */
/*   Updated: 2022/02/23 18:17:17 by shalfbea         ###   ########.fr       */
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

int	median_find(t_stacks *stacks)
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
	if (DEBUG_OUTPUT)
		ft_putstr("\n Sorted_tmp_list : ");
	counter = 0;
	new_cur = new_head;
	while (new_cur)
	{
		if (DEBUG_OUTPUT)
		{
			ft_putnbr(new_cur->data);
			ft_putstr(" ");
		}
		if (counter == stacks->a_len / 2)
			stacks->median = new_cur->data;
		counter++;
		new_cur = new_cur->next;
	}
	if (DEBUG_OUTPUT)
		ft_putstr("\n");
	ft_lstclear(&new_head);
	return (0);//fix
}

void	finding_special_values(t_stacks *stacks)
{
	t_list	*a;

	a = stacks->a;
	if (!a)
		exitter(stacks, 1);
	stacks->min = a->data;
	stacks->max = a->data;
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

void	first_push_to_b(t_stacks *stacks)
{
	int		counter;

	counter = 0;
	while (1)
	{
		//to_delete
		if (stacks->a->data != stacks->min && stacks->a->data != stacks->max)// && stacks->a->data != stacks->median)
		{
			// Think about finding presort optimization here
			op_pb(stacks, 1);
			if (stacks->a->data > stacks->median)
				op_rb(stacks, 1);
		}
		else if (counter < 2) //3
		{
			//Think about optimization, when these 2 nums are near
			op_ra(stacks, 1);
			counter++;
		}
		else
			break ;
	}
}
