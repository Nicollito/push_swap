/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:31:35 by nimadela          #+#    #+#             */
/*   Updated: 2025/02/07 15:18:42 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

char	*swap(t_list **stack, char which)
{
	int		tmp;
	t_list	*current;
	t_list	*next;

	current = stack[0];
	if (which == 'b')
		current = stack[1];
	next = current->next;
	tmp = current->content;
	current->content = next->content;
	next->content = tmp;
	if (which == 'b')
		return ("sb\n");
	return ("sa\n");
}

char	*ss(t_list **stack)
{
	swap(stack, 'a');
	swap(stack, 'b');
	return ("ss\n");
}

char	*push(t_list **stack, char which)
{
	t_list	*src;
	t_list	*dest;
	t_list	*tmp;

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
