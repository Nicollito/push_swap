/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_instructions_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:42:14 by nimadela          #+#    #+#             */
/*   Updated: 2025/02/07 15:18:37 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

char	*rotate(t_list **stack, char which)
{
	t_list	*start;
	t_list	*last;
	t_list	*current;

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
		return ("ra\n");
	}
	stack[1] = start;
	return ("rb\n");
}

char	*rr(t_list **stack)
{
	rotate(stack, 'a');
	rotate(stack, 'b');
	return ("rr\n");
}

char	*reverse_rotate(t_list **stack, char which)
{
	t_list	*start;
	t_list	*current;
	t_list	*s_next;

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
		return ("rra\n");
	}
	stack[1] = s_next;
	return ("rrb\n");
}

char	*rrr(t_list **stack)
{
	reverse_rotate(stack, 'a');
	reverse_rotate(stack, 'b');
	return ("rrr\n");
}
