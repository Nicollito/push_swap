/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:38:06 by nimadela          #+#    #+#             */
/*   Updated: 2025/01/24 18:50:38 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "tmp.h"

int	main(int ac, char **av)
{
	t_list	**stack;

	stack = NULL;
	stack = create_and_fill_stack(stack, ac, av);
	if (stack_len(stack[0]) == 3 && !check_sort(stack[0]))
		sort_3_nbr(stack);
	if ((stack_len(stack[0]) == 5 || stack_len(stack[0]) == 4)
		&& !check_sort(stack[0]))
		sort_4_and_5(stack);
	free_stack(stack);
	return (1);
}
