/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:16:41 by shalfbea          #+#    #+#             */
/*   Updated: 2022/02/10 17:21:04 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ps_inputs(t_list lst, int argc, char **argv)
{
	(void ) lst;
	(void ) argv;
	if (argc < 1)
	{
		ft_putstr_fd("Error!", 1);
		exit(0);
	}
}
