/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:16:19 by shalfbea          #+#    #+#             */
/*   Updated: 2022/02/15 22:31:15 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# define DEBUG_OUTPUT 1
typedef struct s_list
{
	int				data;
	struct s_list	*next;
}	t_list;

t_list	*ps_inputs(int argc, char **argv);

//output_utils.c
int		ft_putnbr(int n);
int		ft_putstr(char *s);
void	error_and_exit(void);
void	heaps_print(t_list *a, t_list *b);

//lst_utils.c
t_list	*ft_lstnew(int num);
void	ft_lstclear(t_list **lst);
char	lst_is_sorted(t_list *lst);
int		ft_lst_pop_first(t_list **lst);
void	ft_lst_add_back(t_list **lst, int num);
void	ft_lst_add_front(t_list **lst, int num);

//ft_atoi_modded.c
int		ft_atoi_mod(const char *str, int *i);

//operations_swap_push.c
void	op_sa(t_list *a, t_list *b, char mode);
void	op_sb(t_list *a, t_list *b, char mode);
void	op_ss(t_list *a, t_list *b, char mode);
void	op_pa(t_list **a, t_list **b, char mode);
void	op_pb(t_list **a, t_list **b, char mode);

//operations_rotating.c
void	op_ra(t_list **a, t_list **b, char mode);
void	op_rb(t_list **a, t_list **b, char mode);
void	op_rr(t_list **a, t_list **b, char mode);

//operations_reverse_rotating.c
void	op_rra(t_list **a, t_list **b, char mode);
void	op_rrb(t_list **a, t_list **b, char mode);
void	op_rrr(t_list **a, t_list **b, char mode);

#endif
