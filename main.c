/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:38:06 by nimadela          #+#    #+#             */
/*   Updated: 2025/01/23 17:46:57 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "tmp.h"

int	main(int ac, char **av)
{
	t_list	**stack;

	stack = NULL;
	stack = create_and_fill_stack(stack, ac, av);
	print_stack(stack[0]);
	printf("%i", check_sort_a(stack));
	return (1);
}
