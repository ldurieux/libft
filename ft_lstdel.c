/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:52:40 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/01 13:52:40 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

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
}
