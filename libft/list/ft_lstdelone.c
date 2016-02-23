/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 15:30:57 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/02/13 15:30:58 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_lstdelone(t_list **list, t_list *elem)
{
	t_list	*last;
	t_list	*cur;

	if (elem == NULL)
		return ;
	cur = *list;
	if (cur == elem)
	{
		*list = cur->next;
		free(cur);
	}
	last = cur;
	cur = cur->next;
	while (cur != NULL)
	{
		if (cur == elem)
		{
			last->next = cur->next;
			free(cur);
			return ;
		}
		last = cur;
		cur = cur->next;
	}
}
