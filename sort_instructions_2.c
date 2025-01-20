/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_instructions_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:42:14 by nimadela          #+#    #+#             */
/*   Updated: 2025/01/20 14:53:44 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*rotate(s_stack *stack, char which)
{
	s_stack	*last;

	last->number = stack->number;
	last->next = NULL;
	while (stack->next)
		stack = stack->next;
	stack->next = last;
	if (which == 'a')
		return("ra");
	return("rb");
}

char	*rr(s_stack **stack)
{
	rotate(stack[0], 'a');
	rotate(stack[1], 'b');
	return("rr");
}

char	*reverse_rotate(s_stack **stack, char which)
{
	s_stack	*start;
	s_stack	*current;
	s_stack	*s_next;

	if (which == 'a')
		current = stack[0];
	else if (which == 'b')
		current = stack[1];
	start = current;
	s_next = current->next;
	while (current->next && s_next->next)
	{
		current = current->next;
		s_next = s_next->next;
	}
	current->next = NULL;
	s_next->next = start;
	if (which == 'a')
	{
		stack[0] = s_next;
		return("rra");
	}
	else if (which == 'b')
	{
		stack[1] = s_next;
		return("rrb");
	}
}

/* char	*rrr(s_stack **stack)
{
	NTM
}
 */