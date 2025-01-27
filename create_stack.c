/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:46:26 by nimadela          #+#    #+#             */
/*   Updated: 2025/01/27 19:44:10 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_node(int number)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = number;
	node->next = NULL;
	return (node);
}

void	fill_stack(t_list **stack, int *digit_array, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_lstadd_back(stack, create_node(digit_array[i]), 0);
		i++;
	}
}

t_list	**create_and_fill_stack(t_list **stack, int ac, char **av)
{
	int		*digit_array;
	char	*str;
	int		len;

	digit_array = NULL;
	str = NULL;
	str = fill_str(ac, av, str);
	if (!str)
		return (NULL);
	len = count_number(str);
	digit_array = fill_digit_array(str, digit_array, len);
	free(str);
	same_in_digit(digit_array, len);
	stack = malloc(sizeof(t_list) * 2);
	stack[0] = NULL;
	stack[1] = NULL;
	if (!stack)
		return (NULL);
	fill_stack(stack, digit_array, len);
	free(digit_array);
	return (stack);
}

int	stack_len(t_list *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	free_stack(t_list **stack)
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
}
