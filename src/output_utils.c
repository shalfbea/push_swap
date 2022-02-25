/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:57:47 by shalfbea          #+#    #+#             */
/*   Updated: 2022/02/25 17:58:51 by shalfbea         ###   ########.fr       */
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
		return (0);
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
		return (2);
	}
	if (*n < 0)
	{
		write(1, "-", 1);
		*n *= -1;
		return (1);
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
	int		sign;

	sign = ft_putnbr_cases(&n);
	if (sign == 2)
		return (11);
	tmp = n;
	tens = 1;
	while (tmp > 9)
	{
		tmp /= 10;
		tens *= 10;
	}
	tmp = 0;
	while (tens > 0)
	{
		cur = (char)(n / tens) + '0';
		write(1, &cur, 1);
		tmp++;
		n %= tens;
		tens /= 10;
	}
	return (tmp + sign);
}

void	error_and_exit(void)
{
	ft_putstr("Error!");
	exit(0);
}

void	heaps_print(t_stacks *stacks)
{
	int		a_len;
	t_list	*a;
	t_list	*b;

	if (DEBUG_OUTPUT && SHOW_ME)
		element_to_move(stacks);
	a = stacks->a;
	b = stacks->b;
	ft_putstr("============\n");
	while (a || b)
	{
		if (a)
		{
			a_len = ft_putnbr(a->data);
			a = a->next;
		}
		else
			a_len = 0;
		if (b)
		{
			while (++a_len < 11)
				ft_putstr(" ");
			a_len = ft_putnbr(b->data);
			if (SHOW_ME)
			{
				while (++a_len < 11)
					ft_putstr(" ");
				a_len = ft_putnbr(b->score_b);
				while (++a_len < 5)
					ft_putstr(" ");
				a_len = ft_putnbr(b->score_a);
				while (++a_len < 5)
					ft_putstr(" ");
				ft_putnbr(b->resulting_score);
			}
			b = b->next;
		}
		ft_putstr("\n");
	}
	ft_putstr("(");
	a_len = ft_putnbr(stacks->a_len);
	ft_putstr(")");
	while(++a_len < 9)
		ft_putstr(" ");
	ft_putstr("(");
	ft_putnbr(stacks->b_len);
	ft_putstr(")");
	ft_putstr("\n============\n");
}
