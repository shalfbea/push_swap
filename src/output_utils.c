/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:57:47 by shalfbea          #+#    #+#             */
/*   Updated: 2022/02/12 19:35:52 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Outputs the string ’s’ to the 1
** descriptor.
*/
int	ft_putstr(char *s)
{
	int	len;

	if (s == NULL)
		return ;
	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
	return (len);
}

static char	ft_putnbr_cases(int *n)
{
	if (*n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (1);
	}
	if (*n < 0)
	{
		write(1, "-", 1);
		*n *= -1;
	}
	return (0);
}

/*
** Outputs the integer ’n’ to the given file
** descriptor.
*/
int	ft_putnbr(int n)
{
	int		tmp;
	int		tens;
	char	cur;

	if (ft_putnbr_cases(&n))
		return ;
	tmp = n;
	tens = 1;
	while (tmp > 9)
	{
		tmp /= 10;
		tens *= 10;
	}
	tmp = tens;
	while (tens > 0)
	{
		cur = (char)(n / tens) + '0';
		write(1, &cur, 1);
		n %= tens;
		tens /= 10;
	}
	return (tmp);
}
