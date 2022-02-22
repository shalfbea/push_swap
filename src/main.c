/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:19:02 by shalfbea          #+#    #+#             */
/*   Updated: 2022/02/22 19:04:04 by shalfbea         ###   ########.fr       */
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
	heaps_print(stacks);
	if (lst_is_sorted(stacks->a))
		ft_putstr("it's sorted\n");
	else
		ft_putstr("it's NOT sorted\n");
	printf("min: %d max : %d median: %d", stacks->min, stacks->max, stacks->median);
	first_push_to_b(stacks);
	score_marking(stacks);
	heaps_print(stacks);
	exitter(stacks, 0);
	return (0);
}
