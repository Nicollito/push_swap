/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:37:51 by nimadela          #+#    #+#             */
/*   Updated: 2025/01/23 19:42:01 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort_a(t_list **stack)
{
	t_list	*next;

	next = stack[0]->next;
	while (next)
	{
		if (stack[0]->content > next->content)
			return (0);
		stack[0] = next;
		next = next->next;
	}
	return (1);
}

void	sort_3_nbr(t_list **stack)
{
	
}
