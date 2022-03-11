/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:16:19 by shalfbea          #+#    #+#             */
/*   Updated: 2022/03/11 15:48:05 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# define DEBUG_OUTPUT 0
# define SHOW_ME 0

typedef struct s_list
{
	int				data;
	int				score_b;
	int				score_a;
	int				resulting_score;
	struct s_list	*next;
}	t_list;

typedef struct s_stacks
{
	t_list		*a;
	t_list		*b;
	long long	a_len;
	long long	b_len;
	int			min;
	int			max;
	int			median;
	char		*str;
}	t_stacks;

typedef struct s_op_num
{
	int		a;
	int		b;
}	t_op_num;

t_stacks	*init_and_input(int argc, char **argv);
int			ft_putnbr(int n);
int			ft_putstr(char *s);
void		error_and_exit(void);
void		heaps_print(t_stacks *stacks);
void		print_array(int	*array, int n);
t_list		*ft_lstnew(int num);
void		ft_lstclear(t_list **lst);
char		lst_is_sorted(t_list *lst);
int			ft_lst_size(t_list *lst);
void		exitter(t_stacks *stacks, char mode);
int			ft_lst_pop_first(t_list **lst);
void		ft_lst_add_back(t_list **lst, int num);
void		ft_lst_add_front(t_list **lst, int num);
int			ft_lst_pop_last(t_list **lst);
void		ft_lst_push_back(t_list **lst, int num);
int			ft_atoi_mod(const char *str, int *i, t_stacks *stacks);
int			ft_last_data(t_list *a);
int			ft_isspace(char c);
void		op_sa(t_stacks *stacks, char mode);
void		op_sb(t_stacks *stacks, char mode);
void		op_ss(t_stacks *stacks, char mode);
void		op_pa(t_stacks *stacks, char mode);
void		op_pb(t_stacks *stacks, char mode);
void		op_ra(t_stacks *stacks, char mode);
void		op_rb(t_stacks *stacks, char mode);
void		op_rr(t_stacks *stacks, char mode);
void		ra_doer(t_stacks *stacks, int counter);
void		rb_doer(t_stacks *stacks, int counter);
void		op_rra(t_stacks *stacks, char mode);
void		op_rrb(t_stacks *stacks, char mode);
void		op_rrr(t_stacks *stacks, char mode);
void		turning_back(t_stacks *stacks);
void		sorting(t_stacks *stacks);
int			sort_three(t_stacks *stack);
int			small_sort(t_stacks *stacks);
int			a_score(t_stacks *stack, int num);
void		score_marking(t_stacks *stacks);
t_op_num	element_to_move(t_stacks *stacks);
int			resulting_score(t_stacks *stacks, t_list *b);
void		finding_special_values(t_stacks *stacks, int median_needs);
void		median_find(t_stacks *stacks);
void		first_push_to_b(t_stacks *stacks);
void		push_to_b_seq(t_stacks *stacks);
int			ft_abs(int x);
int			ft_max2(int a, int b);
int			ft_str_simple_cmp(const char *s1, const char *s2);
void		bubble_sort(t_list *i);
void		marking_subseq(t_stacks *stacks, int *a, int *prev, int pos);
int			subseq_find(t_stacks *stacks);
#endif
