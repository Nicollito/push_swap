/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_digit_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:49:32 by nimadela          #+#    #+#             */
/*   Updated: 2025/01/22 17:01:32 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_number(char *str)
{
	int i;
	int val;

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
	int	i;
	int	j;

	i = 0;
	j = 0;
	digit_array = malloc(sizeof(int) * len);
	while (str[i])
	{
		digit_array[j++] = ft_atoi(&str[i]);
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
			str = ft_strjoin(str, av[i++]);
	}
	else if (ac == 2)
	{
		str = ft_strdup(av[1]);
		if (!str)
			return (NULL);
	}
	return (str);
}
