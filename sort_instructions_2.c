/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_instructions_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:42:14 by nimadela          #+#    #+#             */
/*   Updated: 2025/01/21 14:25:21 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*rotate(s_stack **stack, char which)
{
	s_stack	*start;
	s_stack	*last;
	s_stack	*current;

	current = stack[0];
	if (which == 'b')
		current = stack[1];
	start = current->next;
	last = current;
	while (current->next)
		current = current->next;
	current->next = last;
	last->next = NULL;
	if (which == 'a')
	{
		stack[0] = start;
		return("ra\n");
	}
	stack[1] = start;
	return ("rb\n");
}

char	*rr(s_stack **stack)
{
	rotate(stack, 'a');
	rotate(stack, 'b');
	return ("rr\n");
}

char	*reverse_rotate(s_stack **stack, char which)
{
	s_stack	*start;
	s_stack	*current;
	s_stack	*s_next;

	current = stack[0];
	if (which == 'b')
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
	stack[1] = s_next;
	return ("rrb\n");
}

char	*rrr(s_stack **stack)
{
	reverse_rotate(stack, 'a');
	reverse_rotate(stack, 'b');
	return ("rrr\n");
}
