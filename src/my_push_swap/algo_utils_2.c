/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:06:06 by nimadela          #+#    #+#             */
/*   Updated: 2025/02/07 15:19:02 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

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
	int	res;
	int	len;

	i = 0;
	res = 0;
	len = stack_len(stack_a);
	if (stack_b->content < found_min(stack_a)->content)
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
	if (!stack_a->next && !res)
		return (-1);
	if (res > len / 2)
		return (res - len);
	return (res);
}

void	push_max_b_to_a(t_list **stack, t_list *stack_b)
{
	int		i;
	int		len;

	i = 0;
	while (stack_b != found_max(stack[1]) && ++i)
		stack_b = stack_b->next;
	len = stack_len(stack[1]);
	if (i > len / 2)
		i = i - len;
	while (i != 0)
	{
		if (i <= 0)
		{
			write(1, reverse_rotate(stack, 'b'), 4);
			i++;
		}
		else if (i >= 0)
		{
			write(1, rotate(stack, 'b'), 3);
			i--;
		}
	}
	write(1, push(stack, 'a'), 3);
	write(1, rotate(stack, 'a'), 3);
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
