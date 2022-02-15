/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:16:41 by shalfbea          #+#    #+#             */
/*   Updated: 2022/02/15 18:32:42 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_clever_append(t_list **lst, t_list **cur, int num)
{
	if (*lst == NULL)
	{
		*cur = ft_lstnew(num);
		*lst = *cur;
	}
	else
	{
		(*cur)->next = ft_lstnew(num);
		*cur = (*cur)->next;
	}
}

t_list	*ps_inputs(int argc, char **argv)
{
	t_list	*lst;
	t_list	*cur;
	int		i;
	int		arg;

	lst = NULL;
	cur = NULL;
	if (argc < 1)
		error_and_exit();
	arg = 0;
	while (++arg < argc)
	{
		if (!argv[arg][0])
			error_and_exit();
		i = 0;
		while (argv[arg][i])
			lst_clever_append(&lst, &cur, ft_atoi_mod(argv[arg], &i));
	}
	if (!lst)
		error_and_exit();
	return (lst);
}
