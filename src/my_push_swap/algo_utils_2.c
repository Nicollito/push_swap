/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:06:06 by nimadela          #+#    #+#             */
/*   Updated: 2025/02/14 11:36:47 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	calc_stat(t_stat *stat, t_list *stack)
{
	int	max;
	int	min;
	int	diff;

	max = found_max(stack)->content;
	min = found_min(stack)->content;
	diff = max - min;
	stat->mean = min + (diff / 2);
	stat->quart1 = min + (diff / 4);
	stat->quart3 = min +((3 * diff) / 4);
	while (stack)
	{
		if (stack->content < stat->quart1)
			stack->sort = 1;
		if (stack->content >= stat->quart1 && stack->content < stat->mean)
			stack->sort = 2;
		if (stack->content >= stat->mean && stack->content < stat->quart3)
			stack->sort = 3;
		if (stack->content >= stat->quart3)
			stack->sort = 4;
		stack = stack->next;
	}
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
	int	res;
	int	len;

	i = 0;
	res = 0;
	len = stack_len(stack_a);
	if (stack_b->content < found_min(stack_a)->content
		|| stack_b->content > found_max(stack_a)->content)
		res = found_node_place(stack_a, found_max(stack_a)) + 1;
	if (stack_b->content < stack_a->content
		&& stack_b->content > ft_lstlast(stack_a)->content)
		return (0);
	while (stack_a->next && !res)
	{
		i++;
		if (stack_b->content > stack_a->content
			&& stack_b->content < (stack_a->next)->content)
			res = i;
		stack_a = stack_a->next;
	}
	if (res > len / 2)
		return (res - len);
	return (res);
}

int	found_node_place(t_list *stack, t_list *to_find)
{
	int	i;

	i = 0;
	while (stack != to_find)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
