/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_marking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 19:08:16 by shalfbea          #+#    #+#             */
/*   Updated: 2022/02/23 15:58:59 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	a_score(t_stacks * stack, int num)
{
	int	start;
	int	counter;
	int	last;
	t_list	*a;

	a = stack->a;
	counter = 0;
	last = ft_last_data(a);
	start = a->data;
	if (start > num && last < num)
		return (0);
	if (start < num && last > num)
		return (-1);
	while (a->next)
	{
		counter++;
		if (a->data < num && a->next->data > num)
			break;
		a = a->next;
	}
	if (stack->a_len - counter < counter)
		counter -= stack->a_len;
	return (counter);
}

void	score_marking(t_stacks *stacks)
{
	t_list	*b;
	int		cur_mid;
	int		counter;

	counter = 0;
	b = stacks->b;
	cur_mid = stacks->b_len / 2;
	while (b)
	{
		if (counter <= cur_mid)
			b->score_b = counter;
		else
			b->score_b = counter - stacks->b_len;
		b->score_a = a_score(stacks, b->data);
		b = b->next;
		counter++;
	}
}

t_op_num	element_to_move(t_stacks *stacks)
{
	t_list	*found;
	t_list	*b;
	int		minimum_operations;
	t_op_num	result;

	result.a = 0;
	result.b = 0;
	score_marking(stacks);
	b = stacks->b;
	if (b == NULL)
		return result;
	minimum_operations = abs(b->score_a) + abs(b->score_a);
	found = b;
	//score_marking(stacks);
	while (b)
	{
		b->resulting_score = resulting_score(stacks, b);
		if (b->resulting_score < minimum_operations)
		{
			minimum_operations = b->resulting_score;
			found = b;
		}
		b = b->next;
	}
	result.a = found->score_a;
	result.b = found->score_b;

	return (result);
}
