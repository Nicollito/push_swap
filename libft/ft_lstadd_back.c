/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:57:57 by nimadela          #+#    #+#             */
/*   Updated: 2025/01/23 13:03:09 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new, int which)
{
	t_list	*temp;

	if (!lst[which])
	{
		lst[which] = new;
		return ;
	}
	temp = lst[which];
	ft_lstlast(temp)-> next = new;
}
