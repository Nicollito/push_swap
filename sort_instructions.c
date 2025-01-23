/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:31:35 by nimadela          #+#    #+#             */
/*   Updated: 2025/01/23 10:02:57 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*swap(t_stack **stack, char which)
{
	int		tmp;
	t_stack	*current;
	t_stack	*next;

	current = stack[0];
	if (which == 'b')
		current = stack[1];
	next = current->next;
	tmp = current->number;
	current->number = next->number;
	next->number = tmp;
	if (which == 'b')
		return ("sb");
	return ("sa\n");
}

char	*ss(t_stack **stack)
{
	swap(stack, 'a');
	swap(stack, 'b');
	return ("ss\n");
}

char	*push(t_stack **stack, char which)
{
	t_stack	*src;
	t_stack	*dest;
	t_stack	*tmp;

	src = stack[0];
	dest = stack[1];
	if (which == 'b')
	{
		src = stack[1];
		dest = stack[0];
	}
	if (!dest)
		return (NULL);
	tmp = dest;
	dest = dest->next;
	tmp->next = src;
	if (which == 'a')
	{
		stack[0] = tmp;
		stack[1] = dest;
		return ("pa\n");
	}
	stack[1] = tmp;
	stack[0] = dest;
	return ("pb\n");
}
