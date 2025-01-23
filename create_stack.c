/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:46:26 by nimadela          #+#    #+#             */
/*   Updated: 2025/01/23 10:05:02 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack **stack, int number, int which)
{
	t_stack	*node;

	node = create_node(number);
	node->next = stack[which];
	stack[which] = node;
}

t_stack	*create_node(int number)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->number = number;
	node->next = NULL;
	return (node);
}

void	fill_stack(t_stack **stack, int *digit_array, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		init_stack(stack, digit_array[i], 0);
		i++;
	}
}
