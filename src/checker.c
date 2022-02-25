/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 13:53:28 by shalfbea          #+#    #+#             */
/*   Updated: 2022/02/25 16:23:26 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	execute_operation(t_stacks *stacks)
{
	if (ft_str_simple_cmp(stacks->str, "sa"))
		op_sa(stacks, 0);
	else if (ft_str_simple_cmp(stacks->str, "sb"))
		op_sb(stacks, 0);
	else if (ft_str_simple_cmp(stacks->str, "ss"))
		op_ss(stacks, 0);
	else if (ft_str_simple_cmp(stacks->str, "pa"))
		op_pa(stacks, 0);
	else if (ft_str_simple_cmp(stacks->str, "pb"))
		op_pb(stacks, 0);
	else if (ft_str_simple_cmp(stacks->str, "ra"))
		op_ra(stacks, 0);
	else if (ft_str_simple_cmp(stacks->str, "rb"))
		op_rb(stacks, 0);
	else if (ft_str_simple_cmp(stacks->str, "rr"))
		op_rr(stacks, 0);
	else if (ft_str_simple_cmp(stacks->str, "rra"))
		op_rra(stacks, 0);
	else if (ft_str_simple_cmp(stacks->str, "rrb"))
		op_rrb(stacks, 0);
	else if (ft_str_simple_cmp(stacks->str, "rrr"))
		op_rrr(stacks, 0);
	else
		exitter(stacks, 1);
}

void	checking(t_stacks *stacks)
{
	int		bytes_read;
	int		i;

	stacks->str = (char *)malloc(sizeof(char) * 4);
	if (!stacks->str)
		exitter(stacks, 0);
	bytes_read = 1;
	i = -1;
	while (bytes_read > 0)
	{
		++i;
		bytes_read = read(0, &(stacks->str[i]), 1);
		if (i == 4 && stacks->str[i] != '\n')
			exitter(stacks, 1);
		if (stacks->str[i] == '\n' || (bytes_read == 0 && i > 0))
		{
			stacks->str[i] = '\0';
			execute_operation(stacks);
			i = -1;
		}
	}
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = init_and_input(argc, argv);
	if (!stacks)
		exitter(stacks, 1);
	heaps_print(stacks);
	checking(stacks);
	if (lst_is_sorted(stacks->a) && stacks->b == NULL)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	exitter(stacks, 0);
	return (0);
}
