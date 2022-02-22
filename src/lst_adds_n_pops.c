/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_adds_n_pops.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:26:39 by shalfbea          #+#    #+#             */
/*   Updated: 2022/02/22 17:50:57 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lst_pop_first(t_list **lst)
{
	t_list	*new_first;
	int		old_data;

	if (*lst == NULL)
		return (0);
	old_data = (*lst)->data;
	if ((*lst)->next == NULL)
	{
		free(*lst);
		*lst = NULL;
		return (old_data);
	}
	new_first = (*lst)->next;
	free(*lst);
	*lst = new_first;
	return (old_data);
}

int	ft_lst_pop_last(t_list **lst)
{
	int		old_data;
	t_list	*cur;

	if (lst == NULL)
		return (0);
	if ((*lst)->next == NULL)
	{
		old_data = (*lst)->data;
		free(*lst);
		*lst = NULL;
		return (old_data);
	}
	cur = *lst;
	while (cur->next->next)
		cur = cur->next;
	old_data = cur->next->data;
	free(cur->next);
	cur->next = NULL;
	return (old_data);
}

void	ft_lst_add_back(t_list **lst, int num)
{
	t_list	*tmp;

	if (*lst == NULL)
	{
		*lst = ft_lstnew(num);
		return ;
	}
	tmp = *lst;
	while ((tmp)->next)
		(tmp) = (tmp)->next;
	(tmp)->next = ft_lstnew(num);
}

void	ft_lst_push_back(t_list **lst, int num)
{
	t_list	*tmp;
	t_list	*next;

	if (*lst == NULL)
	{
		*lst = ft_lstnew(num);
		return ;
	}
	tmp = *lst;
	if (tmp->next == NULL)
	{
		tmp->next = ft_lstnew(num);
		return ;
	}
	next = tmp->next;
	tmp->next = ft_lstnew(num);
	tmp = tmp->next;
	tmp->next = next;
}
void	ft_lst_add_front(t_list **lst, int num)
{
	t_list	*tmp;

	if (*lst == NULL)
	{
		*lst = ft_lstnew(num);
		return ;
	}
	tmp = ft_lstnew(num);
	tmp->next = *lst;
	*lst = tmp;
}

int	ft_last_data(t_list *a)
{
	while (a->next)
		a = a->next;
	return (a->data);
}
