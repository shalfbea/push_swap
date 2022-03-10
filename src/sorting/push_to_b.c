/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 20:50:20 by shalfbea          #+#    #+#             */
/*   Updated: 2022/03/09 20:51:09 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (marked < 3)
		return (NULL);
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
	return (res);
}

char	check_in_seq(int data, int *array, int marked)
{
	int	i;

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
	if (!seq)
		first_push_to_b(stacks);
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
	if (that_seq)
		free(that_seq);
}
