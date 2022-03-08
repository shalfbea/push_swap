/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resulting_score.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:28:26 by shalfbea          #+#    #+#             */
/*   Updated: 2022/03/08 16:07:02 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
void	change_scores_opt(t_stacks *stacks, t_list *b, int cases)
{
	if (cases == 1)
		b->score_a = stacks->a_len + b->score_a;
	else if (cases == 2)
		b->score_b = -(stacks->b_len - b->score_b);
	else if (cases == 3)
		b->score_b = stacks->b_len + b->score_b;
	else if (cases == 4)
		b->score_a = b->score_a - stacks->a_len;
}

int	resulting_score_more_cases(t_stacks *stacks, t_list *b, int min, int *cases)
{
	if (b->score_a < 0 && b->score_b > 0)
	{
		if (ft_max2(stacks->a_len + b->score_a, b->score_b) < min)
		{
			min = ft_max2(stacks->a_len + b->score_a, b->score_b);
			*cases = 1;
		}
		if (ft_max2(ft_abs(b->score_a), ft_abs(stacks->b_len - b->score_b)) < min)
		{
			min = ft_max2(ft_abs(b->score_a), ft_abs(stacks->b_len - b->score_b));
			*cases = 2;
		}
	}
	else if (b->score_a > 0 && b->score_b < 0)
	{
		if (ft_max2(b->score_a, stacks->b_len + b->score_b) < min)
		{
			min = ft_max2(b->score_a, stacks->b_len + b->score_b);
			*cases = 3;
		}
		if (ft_max2(ft_abs(b->score_a - stacks->a_len), ft_abs(b->score_b)) < min)
			min = ft_max2(ft_abs(b->score_a - stacks->a_len), ft_abs(b->score_b));
			*cases = 4;
	}
	return (min);
}
*/

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
	/*
	min = resulting_score_more_cases(stacks, b, min, &cases);
	change_scores_opt(stacks, b, cases);
	return (min);
	*/
}
