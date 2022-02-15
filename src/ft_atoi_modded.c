/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_modded.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:13:29 by shalfbea          #+#    #+#             */
/*   Updated: 2022/02/15 18:14:07 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(char c)
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
	if (!ft_isdigit(str[*i]))
		error_and_exit();
	return (*i);
}

int	ft_atoi_mod(const char *str, int *i)
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
			return (-1);
		if ((sign < 0) && (res > 2147483648))
			return (0);
	}
	return ((int) res * sign);
}
