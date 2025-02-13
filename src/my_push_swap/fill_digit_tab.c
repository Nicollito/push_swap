/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_digit_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:49:32 by nimadela          #+#    #+#             */
/*   Updated: 2025/02/13 14:11:26 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	count_number(char *str)
{
	int	i;
	int	val;

	i = 0;
	val = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			while (ft_isdigit(str[i]))
				i++;
			val++;
		}
		if (str[i])
			i++;
	}
	return (val);
}

int	*fill_digit_array(char *str, int *digit_array, int len)
{
	int			i;
	int			j;
	long int	checker;

	i = 0;
	j = 0;
	digit_array = malloc(sizeof(int) * len);
	if (!digit_array)
		exit(free_all(str, NULL, NULL, NULL));
	while (str[i] && len--)
	{
		checker = ft_atoi(&str[i]);
		if (checker > INT_MAX || checker < INT_MIN)
		{
			write(2, "Error\n", 6);
			exit(free_all(str, digit_array, NULL, NULL));
		}
		digit_array[j++] = (int)checker;
		i++;
		if (str[i] == '-')
			i++;
		while (ft_isdigit(str[i]))
			i++;
	}
	return (digit_array);
}

char	*fill_str(int ac, char **av, char *str)
{
	int	i;

	i = 1;
	if (ac > 2)
	{
		while (av[i])
		{
			str = ft_strjoin(str, av[i++]);
			if (!str)
				exit(1);
		}
	}
	else if (ac == 2)
	{
		str = ft_strdup(av[1]);
		if (!str)
			exit(1);
	}
	if (!check_if_isdigit(str))
	{
		write(2, "Error\n", 6);
		exit(free_all(str, NULL, NULL, NULL));
	}
	check_str(str);
	return (str);
}
