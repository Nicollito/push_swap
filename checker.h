/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:32:33 by nimadela          #+#    #+#             */
/*   Updated: 2025/02/07 16:17:14 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"
# include "get_next_line.h"

// checker.c
void	read_and_exec_instr(t_list **stack);

// exec_instr.c
void	exec_instr(t_list **stack, char *instr);
void	exec_swap(t_list **stack, char *instr);
void	exec_push(t_list **stack, char *instr);
void	exec_rotate(t_list **stack, char *instr);
void	exec_reverse_rotate(t_list **stack, char *instr);

#endif