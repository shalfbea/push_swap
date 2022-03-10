/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resulting_score.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:28:26 by shalfbea          #+#    #+#             */
/*   Updated: 2022/03/10 19:21:49 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
