/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:06:55 by nimadela          #+#    #+#             */
/*   Updated: 2025/01/23 10:01:15 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack_node
{
	int					number;
	struct s_stack_node	*next;
}	t_stack;

char	*swap(t_stack **stack, char which);
char	*ss(t_stack **stack);
char	*push(t_stack **stack, char which);
char	*rotate(t_stack **stack, char which);
char	*rr(t_stack **stack);
char	*reverse_rotate(t_stack **stack, char which);
char	*rrr(t_stack **stack);
char	*fill_str(int ac, char **av, char *str);
int		*fill_digit_array(char *str, int *digit_array, int len);
int		count_number(char *str);
void	init_stack(t_stack **stack, int number, int which);
t_stack	*create_node(int number);
void	fill_stack(t_stack **stack, int *digit_array, int len);
t_stack	**create_and_fill_stack(t_stack **stack, int ac, char **av);

#endif