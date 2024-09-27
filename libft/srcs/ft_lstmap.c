/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:58:26 by mrusu             #+#    #+#             */
/*   Updated: 2024/03/19 13:30:55 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name ft_lstmap
// Prototype t_list *ft_lstmap(t_list *lst, void *(*f)(void *),
// void (*del)(void *));
// Turn in files -
// Parameters lst: The address of a pointer to a node.
// f: The address of the function used to iterate on
// the list.
// del: The address of the function used to delete
// the content of a node if needed.
// Return value The new list.
// NULL if the allocation fails.
// External functs. malloc, free
// Description Iterates the list ’lst’ and applies the function
// ’f’ on the content of each node. Creates a new
// list resulting of the successive applications of
// the function ’f’. The ’del’ function is used to
// delete the content of a node if needed.

#include "../inc/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_l;
	t_list	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	new_l = NULL;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
		{
			ft_lstclear(&new_l, del);
			return (NULL);
		}
		ft_lstadd_back(&new_l, tmp);
		lst = lst->next;
	}
	return (new_l);
}
