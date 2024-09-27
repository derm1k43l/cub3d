/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:56:33 by mrusu             #+#    #+#             */
/*   Updated: 2024/03/19 13:30:47 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name ft_lstiter
// Prototype void ft_lstiter(t_list *lst, void (*f)(void *));
// Turn in files -
// Parameters lst: The address of a pointer to a node.
// f: The address of the function used to iterate on
// the list.
// Return value None
// External functs. None
// Description Iterates the list ’lst’ and applies the function
// ’f’ on the content of each node.

#include "../inc/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
