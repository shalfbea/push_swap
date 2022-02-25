/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:19:02 by shalfbea          #+#    #+#             */
/*   Updated: 2022/02/25 18:44:43 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = init_and_input(argc, argv);
	if (!stacks)
		exitter(stacks, 1);
	if (lst_is_sorted(stacks->a))
		exitter(stacks, 0);
	if (sort_three(stacks))
		exitter(stacks, 0);
	finding_special_values(stacks);
	if (small_sort(stacks))
		exitter(stacks, 0);
	if (DEBUG_OUTPUT)
	{
		heaps_print(stacks);
		printf("min: %d max : %d median: %d", stacks->min, stacks->max, stacks->median);
	}
	first_push_to_b(stacks);
	if (DEBUG_OUTPUT)
	{
		ft_putstr("\n=> ENDED PUSH TO B\n");
		heaps_print(stacks);
	}
	sorting(stacks);
	if (!lst_is_sorted(stacks->a))
		ft_putstr("Something's wrong...");
	exitter(stacks, 0);
	return (0);
}
