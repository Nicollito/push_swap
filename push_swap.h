/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:06:55 by nimadela          #+#    #+#             */
/*   Updated: 2025/02/07 16:12:29 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct descriptive_statistics
{
	int	mean;
	int	quart1;
	int	quart3;
}		t_stat;

// algo_utils.c
int		check_sort(t_list *stack);
t_list	*found_min(t_list *stack);
t_list	*found_max(t_list *stack);
int		found_worth(t_list	*stack, t_list *to_move);
void	switch_to_b(t_list **stack);

// algo_utils_2.c
void	calc_stat(t_stat *stat, t_list *stack);
int		verif_quart(t_stat *stat, t_list *stack);
int		count_rotate_a(t_list *stack_a, t_list *stack_b);
void	push_max_b_to_a(t_list **stack, t_list *stack_b);
int		found_node_place(t_list *stack, t_list *to_find);

// algo_utils_3.c
void	set_rot(t_list **stack, t_list *stack_b);
void	fill_ra(t_list **stack, t_list *stack_b);
void	fill_rb(t_list **stack, t_list *stack_b);
void	fill_rra(t_list **stack, t_list *stack_b);
void	fill_rrb(t_list **stack, t_list *stack_b);

// algo_utils_4.c
t_list	*node_to_push(t_list *stack_b);
void	all_rr_and_rrr_actions(t_list **stack, t_list *to_push);

// algorithm.c
void	sort_3_nbr(t_list **stack);
void	sort_4_and_5(t_list **stack);

// all_free.c
int		free_stack(t_list **stack);
int		free_all(char *str, int *digit_array, t_list **stack, t_list *node);

// big_algo.c
void	sort_to_b(t_list **stack, t_stat *stat);
void	sort_to_a(t_list **stack);
void	push_to_a(t_list **stack);
void	set_b_to_push(t_list **stack, t_list *to_push);
void	set_a(t_list **stack);

// create_stack.c
t_list	*create_node(int number);
void	fill_stack(t_list **stack, int *digit_array, int len);
t_list	**create_and_fill_stack(t_list **stack, int ac, char **av);
int		stack_len(t_list *stack);

// fill_digit_tab.c
int		count_number(char *str);
int		*fill_digit_array(char *str, int *digit_array, int len);
char	*fill_str(int ac, char **av, char *str);

// parsing.c
int		check_if_isdigit(char *str);
void	same_in_digit(int *digit_array, int len);

// push_swap.c
void	big_sort(t_list **stack);

// sort_instructions.c
char	*swap(t_list **stack, char which);
char	*ss(t_list **stack);
char	*push(t_list **stack, char which);

// sort_instructions_2.c
char	*rotate(t_list **stack, char which);
char	*rr(t_list **stack);
char	*reverse_rotate(t_list **stack, char which);
char	*rrr(t_list **stack);

#endif