/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:06:55 by nimadela          #+#    #+#             */
/*   Updated: 2025/01/21 15:13:12 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack_node
{
	int				number;
	struct s_stack_node	*next;
}	s_stack;

# include "libft/libft.h"

char	*swap(s_stack **stack, char which);
char	*ss(s_stack **stack);
char	*push(s_stack **stack, char which);
char	*rotate(s_stack **stack, char which);
char	*rr(s_stack **stack);
char	*reverse_rotate(s_stack **stack, char which);
char	*rrr(s_stack **stack);

#endif