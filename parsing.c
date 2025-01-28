/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:08:48 by nimadela          #+#    #+#             */
/*   Updated: 2025/01/28 11:13:01 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_isdigit(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] != ' ' && str[i] <= 11 && str[i] >= 0 && str[i] != '-'
			&& str[i] != '+' && !ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	same_in_digit(int *digit_array, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (len > i)
	{
		j = i + 1;
		while (len > j)
		{
			if (digit_array[i] == digit_array[j])
			{
				write(2, "Error\n", 6);
				free(digit_array);
				exit(1);
			}
			j++;
		}
		i++;
	}
}
