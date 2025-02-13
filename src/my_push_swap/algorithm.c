/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:57:22 by nimadela          #+#    #+#             */
/*   Updated: 2025/01/27 16:57:49 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_3_nbr(t_list **stack)
{
	int	cmp2;
	int	cmp3;

	cmp2 = (stack[0]->next)->content;
	cmp3 = ((stack[0]->next)->next)->content;
	if (stack[0]->content < cmp2 && stack[0]->content < cmp3 && cmp3 < cmp2)
	{
		print_instr(reverse_rotate(stack, 'a'));
		print_instr(swap(stack, 'a'));
	}
	else if (stack[0]->content < cmp2 || stack[0]->content < cmp3)
	{
		if (stack[0]->content < cmp2)
			print_instr(reverse_rotate(stack, 'a'));
		else
			print_instr(swap(stack, 'a'));
	}
	else if (cmp2 > cmp3)
	{
		print_instr(rotate(stack, 'a'));
		print_instr(swap(stack, 'a'));
	}
	else if (cmp2 < cmp3)
		print_instr(rotate(stack, 'a'));
}

void	sort_4_and_5(t_list **stack)
{
	if (stack_len(stack[0]) == 3)
		sort_3_nbr(stack);
	else
		switch_to_b(stack);
	if (stack_len(stack[0]) == 4 && !check_sort(stack[0]))
		switch_to_b(stack);
	if (!check_sort(stack[0]))
		sort_3_nbr(stack);
	if (stack[1] && stack[1]->next && stack[1]->content < (stack[1]->next)->content)
		print_instr(swap(stack, 'b'));
	while (stack[1])
		print_instr(push(stack, 'a'));
}
