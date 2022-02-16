/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:19:02 by shalfbea          #+#    #+#             */
/*   Updated: 2022/02/16 17:23:04 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exitter(t_stacks *stacks, char mode)
{
	if (mode)
		ft_putstr("Error!");
	ft_lstclear(&(stacks->a));
	ft_lstclear(&(stacks->b));
	free(stacks);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = init_and_input(argc, argv);
	heaps_print(stacks);
	if (lst_is_sorted(stacks->a))
		ft_putstr("it's sorted\n");
	else
		ft_putstr("it's NOT sorted\n");
	ft_putnbr(stacks->a_len);
	exitter(stacks, 0);
	return (0);
}
