/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subsequence.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:26:29 by shalfbea          #+#    #+#             */
/*   Updated: 2022/03/08 19:07:19 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	from_min_to_max(t_stacks *stacks, int **array)
{
	t_list	*a;
	int		i;
	char	found_max;

	*array = (int *) malloc(sizeof(int) * stacks->a_len);
	i = 0;
	if (!(*array))
		return (0);
	found_max = 0;
	a = stacks->a;
	while (a)
	{
		if (a->data == stacks->min)
			break;
		a = a->next;
	}
	while (a && !found_max)
	{
		(*array)[i++] = a->data;
		if (a->data == stacks->max)
			found_max = 1;
		a = a->next;
	}
	if (found_max)
		return (i);
	a = stacks->a;
	while (a)
	{
		(*array)[i++] = a->data;
		if (a->data == stacks->max)
			break;
		a = a->next;
	}
	return (i);
}

void prework(int *a, int *prev, int *d, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		d[i] = 1;
		prev[i] = -1;
		j = 0;
		while (j < i)
		{
			if (a[j] < a[i] && d[j] + 1 > d[i])
			{
				d[i] = d[j] + 1;
				prev[i] = j;
			}
			j++;
		}
		i++;
	}
}

void	mark_stack(t_stacks *stacks, int data)
{
	t_list	*a;

	a = stacks->a;
	while(a)
	{
		if (a->data == data)
		{
			a->score_a = 1;
			break;
		}
		a = a->next;
	}
}

void	view_marked(t_stacks *stacks)
{
	t_list	*a;

	a = stacks->a;
	while(a)
	{
		if (a->score_a)
		{
			ft_putnbr(a->data);
			ft_putstr(" ");
		}
		a = a->next;
	}
	ft_putstr("\n");
}

int	findLIS(int *a, int *prev, int *d, int n)
{
	int	pos;
	int	len;
	int	i;

	(void) a;
	(void) prev;
	pos = 0;
	len = d[0];
	i = 0;
	while (i < n)
	{
		if (d[i] > len)
		{
			pos = i;
			len = d[i];
		}
		i++;
	}
	return (pos);
}

void	marking_subseq(t_stacks *stacks, int *a, int *prev, int pos)
{
	while (pos != -1)
	{
		mark_stack(stacks, a[pos]);
		pos = prev[pos];
	}
}

int	subseq_find(t_stacks *stacks)
{
	int	*array;
	int	*prev;
	int	*d;
	int	n;

	n = from_min_to_max(stacks, &array);
	prev = (int *) malloc(sizeof(int) * n);
	d = (int *) malloc(sizeof(int) * n);
	if (!array || !prev || !d)
		exitter(stacks, 0);
	if (DEBUG_OUTPUT)
		print_array(array, n);
	prework(array, prev, d, n);
	n = findLIS(array, prev, d, n);
	marking_subseq(stacks, array , prev, n);
	if (DEBUG_OUTPUT)
		view_marked(stacks);
	free(array);
	free(prev);
	free(d);
	return (1);
}
