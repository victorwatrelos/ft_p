/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/10 11:04:14 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/02/13 16:06:47 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void		ft_lstiter(t_list *list, void *(*f)(void *data));
void		ft_lstadd(t_list **begin, t_list *new_elem);
t_list		*ft_lstnew(void *content, size_t content_size);
void		ft_lstdel(t_list **begin, t_list *elem);
void		ft_lstdelone(t_list **list, t_list *elem);
void		free_tab(char **tab);

#endif
