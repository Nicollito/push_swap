/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:46:26 by nimadela          #+#    #+#             */
/*   Updated: 2025/01/23 13:36:22 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_list **stack, int number, int which)
{
	// t_list	*node;

/* 	node = create_node(number);
	node->next = stack[which];
	stack[which] = node; */
	ft_lstadd_back(stack, create_node(number), which);
}

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
		init_stack(stack, digit_array[i], 0);
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
	stack = malloc(sizeof(t_list) * 2);
	stack[0] = NULL;
	stack[1] = NULL;
	if (!stack)
		return (NULL);
	fill_stack(stack, digit_array, len);
	free(digit_array);
	return (stack);
}
