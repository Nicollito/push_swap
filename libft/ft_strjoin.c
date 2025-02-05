/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:25:04 by nimadela          #+#    #+#             */
/*   Updated: 2025/02/05 12:02:53 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	char	*res;
	char	*free_s1;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return ((char *)s1);
	free_s1 = s1;
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (!str)
	{
		free(free_s1);
		return (NULL);
	}
	res = str;
	while (*s1)
		*str++ = *s1++;
	if (s1)
		*str++ = ' ';
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	free(free_s1);
	return (res);
}
/* #include <stdio.h>
#include <string.h>
int    main(void)
{

    char *result_ft;

    char *s1 = NULL;
    char *s2 = NULL;

    result_ft = ft_strjoin(s1, s2);
    if (!result_ft)
        printf("ft_strjoin retourne NULL comme attendu ✅\n");
    else
    {
        printf("ft_strjoin ne retourne pas NULL ❌\n");
        //free(result_ft);
    }
	return (0);
} */