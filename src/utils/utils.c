/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:42:29 by shalfbea          #+#    #+#             */
/*   Updated: 2022/02/25 14:57:49 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int x)
{
	if (x < 0)
		return (-1 * x);
	return (x);
}

int	ft_max2(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_str_simple_cmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] == s2[i]) && s1[i] && s2[i])
		++i;
	if ((unsigned char)s1[i] - s2[i] != 0 || (s1[i]) || (s2[i]))
		return (0);
	return (1);
}
