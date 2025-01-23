/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:08:56 by nimadela          #+#    #+#             */
/*   Updated: 2025/01/23 14:37:59 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
/*
#include <stdio.h>
int	main(int ac, char **av)
{
	if (ac > 2)
	{
		printf("nop");
		return (0);
	}
	printf("%d\n", ft_strlen(av[1]));
	return (0);
}*/
