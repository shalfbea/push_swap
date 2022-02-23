/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:19:02 by shalfbea          #+#    #+#             */
/*   Updated: 2022/02/23 17:22:46 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exitter(t_stacks *stacks, char mode)
{
	if (mode)
		//ft_putstr("Error!");
		write(2, "Error!", 6);
	ft_lstclear(&(stacks->a));
	ft_lstclear(&(stacks->b));
	if (stacks != NULL)
		free(stacks);
	exit(0);
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = init_and_input(argc, argv);
	if (!stacks)
		exitter(stacks, 1);
	if (DEBUG_OUTPUT)
	{
		heaps_print(stacks);
		printf("min: %d max : %d median: %d", stacks->min, stacks->max, stacks->median);
	}
	if (lst_is_sorted(stacks->a))
		exitter(stacks, 0);
	first_push_to_b(stacks);
	if (DEBUG_OUTPUT)
	{
		ft_putstr("\n=> ENDED PUSH TO B\n");
		heaps_print(stacks);
	}
	sorting(stacks);
	exitter(stacks, 0);
	return (0);
}
