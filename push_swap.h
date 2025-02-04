/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:06:55 by nimadela          #+#    #+#             */
/*   Updated: 2025/02/04 13:46:54 by nimadela         ###   ########.fr       */
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

char	*swap(t_list **stack, char which);
char	*ss(t_list **stack);
char	*push(t_list **stack, char which);
char	*rotate(t_list **stack, char which);
char	*rr(t_list **stack);
char	*reverse_rotate(t_list **stack, char which);
char	*rrr(t_list **stack);
char	*fill_str(int ac, char **av, char *str);
int		*fill_digit_array(char *str, int *digit_array, int len);
int		count_number(char *str);
t_list	*create_node(int number);
void	fill_stack(t_list **stack, int *digit_array, int len);
t_list	**create_and_fill_stack(t_list **stack, int ac, char **av);
int		check_sort(t_list *stack);
void	sort_3_nbr(t_list **stack);
void	sort_4_and_5(t_list **stack);
int		stack_len(t_list *stack);
int		free_stack(t_list **stack);
t_list	*found_min(t_list *stack);
t_list	*found_max(t_list *stack);
int		found_worth(t_list	*stack, t_list *to_move);
void	switch_to_b(t_list **stack);
int		check_sort(t_list *stack);
int		check_if_isdigit(char *str);
void	same_in_digit(int *digit_array, int len);
void	calc_stat(t_stat *stat, t_list *stack);
void	sort_to_a(t_list **stack);
void	sort_to_b(t_list **stack, t_stat *stat);
int		verif_quart(t_stat *stat, t_list *stack);
void	big_sort(t_list **stack);
int		count_rotate_a(t_list *stack_a, t_list *stack_b);
void	push_max_b_to_a(t_list **stack);
int		found_node_place(t_list *stack, t_list *to_find);
void	set_a(t_list **stack);
int		opti_rotate(t_list *stack_a, t_list *stack_b);
void	set_rot(t_list **stack, t_list *stack_b);
void	fill_ra(t_list **stack, t_list *stack_b);
void	fill_rb(t_list **stack, t_list *stack_b);
void	fill_rra(t_list **stack, t_list *stack_b);
void	fill_rrb(t_list **stack, t_list *stack_b);
t_list	*node_to_push(t_list **stack);
void	set_b_to_push(t_list **stack, t_list *to_push);
void	push_to_a(t_list **stack);

#endif