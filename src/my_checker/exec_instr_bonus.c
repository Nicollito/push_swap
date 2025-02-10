/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_instr_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:42:18 by nimadela          #+#    #+#             */
/*   Updated: 2025/02/10 12:43:24 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../checker_bonus.h"

void	exec_instr(t_list **stack, char *instr)
{
	if (ft_strlen(instr) == 4 && instr[0] == 'r' && instr[1] == 'r')
		exec_reverse_rotate(stack, instr);
	else if (ft_strlen(instr) == 3)
	{
		if (instr[0] == 's')
			exec_swap(stack, instr);
		else if (instr[0] == 'p')
			exec_push(stack, instr);
		else if (instr[0] == 'r')
			exec_rotate(stack, instr);
		else
		{
			write(2, "Error\n", 6);
			exit(free_all(instr, NULL, stack, NULL));
		}
	}
	else
	{
		write(2, "Error\n", 6);
		exit(free_all(instr, NULL, stack, NULL));
	}
}

void	exec_swap(t_list **stack, char *instr)
{
	if (ft_strlen(instr) != 3)
		return ;
	else if (instr[1] == 'a')
		swap(stack, 'a');
	else if (instr[1] == 'b')
		swap(stack, 'b');
	else if (instr[1] == 's')
		ss(stack);
	else
	{
		write(2, "Error\n", 6);
		exit(free_all(instr, NULL, stack, NULL));
	}
}

void	exec_push(t_list **stack, char *instr)
{
	if (ft_strlen(instr) != 3)
		return ;
	else if (instr[1] == 'a')
		push(stack, 'a');
	else if (instr[1] == 'b')
		push(stack, 'b');
	else
	{
		write(2, "Error\n", 6);
		exit(free_all(instr, NULL, stack, NULL));
	}
}

void	exec_rotate(t_list **stack, char *instr)
{
	if (ft_strlen(instr) != 3)
		return ;
	else if (instr[1] == 'a')
		rotate(stack, 'a');
	else if (instr[1] == 'b')
		rotate(stack, 'b');
	else if (instr[1] == 'r')
		rr(stack);
	else
	{
		write(2, "Error\n", 6);
		exit(free_all(instr, NULL, stack, NULL));
	}
}

void	exec_reverse_rotate(t_list **stack, char *instr)
{
	if (ft_strlen(instr) != 4)
		return ;
	else if (instr[2] == 'a')
		reverse_rotate(stack, 'a');
	else if (instr[2] == 'b')
		reverse_rotate(stack, 'b');
	else if (instr[2] == 'r')
		rrr(stack);
	else
	{
		write(2, "Error\n", 6);
		exit(free_all(instr, NULL, stack, NULL));
	}
}
