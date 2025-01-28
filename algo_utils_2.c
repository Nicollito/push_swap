/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:06:06 by nimadela          #+#    #+#             */
/*   Updated: 2025/01/28 13:18:47 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calc_stat(t_stat *stat, t_list *stack)
{
	long long int	total;
	int				len;
	t_list			*current;

	total = 0;
	len = stack_len(stack);
	current = stack;
	while (current)
	{
		total += current->content;
		current = current->next;
	}
	stat->mean = total / len;
	stat->quart1 = (found_min(stack)->content - stat->mean) / 2;
	stat->quart3 = (found_max(stack)->content - stat->mean) / 2;
}
