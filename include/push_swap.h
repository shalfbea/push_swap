/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:16:19 by shalfbea          #+#    #+#             */
/*   Updated: 2022/02/12 19:44:50 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				*data;
	struct s_list	*next;
}	t_list;

t_list *ps_inputs(int argc, char **argv);

//output_utils.c
int		ft_putnbr(int n);
int		ft_putstr(char *s);
#endif

