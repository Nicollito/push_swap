/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:14:42 by nimadela          #+#    #+#             */
/*   Updated: 2025/02/05 10:53:09 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_stack(t_list **stack)
{
	t_list	*stack_to_free;

	while (stack[1])
	{
		push(stack, 'a');
	}
	while (stack[0])
	{
		stack_to_free = stack[0];
		stack[0] = stack[0]->next;
		free(stack_to_free);
	}
	free(stack);
	return (1);
}

int	free_all(char *str, int *digit_array, t_list **stack, t_list *node)
{
	if (str)
		free(str);
	if (digit_array)
		free(digit_array);
	if (stack)
		free_stack(stack);
	if (node)
		free(node);
	return (1);
}
