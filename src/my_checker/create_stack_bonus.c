/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:46:26 by nimadela          #+#    #+#             */
/*   Updated: 2025/02/11 10:04:05 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../checker_bonus.h"

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
	int		i;
	t_list	*node;

	i = 0;
	while (i < len)
	{
		node = create_node(digit_array[i]);
		if (!node)
			exit(free_all(NULL, digit_array, stack, NULL));
		ft_lstadd_back(stack, node, 0);
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
	len = count_number(str);
	digit_array = fill_digit_array(str, digit_array, len);
	free(str);
	same_in_digit(digit_array, len);
	stack = malloc(sizeof(t_list) * 2);
	if (!stack)
		exit(free_all(NULL, digit_array, NULL, NULL));
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
