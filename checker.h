/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:32:33 by nimadela          #+#    #+#             */
/*   Updated: 2025/02/07 10:53:26 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"
# include "get_next_line.h"

void	read_and_exec_instr(t_list **stack);
void	exec_instr(t_list **stack, char *instr);
void	exec_swap(t_list **stack, char *instr);
void	exec_push(t_list **stack, char *instr);
void	exec_rotate(t_list **stack, char *instr);
void	exec_reverse_rotate(t_list **stack, char *instr);

#endif