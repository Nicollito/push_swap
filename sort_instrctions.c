/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_instrctions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:31:35 by nimadela          #+#    #+#             */
/*   Updated: 2025/01/20 10:31:08 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*swap_a(s_stack *stack_a)
{
	int		tmp;
	s_stack	*next;

	if (!stack_a || !stack_a->next)
		return (NULL);
	next = stack_a->next;
	tmp = stack_a->number;
	stack_a->number = next->number;
	next->number = tmp;
	return ("sa\n");
}

char	*swap_b(s_stack *stack_b)
{
	int		tmp;
	s_stack	*next;

	if (!stack_b || !stack_b->next)
		return (NULL);
	next = stack_b->next;
	tmp = stack_b->number;
	stack_b->number = next->number;
	next->number = tmp;
	return ("sb\n");
}

char	*ss(s_stack **stack)
{
	swap_a(stack[0]);
	swap_b(stack[1]);
	return ("ss\n");
}

char	*push_a(s_stack **stack)
{
	s_stack	*new;
	s_stack	*old;

	if (!stack[1])
		return (NULL);
	old = stack[1];
	stack[1] = stack[1]->next;
	new->number = old->number;
	free(old);
	new->next = stack[0];
	return ("pa\n");
}

char	*push_b(s_stack **stack)
{
	s_stack	*new;
	s_stack	*old;

	if (!stack[0])
		return (NULL);
	old = stack[0];
	stack[0] = stack[0]->next;
	new->number = old->number;
	free(old);
	new->next = stack[1];
	return ("pb\n");
}
