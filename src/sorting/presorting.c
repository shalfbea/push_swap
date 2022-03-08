/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:32:06 by shalfbea          #+#    #+#             */
/*   Updated: 2022/03/08 19:02:29 by shalfbea         ###   ########.fr       */
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

void	first_push_to_b(t_stacks *stacks)
{
	int		counter;

	counter = 0;
	while (1)
	{
		if (stacks->a->data != stacks->min && stacks->a->data != stacks->max \
				&& stacks->a->data != stacks->median)
			op_pb(stacks, 1);
		else if (counter < 3)
		{
			//Think about optimization, when these 2 nums are near
			op_ra(stacks, 1);
			counter++;
		}
		else
			break ;
	}
	sort_three(stacks);
}

int		*that_seq(t_stacks *stacks, int *marked)
{
	t_list	*a;
	int		*res;
	int		i;

	*marked = 0;
	a = stacks->a;
	while (a)
	{
		if (a->score_a)
			(*marked)++;
		a = a->next;
	}
	res = NULL;
	res = (int *) malloc(sizeof(int) * (*marked));
	if (!res)
		exitter(stacks, 0);
	i = 0;
	a = stacks->a;
	while (a)
	{
		if (a->score_a)
			res[i++] = a->data;
		a = a->next;
	}
	if (DEBUG_OUTPUT)
	{
		i = 0;
		ft_putstr("seq : ");
		while (i < *marked)
		{
			ft_putnbr(res[i]);
			ft_putstr(" ");
			++i;
		}
		ft_putstr("\n");
	}

	return (res);
}

char	check_in_seq(int data, int *array, int marked)
{
	int i;

	i = 0;
	while (i < marked)
	{
		if (data == array[i])
			return (1);
		i++;
	}
	return (0);
}

void	push_to_b_seq(t_stacks *stacks)
{
	int		counter;
	int		marked;
	int		*seq;

	counter = 0;
	seq = that_seq(stacks, &marked);
	while (1)
	{
		if (!check_in_seq(stacks->a->data, seq, marked))
			op_pb(stacks, 1);
		else if (counter < marked)
		{
			op_ra(stacks, 1);
			counter++;
		}
		else
			break ;
	}
}
