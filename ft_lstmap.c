/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:44:09 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/08 14:44:11 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*last;
	t_list	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	res = NULL;
	last = NULL;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
		{
			ft_lstclear(res, del);
			return (NULL);
		}
		lst = lst->next;
		if (!last)
			res = tmp;
		else
			last->next = tmp;
		last = tmp;
	}
	return (res);
}
