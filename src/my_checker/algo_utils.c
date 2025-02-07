/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:22:59 by nimadela          #+#    #+#             */
/*   Updated: 2025/02/07 15:17:57 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	check_sort(t_list *stack)
{
	t_list	*next;

	next = stack->next;
	while (next)
	{
		if (stack->content > next->content)
			return (0);
		stack = next;
		next = next->next;
	}
	return (1);
}

t_list	*found_min(t_list *stack)
{
	t_list	*min;

	min = stack;
	while (stack)
	{
		stack = stack->next;
		if (stack && min->content > stack->content)
			min = stack;
	}
	return (min);
}

t_list	*found_max(t_list *stack)
{
	t_list	*max;

	max = stack;
	while (stack)
	{
		stack = stack->next;
		if (stack && max->content < stack->content)
			max = stack;
	}
	return (max);
}

int	found_worth(t_list	*stack, t_list *to_move)
{
	int	len;
	int	place;

	len = stack_len(stack);
	place = 0;
	while (stack != to_move)
	{
		stack = stack->next;
		place++;
	}
	if (place > len / 2)
		return (1);
	return (0);
}

void	switch_to_b(t_list **stack)
{
	t_list	*min;

	min = found_min(stack[0]);
	if (found_worth(stack[0], min))
	{
		while (stack[0] != min)
			write(1, reverse_rotate(stack, 'a'), 4);
	}
	else
	{
		while (stack[0] != min)
			write(1, rotate(stack, 'a'), 3);
	}
	write(1, push(stack, 'b'), 3);
}
