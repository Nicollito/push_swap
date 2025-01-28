/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 09:44:04 by nimadela          #+#    #+#             */
/*   Updated: 2025/01/28 10:56:33 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_to_b(t_list **stack, t_stat *stat)
{
	if (stack[0]->content >= stat->quart1 && stack[0]->content <= stat->mean)
	{
		write(1, push(stack, 'b'), 3);
		if (stack[1]->next)
			write(1, rotate(stack, 'b'), 3);
	}
	else if (stack[0]->content >= stat->mean && stack[0]->content <= stat->quart3)
		write(1, push(stack, 'b'), 3);
	else
		write(1, rotate(stack, 'a'), 3);
}
