/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:35:05 by nimadela          #+#    #+#             */
/*   Updated: 2025/02/07 15:19:06 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	set_rot(t_list **stack, t_list *stack_b)
{
	while (stack_b)
	{
		fill_ra(stack, stack_b);
		fill_rb(stack, stack_b);
		fill_rra(stack, stack_b);
		fill_rrb(stack, stack_b);
		stack_b = stack_b ->next;
	}
}

void	fill_ra(t_list **stack, t_list *stack_b)
{
	int	nb_rot;

	nb_rot = count_rotate_a(stack[0], stack_b);
	if (nb_rot < 0)
		stack_b->rot.ra = -1;
	else
		stack_b->rot.ra = nb_rot;
}

void	fill_rb(t_list **stack, t_list *stack_b)
{
	int	nb_rot;
	int	len;

	nb_rot = found_node_place(stack[1], stack_b);
	len = stack_len(stack[1]);
	if (nb_rot > len / 2)
		stack_b->rot.rb = -1;
	else
		stack_b->rot.rb = nb_rot;
}

void	fill_rra(t_list **stack, t_list *stack_b)
{
	int	nb_rot;

	nb_rot = count_rotate_a(stack[0], stack_b);
	if (nb_rot < 0)
		stack_b->rot.rra = nb_rot * -1;
	else
		stack_b->rot.rra = -1;
}

void	fill_rrb(t_list **stack, t_list *stack_b)
{
	int	nb_rot;
	int	len;

	nb_rot = found_node_place(stack[1], stack_b);
	len = stack_len(stack[1]);
	if (nb_rot > len / 2)
		stack_b->rot.rrb = len - nb_rot;
	else
		stack_b->rot.rrb = -1;
}
