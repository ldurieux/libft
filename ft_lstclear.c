/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:44:00 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/08 14:44:01 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*it;
	t_list	*next;

	if (!lst || !del)
		return ;
	it = *lst;
	while (it)
	{
		del(it->content);
		next = it->next;
		free(it);
		it = next;
	}
	*lst = NULL;
}
