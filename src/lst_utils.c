/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 19:39:15 by shalfbea          #+#    #+#             */
/*   Updated: 2022/02/21 19:18:44 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Allocates (with malloc(3)) and returns a new
** element. The variable ’content’ is initialized
** with the value of the parameter ’content’. The
** variable ’next’ is initialized to NULL.
*/
t_list	*ft_lstnew(int num)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		//return (NULL);
		exit(0);
	list->data = num;
	list->score_b = 0;
	list->score_a = 0;
	list->next = NULL;
	return (list);
}

/*
** Deletes and frees the given element and every
** successor of that element, using the function ’del’
** and free(3).
** Finally, the pointer to the list must be set to
** NULL.
*/
void	ft_lstclear(t_list **lst)
{
	t_list	*cur_elem;
	t_list	*next_elem;
	char	check;

	check = 1;
	if (*lst == NULL)
		//return ;
		exit(0);
	cur_elem = *lst;
	next_elem = *lst;
	while (check)
	{
		if (cur_elem->next)
			next_elem = cur_elem->next;
		else
			check = 0;
		free(cur_elem);
		cur_elem = next_elem;
	}
	*lst = NULL;
}

char	lst_is_sorted(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
	{
		if (lst->data > lst->next->data)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	ft_lst_size(t_list *lst)
{
	int	counter;

	counter = 0;
	while (lst)
	{
		counter++;
		if (lst->next)
			lst = lst->next;
		else
			lst = NULL;
	}
	return (counter);
}
