/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 09:44:04 by nimadela          #+#    #+#             */
/*   Updated: 2025/02/07 15:19:28 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_to_b(t_list **stack, t_stat *stat)
{
	if (stack[0]->content >= stat->quart1 && stack[0]->content < stat->mean)
	{
		write(1, push(stack, 'b'), 3);
		if (stack[1]->next)
			write(1, rotate(stack, 'b'), 3);
	}
	else if (stack[0]->content >= stat->mean
		&& stack[0]->content <= stat->quart3)
		write(1, push(stack, 'b'), 3);
	else
		write(1, rotate(stack, 'a'), 3);
	if (!verif_quart(stat, stack[0]))
	{
		if (stack[0]->content < stat->quart1)
		{
			write(1, push(stack, 'b'), 3);
			write(1, rotate(stack, 'b'), 3);
		}
		else
			write(1, push(stack, 'b'), 3);
	}
}

void	sort_to_a(t_list **stack)
{
	t_list	*to_push;

	if (found_max(stack[0])->content < found_max(stack[1])->content)
		push_max_b_to_a(stack, stack[1]);
	set_rot(stack, stack[1]);
	to_push = node_to_push(stack[1]);
	all_rr_and_rrr_actions(stack, to_push);
	set_b_to_push(stack, to_push);
	push_to_a(stack);
	write(1, push(stack, 'a'), 3);
}

void	push_to_a(t_list **stack)
{
	int	nb_rot;
	int	reverse;

	reverse = 0;
	nb_rot = 0;
	if (stack[1]->rot.rra == -1)
		nb_rot = stack[1]->rot.ra;
	else if (stack[1]->rot.ra == -1)
	{
		reverse = -1;
		nb_rot = stack[1]->rot.rra;
	}
	while (nb_rot)
	{
		if (!reverse)
			write(1, rotate(stack, 'a'), 3);
		else
			write(1, reverse_rotate(stack, 'a'), 4);
		nb_rot--;
	}
}

void	set_b_to_push(t_list **stack, t_list *to_push)
{
	int	nb_rot;
	int	reverse;

	reverse = 0;
	nb_rot = 0;
	if (to_push->rot.rrb == -1)
		nb_rot = to_push->rot.rb;
	else if (to_push->rot.rb == -1)
	{
		nb_rot = to_push->rot.rrb;
		reverse = -1;
	}
	while (nb_rot)
	{
		if (!reverse)
			write(1, rotate(stack, 'b'), 3);
		else
			write(1, reverse_rotate(stack, 'b'), 4);
		nb_rot--;
	}
}

void	set_a(t_list **stack)
{
	int		i;
	int		place_max;
	int		len_a;
	t_list	*max_a;

	i = 0;
	len_a = stack_len(stack[0]);
	max_a = found_max(stack[0]);
	place_max = found_node_place(stack[0], max_a);
	if (place_max > len_a / 2)
		place_max -= len_a;
	while (place_max != 0)
	{
		if (place_max > 0)
		{
			write(1, rotate(stack, 'a'), 3);
			place_max--;
		}
		else
		{
			write(1, reverse_rotate(stack, 'a'), 4);
			place_max++;
		}
	}
	write(1, rotate(stack, 'a'), 3);
}
