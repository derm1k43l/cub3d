/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:53:48 by mrusu             #+#    #+#             */
/*   Updated: 2024/03/19 13:30:41 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name ft_lstclear
// Prototype void ft_lstclear(t_list **lst, void (*del)(void*));
// Turn in files -
// Parameters lst: The address of a pointer to a node.
// del: The address of the function used to delete
// the content of the node.
// Return value None
// External functs. free
// Description Deletes and frees the given node and every
// successor of that node, using the function ’del’
// and free(3).
// Finally, the pointer to the list must be set to
// NULL.

#include "../inc/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*next;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current)
	{
		next = current->next;
		del(current->content);
		free(current);
		current = next;
	}
	*lst = NULL;
}
