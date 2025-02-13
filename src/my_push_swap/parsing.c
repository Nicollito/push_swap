/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:08:48 by nimadela          #+#    #+#             */
/*   Updated: 2025/02/13 14:02:25 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	check_if_isdigit(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] != ' ' && (str[i] >= 11 || str[i] <= 0) && str[i] != '-'
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

void	check_sign(char *str)
{
	int	i;

	i = 0;
	while (str[i + 1])
	{
		if ((str[i] == '-' || str[i] == '+') && (str[i + 1] == '-'
				|| str[i + 1] == '+' || !str[i + 1] || !ft_isdigit(str[i + 1])))
		{
			write(2, "Error\n", 6);
			exit(free_all(str, NULL, NULL, NULL));
		}
		if (i > 0 && str[i - 1] != ' ' && (str[i] == '-' || str[i] == '+'))
		{
			write(2, "Error\n", 6);
			exit(free_all(str, NULL, NULL, NULL));
		}
		if (str[i] == ' ' && str[i + 1] == ' ')
		{
			write(2, "Error\n", 6);
			exit(free_all(str, NULL, NULL, NULL));
		}
		i++;
	}
}

void	check_str(char *str)
{
	check_sign(str);
	if (ft_strlen(str) == 1 && !ft_isdigit(str[1]))
	{
		write(2, "Error\n", 6);
		exit(free_all(str, NULL, NULL, NULL));
	}
}
