/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:46:26 by nimadela          #+#    #+#             */
/*   Updated: 2025/01/22 17:24:55 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(s_stack **stack, int	number, int	which)
{
	s_stack *node;

	node = create_node(number);
	node->next = stack[which];
	stack[which] = node;
}

s_stack	*create_node(int number)
{
	s_stack	*node;

	node = malloc(sizeof(s_stack));
	if (!node)
		return (NULL);
	node->number = number;
	node->next = NULL;
	return (node);
}

void	fill_stack(s_stack **stack, int *digit_array, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		init_stack(stack, digit_array[i], 0);
		i++;
	}
}
