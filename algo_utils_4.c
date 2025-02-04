/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:32:26 by nimadela          #+#    #+#             */
/*   Updated: 2025/02/04 12:55:57 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*node_to_push(t_list **stack)
{
	t_list	*current;
	t_list	*to_push;
	int		cmp;
	int		tmp;

	current = stack[1];
	cmp = -1;
	while (current)
	{
		if (current->rot.rra < 0 && current->rot.rrb < 0)
			tmp = current->rot.ra + current->rot.rb;
		else if (current->rot.rra < 0 && current->rot.rb < 0)
			tmp = current->rot.ra + current->rot.rrb;
		else if (current->rot.ra < 0 && current->rot.rrb < 0)
			tmp = current->rot.rra + current->rot.rb;
		else if (current->rot.ra < 0 && current->rot.rb < 0)
			tmp = current->rot.rra + current->rot.rrb;
		if (tmp < cmp || cmp == -1)
		{
			cmp = tmp;
			to_push = current;
		}
		current = current->next;
	}
	return (to_push);
}
