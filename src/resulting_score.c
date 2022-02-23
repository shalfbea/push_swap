/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resulting_score.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:28:26 by shalfbea          #+#    #+#             */
/*   Updated: 2022/02/23 15:55:45 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	change_scores_opt(t_stacks *stacks, t_list *b, int cases)
{
	if (cases == 1)
		b->score_b = stacks->b_len + b->score_b;
	else if (cases == 2)
		b->score_a = stacks->a_len - b->score_a;
	else if (cases == 3)
		b->score_a = stacks->a_len + b->score_a;
	else if (cases == 4)
		b->score_b = stacks->b_len - b->score_b;

}

int	resulting_score_more_cases(t_stacks *stacks, t_list *b, int min, int *cases)
{
	if (b->score_b >= 0)
	{
		if (ft_max2(stacks->a_len + b->score_a, ft_abs(b->score_b)) < min)
		{
			min = ft_max2(stacks->a_len + b->score_a, b->score_b);
			*cases = 3;
		}
		if (ft_max2(ft_abs(b->score_a) ,stacks->b_len - b->score_b) < min)
		{
			min = ft_max2(ft_abs(b->score_a), b->score_b - stacks->b_len);
			*cases = 4;
		}
	}
	else if (ft_max2(ft_abs(b->score_b), stacks->a_len - b->score_a) < min)
	{
		min = ft_max2(ft_abs(b->score_b), b->score_a - stacks->a_len);
		*cases = 2;
	}
	return (min);
}

int	resulting_score(t_stacks *stacks, t_list *b)
{
	int		min;
	int		cases;

	min = ft_abs(b->score_a) + ft_abs(b->score_b) + 1;
	cases = 0;
	if ((b->score_a >= 0 && b->score_b >= 0) || \
		(b->score_a < 0 && b->score_b < 0))
		min = ft_max2(ft_abs(b->score_a), ft_abs(b->score_b));
	else
	{
		if (b->score_b < 0)
		{
			if (ft_max2(stacks->b_len + b->score_b, b->score_a) < min)
			{
				min = ft_max2(stacks->b_len + b->score_b, b->score_a);
				cases = 1;
			}
		}
		min = resulting_score_more_cases(stacks, b, min, &cases);
	}
	change_scores_opt(stacks, b, cases);
	return (min);
}
