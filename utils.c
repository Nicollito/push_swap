/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:40:09 by nimadela          #+#    #+#             */
/*   Updated: 2025/01/23 09:59:17 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "tmp.h"

void	print_int_tab(int *tab, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		printf("%i\n", tab[i]);
		i++;
	}
}

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("%i ", stack->number);
		stack = stack->next;
	}
}
