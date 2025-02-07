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
		write(1, reverse_rotate(stack, 'a'), 4);
		write(1, swap(stack, 'a'), 3);
	}
	else if (stack[0]->content < cmp2 || stack[0]->content < cmp3)
	{
		if (stack[0]->content < cmp2)
			write(1, reverse_rotate(stack, 'a'), 4);
		else
			write(1, swap(stack, 'a'), 3);
	}
	else if (cmp2 > cmp3)
	{
		write(1, rotate(stack, 'a'), 3);
		write(1, swap(stack, 'a'), 3);
	}
	else if (cmp2 < cmp3)
		write(1, rotate(stack, 'a'), 3);
}

void	sort_4_and_5(t_list **stack)
{
	if (stack_len(stack[0]) == 3)
		sort_3_nbr(stack);
	switch_to_b(stack);
	if (stack_len(stack[0]) == 4 && !check_sort(stack[0]))
		switch_to_b(stack);
	if (!check_sort(stack[0]))
		sort_3_nbr(stack);
	if (stack[1]->next && stack[1]->content < (stack[1]->next)->content)
		write(1, swap(stack, 'b'), 3);
	while (stack[1])
		write(1, push(stack, 'a'), 3);
}
