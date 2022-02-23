/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:24:40 by shalfbea          #+#    #+#             */
/*   Updated: 2022/02/23 18:07:05 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_three(t_stacks *stack)
{
	t_list	*a;

	a = stack->a;
	if (ft_lst_size(a) >3)
		return (0);
	return (1);
}
