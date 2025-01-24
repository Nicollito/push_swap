/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:22:59 by nimadela          #+#    #+#             */
/*   Updated: 2025/01/24 18:52:51 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (stack && min->content < stack->content)
			min = stack;
	}
	return (min);
}

int	found_worth(t_list	*stack, t_list *min)
{
	int	len;
	int	min_place;

	len = stack_len(stack);
	min_place = 0;
	while (stack != min)
	{
		stack = stack->next;
		min_place++;
	}
	if (min_place > len / 2)
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
