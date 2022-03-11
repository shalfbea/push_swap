/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subsequence.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:26:29 by shalfbea          #+#    #+#             */
/*   Updated: 2022/03/11 15:20:58 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	array_searcher(int integrated, t_list **a, int **array, int *i)
{
	char	found;

	found = 0;
	while ((*a) && !found)
	{
		(*array)[(*i)++] = (*a)->data;
		if ((*a)->data == integrated)
			found = 1;
		(*a) = (*a)->next;
	}
	return (found);
}

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
			break ;
		a = a->next;
	}
	if (array_searcher(stacks->max, &a, array, &i))
		return (i);
	a = stacks->a;
	array_searcher(stacks->max, &a, array, &i);
	return (i);
}

void	prework(int *a, int *prev, int *d, int n)
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

int	find_lis(int *d, int n)
{
	int	pos;
	int	len;
	int	i;

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
	n = find_lis(d, n);
	marking_subseq(stacks, array, prev, n);
	if (array)
		free(array);
	if (prev)
		free(prev);
	if (d)
		free(d);
	return (1);
}
