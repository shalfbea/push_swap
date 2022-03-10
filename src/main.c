/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:19:02 by shalfbea          #+#    #+#             */
/*   Updated: 2022/03/09 20:43:19 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

t_list	*lst_copy(t_list *a)
{
	t_list	*head;
	t_list	*tail;

	if (a == NULL)
		return (NULL);
	head = ft_lstnew(a->data);
	tail = head;
	a = a->next;
	while (a)
	{
		tail->next = ft_lstnew(a->data);
		tail = tail->next;
		a = a->next;
	}
	return (head);
}

int	new_value(t_list *sorted, int num)
{
	while (sorted)
	{
		if (sorted->data == num)
			return (sorted->score_a);
		sorted = sorted->next;
	}
	return (-1);
}

void	renummer(t_stacks *stacks)
{
	t_list	*a;
	t_list	*sorted_head;
	t_list	*sorted;
	int		counter;

	counter = 0;
	a = stacks->a;
	sorted_head = lst_copy(a);
	bubble_sort(sorted_head);
	sorted = sorted_head;
	while (sorted)
	{
		sorted->score_a = counter;
		counter++;
		sorted = sorted->next;
	}
	while (a)
	{
		a->data = new_value(sorted_head, a->data);
		a = a->next;
	}
	if (DEBUG_OUTPUT)
		heaps_print(stacks);
	ft_lstclear(&sorted_head);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = init_and_input(argc, argv);
	renummer(stacks);
	finding_special_values(stacks, 1);
	if (!stacks)
		exitter(stacks, 1);
	if (lst_is_sorted(stacks->a))
		exitter(stacks, 0);
	if (sort_three(stacks))
		exitter(stacks, 0);
	if (small_sort(stacks))
		exitter(stacks, 0);
	if (DEBUG_OUTPUT)
		heaps_print(stacks);
	if (subseq_find(stacks))
		push_to_b_seq(stacks);
	else
		first_push_to_b(stacks);
	if (DEBUG_OUTPUT)
		ft_putstr("\n=> ENDED PUSH TO B\n");
	sorting(stacks);
	if (!lst_is_sorted(stacks->a))
		ft_putstr("Something's wrong...\n");
	exitter(stacks, 0);
	return (0);
}
