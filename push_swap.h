/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:06:55 by nimadela          #+#    #+#             */
/*   Updated: 2025/01/27 10:22:08 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

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
void	free_stack(t_list **stack);
t_list	*found_min(t_list *stack);
int		found_worth(t_list	*stack, t_list *min);
void	switch_to_b(t_list **stack);
int		check_sort(t_list *stack);
int		check_if_isdigit(char *str);

#endif