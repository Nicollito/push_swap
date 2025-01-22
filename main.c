/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:38:06 by nimadela          #+#    #+#             */
/*   Updated: 2025/01/22 17:26:03 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "tmp.h"

int	main(int ac, char **av)
{
	int		len;
	int		*digit_array;
	char	*str;
	s_stack	**stack;

	digit_array = NULL;
	str = NULL;
	str = fill_str(ac, av, str);
	if (!str)
		return (0);
	len = count_number(str);
	digit_array = fill_digit_array(str, digit_array, len);
	free(str);
	stack = malloc(sizeof(s_stack) * 2);
	if (!stack)
		return(0);
	fill_stack(stack, digit_array, len);
	print_stack(stack[0]);
	return (1);
}
