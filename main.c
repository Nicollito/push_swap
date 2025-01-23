/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:38:06 by nimadela          #+#    #+#             */
/*   Updated: 2025/01/23 10:04:07 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "tmp.h"

t_stack	**create_and_fill_stack(t_stack **stack, int ac, char **av)
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
	stack = malloc(sizeof(t_stack) * 2);
	if (!stack)
		return (NULL);
	fill_stack(stack, digit_array, len);
	return (stack);
}

int	main(int ac, char **av)
{
	t_stack	**stack;

	stack = NULL;
	stack = create_and_fill_stack(stack, ac, av);
	print_stack(stack[0]);
	return (1);
}
