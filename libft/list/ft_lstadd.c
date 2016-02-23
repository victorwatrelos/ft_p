/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 15:30:39 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/02/13 15:30:40 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_lstadd(t_list **begin, t_list *new_elem)
{
	t_list		*list;

	if (*begin == NULL)
	{
		*begin = new_elem;
		return ;
	}
	list = *begin;
	while (list->next != NULL)
		list = list->next;
	list->next = new_elem;
}
