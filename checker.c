/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:50:14 by nimadela          #+#    #+#             */
/*   Updated: 2025/02/07 11:22:05 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char **av)
{
	t_list	**stack;

	stack = NULL;
	if (ac == 1)
		return (0);
	stack = create_and_fill_stack(stack, ac, av);
	read_and_exec_instr(stack);
	if (!check_sort(stack[0]))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}

void	read_and_exec_instr(t_list **stack)
{
	char	*instr;

	instr = get_next_line(0);
	if (!instr)
		return ;
	while (instr)
	{
		exec_instr(stack, instr);
		free(instr);
		instr = get_next_line(0);
	}
}
