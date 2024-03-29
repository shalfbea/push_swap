/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:26:23 by shalfbea          #+#    #+#             */
/*   Updated: 2022/03/11 15:31:51 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	lst_clever_append(t_list **lst, t_list **cur, int num)
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

static t_list	*input_handler(int argc, char **argv, t_stacks *stacks)
{
	t_list	*lst;
	t_list	*cur;
	int		i;
	int		arg;

	lst = NULL;
	cur = NULL;
	arg = 0;
	while (++arg < argc)
	{
		if (!argv[arg][0])
			exitter(stacks, 1);
		i = 0;
		while (argv[arg][i])
		{
			lst_clever_append(&lst, &cur, ft_atoi_mod(argv[arg], &i, stacks));
			while (ft_isspace(argv[arg][i]))
				++i;
		}
	}
	if (!lst)
		exitter(stacks, 1);
	return (lst);
}

static int	check_n_count(t_stacks *stacks)
{
	int		counter;
	t_list	*tmp;
	t_list	*checking;

	checking = stacks->a;
	counter = 0;
	while (checking)
	{
		if (checking->next)
		{
			checking = checking->next;
			tmp = stacks->a;
			while (tmp != checking)
			{
				if (tmp->data == checking->data)
					exitter(stacks, 1);
				tmp = tmp->next;
			}
		}
		else
			checking = NULL;
		counter++;
	}
	return (counter);
}

t_stacks	*init_and_input(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = (t_stacks *) malloc(sizeof(t_stacks));
	if (!stacks)
		exit(0);
	stacks->a = NULL;
	stacks->b = NULL;
	stacks->str = NULL;
	if (argc < 2)
		exitter(stacks, 0);
	if (argc == 2 && !argv[1][0])
		exitter(stacks, 0);
	stacks->a = input_handler(argc, argv, stacks);
	stacks->a_len = check_n_count(stacks);
	stacks->b_len = 0;
	return (stacks);
}
