/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:37:51 by nimadela          #+#    #+#             */
/*   Updated: 2025/01/28 15:22:19 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "tmp.h"

int	main(int ac, char **av)
{
	t_list	**stack;
	t_stat	*stat;

	stack = NULL;
	stack = create_and_fill_stack(stack, ac, av);
	if (stack_len(stack[0]) == 2 && !check_sort(stack[0]))
		write(1, swap(stack, 'a'), 3);
	if ((stack_len(stack[0]) <= 5 && stack_len(stack[0]) >= 3)
		&& !check_sort(stack[0]))
		sort_4_and_5(stack);
	stat = malloc(sizeof(t_stat));
	while (stack_len(stack[0]) > 3)
	{
		calc_stat(stat, stack[0]);
		sort_to_b(stack, stat);
	}
	printf("stack a :\n");
	print_stack(stack[0]);
	printf("\nstack b :\n");
	print_stack(stack[1]);
	free(stat);
	free_stack(stack);
	return (1);
}
