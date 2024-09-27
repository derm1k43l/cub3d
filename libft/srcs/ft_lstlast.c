/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:47:34 by mrusu             #+#    #+#             */
/*   Updated: 2024/03/19 13:30:52 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name ft_lstlast
// Prototype t_list *ft_lstlast(t_list *lst);
// Turn in files -
// Parameters lst: The beginning of the list.
// Return value Last node of the list
// External functs. None
// Description Returns the last node of the list.

#include "../inc/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
