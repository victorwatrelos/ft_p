/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 15:31:16 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/02/13 15:31:17 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list		*ft_lstnew(void *content, size_t content_size)
{
	t_list		*elem;

	if ((elem = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	elem->content = content;
	elem->content_size = content_size;
	elem->next = NULL;
	return (elem);
}
