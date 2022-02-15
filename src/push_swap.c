/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:19:02 by shalfbea          #+#    #+#             */
/*   Updated: 2022/02/15 22:25:45 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;


	a = NULL;
	b = NULL;
	a = ps_inputs(argc, argv);
	heaps_print(a, b);
	if (lst_is_sorted(a))
		ft_putstr("it's sorted\n");
	else
		ft_putstr("it's NOT sorted\n");
	op_ra(&a, &b, 1);
	op_ra(&a, &b, 1);
	ft_lstclear(&a);
	ft_lstclear(&b);
	exit(0);
	return (0);
}
