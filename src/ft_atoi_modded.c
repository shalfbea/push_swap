/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_modded.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:13:29 by shalfbea          #+#    #+#             */
/*   Updated: 2022/02/25 16:15:16 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\r')
		return (1);
	if (c == '\t' || c == '\n' || c == '\v')
		return (1);
	return (0);
}

static int	ft_isdigit(int c)
{
	if ((c >= '0') && (c <= '9'))
		return (1);
	return (0);
}

static int	ft_atoi_helper(const char *str, int *sign, int *i)
{
	while (ft_isspace(str[*i]))
		++(*i);
	if (str[*i] == '-')
	{
		*sign = -1;
		++(*i);
	}
	else if (str[*i] == '+')
		++(*i);
	if ((!ft_isdigit(str[*i])) && (!ft_isspace(str[*i])))
		error_and_exit();
	return (*i);
}

int	ft_atoi_mod(const char *str, int *i, t_stacks *stacks)
{
	size_t	res;
	int		sign;

	sign = 1;
	res = 0;
	ft_atoi_helper(str, &sign, i);
	while (ft_isdigit(str[*i]))
	{
		res = (res * 10) + str[*i] - '0';
		++(*i);
		if ((sign > 0) && (res > 2147483647))
			exitter(stacks, 1);
		if ((sign < 0) && (res > 2147483648))
			exitter(stacks, 1);
	}
	return ((int) res * sign);
}
