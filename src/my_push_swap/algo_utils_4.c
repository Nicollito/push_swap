/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:32:26 by nimadela          #+#    #+#             */
/*   Updated: 2025/02/07 15:19:10 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_list	*node_to_push(t_list *stack_b)
{
	t_list	*to_push;
	int		cmp;
	int		tmp;

	cmp = -1;
	while (stack_b)
	{
		if (stack_b->rot.rra < 0 && stack_b->rot.rrb < 0)
			tmp = stack_b->rot.ra + stack_b->rot.rb;
		else if (stack_b->rot.rra < 0 && stack_b->rot.rb < 0)
			tmp = stack_b->rot.ra + stack_b->rot.rrb;
		else if (stack_b->rot.ra < 0 && stack_b->rot.rrb < 0)
			tmp = stack_b->rot.rra + stack_b->rot.rb;
		else if (stack_b->rot.ra < 0 && stack_b->rot.rb < 0)
			tmp = stack_b->rot.rra + stack_b->rot.rrb;
		if (tmp < cmp || cmp == -1)
		{
			cmp = tmp;
			to_push = stack_b;
		}
		stack_b = stack_b->next;
	}
	return (to_push);
}

void	all_rr_and_rrr_actions(t_list **stack, t_list *to_push)
{
	if (to_push->rot.ra != -1 && to_push->rot.rb != -1)
	{
		while (to_push->rot.ra && to_push->rot.rb)
		{
			to_push->rot.ra--;
			to_push->rot.rb--;
			write(1, rr(stack), 3);
		}
	}
	else if (to_push->rot.rra != -1 && to_push->rot.rrb != -1)
	{
		while (to_push->rot.rra && to_push->rot.rrb)
		{
			to_push->rot.rra--;
			to_push->rot.rrb--;
			write(1, rrr(stack), 4);
		}
	}
}
