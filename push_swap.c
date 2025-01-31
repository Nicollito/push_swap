/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:37:51 by nimadela          #+#    #+#             */
/*   Updated: 2025/01/31 15:23:53 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "tmp.h"

int	main(int ac, char **av)
{
	t_list	**stack;

	stack = NULL;
	stack = create_and_fill_stack(stack, ac, av);
	if (stack_len(stack[0]) == 2 && !check_sort(stack[0]))
		write(1, swap(stack, 'a'), 3);
	if ((stack_len(stack[0]) <= 5 && stack_len(stack[0]) >= 3)
		&& !check_sort(stack[0]))
		sort_4_and_5(stack);
	big_sort(stack);
	free_stack(stack);
	return (1);
}

void	big_sort(t_list **stack)
{
	t_stat	*stat;

	stat = malloc(sizeof(t_stat));
	if (!stat)
	{
		free_stack(stack);
		exit(1);
	}
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
