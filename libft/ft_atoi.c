/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:53:30 by nimadela          #+#    #+#             */
/*   Updated: 2025/01/27 10:45:24 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_atoi(const char *nptr)
{
	int					sign;
	unsigned long long	res;

	sign = 1;
	res = 0;
	while (*nptr && ((*nptr >= 9 && *nptr <= 13) || *nptr == 32))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr && (*nptr >= '0' && *nptr <= '9'))
		res = res * 10 + (*nptr++ - '0');
	return ((long int)res * sign);
}
