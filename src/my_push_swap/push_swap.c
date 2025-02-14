/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:37:51 by nimadela          #+#    #+#             */
/*   Updated: 2025/02/14 11:26:16 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	main(int ac, char **av)
{
	t_list	**stack;

	stack = NULL;
	if (ac == 1)
		return (0);
	stack = create_and_fill_stack(stack, ac, av);
	if (stack_len(stack[0]) == 2 && !check_sort(stack[0]))
		print_instr(swap(stack, 'a'));
	if ((stack_len(stack[0]) <= 5 && stack_len(stack[0]) >= 3)
		&& !check_sort(stack[0]))
		sort_4_and_5(stack);
	if (stack_len(stack[0]) > 5 && !check_sort(stack[0]))
		big_sort(stack);
	free_stack(stack);
	return (1);
}

void	big_sort(t_list **stack)
{
	t_stat	*stat;

	stat = malloc(sizeof(t_stat));
	if (!stat)
		exit(free_stack(stack));
	calc_stat(stat, stack[0]);
	while (stack_len(stack[0]) > 3)
		sort_to_b(stack, stat);
	free(stat);
	if (stack_len(stack[0]) == 3 && !check_sort(stack[0]))
		sort_3_nbr(stack);
	while (stack[1])
		sort_to_a(stack);
	set_a(stack);
}
