/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_instr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:42:18 by nimadela          #+#    #+#             */
/*   Updated: 2025/02/07 15:18:16 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../checker.h"

void	exec_instr(t_list **stack, char *instr)
{
	if (ft_strlen(instr) == 4)
		exec_reverse_rotate(stack, instr);
	else if (ft_strlen(instr) == 3)
	{
		if (instr[0] == 's')
			exec_swap(stack, instr);
		if (instr[0] == 'p')
			exec_push(stack, instr);
		if (instr[0] == 'r')
			exec_rotate(stack, instr);
	}
}

void	exec_swap(t_list **stack, char *instr)
{
	if (ft_strlen(instr) != 3)
		return ;
	if (instr[1] == 'a')
		swap(stack, 'a');
	if (instr[1] == 'b')
		swap(stack, 'b');
	if (instr[1] == 's')
		ss(stack);
}

void	exec_push(t_list **stack, char *instr)
{
	if (ft_strlen(instr) != 3)
		return ;
	if (instr[1] == 'a')
		push(stack, 'a');
	if (instr[1] == 'b')
		push(stack, 'b');
}

void	exec_rotate(t_list **stack, char *instr)
{
	if (ft_strlen(instr) != 3)
		return ;
	if (instr[1] == 'a')
		rotate(stack, 'a');
	if (instr[1] == 'b')
		rotate(stack, 'b');
	if (instr[1] == 'r')
		rr(stack);
}

void	exec_reverse_rotate(t_list **stack, char *instr)
{
	if (ft_strlen(instr) != 4)
		return ;
	if (instr[1] != 'r')
		return ;
	if (instr[2] == 'a')
		reverse_rotate(stack, 'a');
	if (instr[2] == 'b')
		reverse_rotate(stack, 'b');
	if (instr[2] == 'r')
		rrr(stack);
}
