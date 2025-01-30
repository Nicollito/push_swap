/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:06:06 by nimadela          #+#    #+#             */
/*   Updated: 2025/01/30 17:13:21 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calc_stat(t_stat *stat, t_list *stack)
{
	stat->mean = found_max(stack)->content * 0.5;
	stat->quart1 = found_max(stack)->content * 0.25;
	stat->quart3 = found_max(stack)->content * 0.75;
}

int	verif_quart(t_stat *stat, t_list *stack)
{
	while (stack && (stack->content < stat->quart1
		|| stack->content > stat->quart3))
		stack = stack->next;
	if (stack)
		return (1);
	return (0);
}

int	count_rotate_a(t_list *stack_a, t_list *stack_b)
{
	int	i;
	int	len;

	i = 0;
	len = stack_len(stack_a);
	if (stack_b->content < stack_a->content)
		return (0);
	while (stack_a->next)
	{
		if (stack_b->content > stack_a->content &&
			stack_b->content < (stack_a->next)->content)
			break;
		stack_a = stack_a->next;
		i++;
	}
	if (!stack_a->next)
		return (-1);
	if (i > len / 2)
		return (i - len);
	return (i);
}
