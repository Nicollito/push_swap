/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:13:07 by nimadela          #+#    #+#             */
/*   Updated: 2025/01/21 19:58:21 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

s_stack	*create_node(int number)
{
	s_stack	*node;

	node = malloc(sizeof(s_stack));
	node->number = number;
	node->next = NULL;
	return(node);
}

void	fill_stack_0(s_stack **stack, int	number)
{
	s_stack *node = create_node(number);
	node->next = stack[0];
	stack[0] = node;
}
void	fill_stack_1(s_stack **stack, int	number)
{
	s_stack *node = create_node(number);
	node->next = stack[1];
	stack[1] = node;
}

void	print_stack(s_stack *stack)
{
	while (stack)
	{
		printf("%i ", stack->number);
		stack = stack->next;
	}
}

int	main()
{
	s_stack	**main_stack;
	int		i;

	main_stack = malloc(sizeof(s_stack) * 2);
	i = 0;
	while (i < 10)
	{
		fill_stack_0(main_stack, i);
		i++;
	}
	while (i< 20)
	{
		fill_stack_1(main_stack, i);
		i++;
	}

	printf("Before :\n\n");

	printf("stack a:\n	");
	print_stack(main_stack[0]);
	printf("\n");

	printf("stack b:\n	");
	print_stack(main_stack[1]);
	printf("\n\n");

	ss(main_stack);

	printf("After :\n\n");

	printf("stack a:\n	");
	print_stack(main_stack[0]);
	printf("\n");

	printf("stack b:\n	");
	print_stack(main_stack[1]);
	printf("\n");

	return (0);
}
 