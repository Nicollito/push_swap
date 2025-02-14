/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 09:44:04 by nimadela          #+#    #+#             */
/*   Updated: 2025/02/14 12:59:03 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_to_b(t_list **stack, t_stat *stat)
{
	if (stack[0]->content >= stat->quart1 && stack[0]->content < stat->mean)
	{
		print_instr(push(stack, 'b'));
		if (stack[1]->next)
			print_instr(rotate(stack, 'b'));
	}
	else if (stack[0]->content >= stat->mean
		&& stack[0]->content <= stat->quart3)
		print_instr(push(stack, 'b'));
	else
		print_instr(rotate(stack, 'a'));
	if (!verif_quart(stat, stack[0]))
	{
		if (stack[0]->content < stat->quart1 && nbr_in_quart(stack[0], 1) > 3)
		{
			print_instr(push(stack, 'b'));
			print_instr(rotate(stack, 'b'));
		}
		else if (stack[0]->content > stat->quart3)
			print_instr(push(stack, 'b'));
	}
}

void	sort_to_a(t_list **stack)
{
	t_list	*to_push;

	set_rot(stack, stack[1]);
	to_push = node_to_push(stack[1]);
	all_rr_and_rrr_actions(stack, to_push);
	set_b_to_push(stack, to_push);
	push_to_a(stack);
	print_instr(push(stack, 'a'));
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
			print_instr(rotate(stack, 'a'));
		else
			print_instr(reverse_rotate(stack, 'a'));
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
			print_instr(rotate(stack, 'b'));
		else
			print_instr(reverse_rotate(stack, 'b'));
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
			print_instr(rotate(stack, 'a'));
			place_max--;
		}
		else
		{
			print_instr(reverse_rotate(stack, 'a'));
			place_max++;
		}
	}
	print_instr(rotate(stack, 'a'));
}
