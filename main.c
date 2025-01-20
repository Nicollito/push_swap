/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:13:07 by nimadela          #+#    #+#             */
/*   Updated: 2025/01/20 15:59:48 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

s_stack	*create_node(int number)
{
	s_stack	*node;

	node = malloc(sizeof(s_stack));
	node->number = number;
	node->next = NULL;
	return(node);
}

s_stack	*fill_stack(s_stack *stack, int	number)
{
	s_stack *node = create_node(number);
	node->next = stack;
	stack = node;
	return(stack);
}

int	main()
{
	
}
 