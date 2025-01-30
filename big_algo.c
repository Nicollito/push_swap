/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 09:44:04 by nimadela          #+#    #+#             */
/*   Updated: 2025/01/30 17:24:10 by nimadela         ###   ########.fr       */
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
	if (!verif_quart(stat, stack[0]))
	{
		if (stack[0]->content < stat->quart1)
		{
			write(1, push(stack, 'b'), 3);
			write(1, rotate(stack, 'b'), 3);
		}
		else
			write(1, push(stack, 'b'), 3);
	}
}

void	sort_to_a(t_list **stack)
{
	int	i;

	i = count_rotate_a(stack[0], stack[1]);
	while (found_max(stack[0]) != ft_lstlast(stack[0]))
		write(1, rotate(stack, 'a'), 3);
	while (i != 0)
	{
		if (i < 0)
		{
			write(1, reverse_rotate(stack, 'a'), 4);
			i++;
		}
		else
		{
			write(1, rotate(stack, 'a'), 3);
			i--;
		}
	}
	write(1, push(stack, 'a'), 3);
}
