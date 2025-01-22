/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:06:55 by nimadela          #+#    #+#             */
/*   Updated: 2025/01/22 17:21:10 by nimadela         ###   ########.fr       */
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
char	*fill_str(int ac, char **av, char *str);
int		*fill_digit_array(char *str, int *digit_array, int len);
int		count_number(char *str);
void	init_stack(s_stack **stack, int	number, int	which);
s_stack	*create_node(int number);
void	fill_stack(s_stack **stack, int *digit_array, int len);

#endif