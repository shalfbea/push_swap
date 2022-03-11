/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_marking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 19:08:16 by shalfbea          #+#    #+#             */
/*   Updated: 2022/03/11 15:38:15 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	a_score(t_stacks *stack, int num)
{
	int		start;
	int		counter;
	int		last;
	t_list	*a;

	a = stack->a;
	counter = 0;
	last = ft_last_data(a);
	start = a->data;
	if (start > num && last < num)
		return (0);
	while (a->next)
	{
		counter++;
		if (a->data < num && a->next->data > num)
			break ;
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

int	resulting_score(t_stacks *stacks, t_list *b)
{
	int		min;
	int		cases;

	(void) stacks;
	min = ft_abs(b->score_a) + ft_abs(b->score_b);
	cases = 0;
	if (b->score_a >= 0 && b->score_b >= 0)
		return (ft_max2(b->score_a, b->score_b));
	if (b->score_a <= 0 && b->score_b <= 0)
		return (ft_max2(ft_abs(b->score_a), ft_abs(b->score_b)));
	return (min);
}

t_op_num	element_to_move(t_stacks *stacks)
{
	t_list		*found;
	t_list		*b;
	t_op_num	result;

	result.a = 0;
	result.b = 0;
	score_marking(stacks);
	b = stacks->b;
	if (b == NULL)
		return (result);
	found = b;
	while (b)
	{
		b->resulting_score = resulting_score(stacks, b);
		if (b->resulting_score < found->resulting_score)
			found = b;
		b = b->next;
	}
	result.a = found->score_a;
	result.b = found->score_b;
	return (result);
}
