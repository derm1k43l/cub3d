/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:03:52 by mrusu             #+#    #+#             */
/*   Updated: 2024/03/19 13:29:53 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
     The calloc() function contiguously allocates enough space for count
     objects that are size bytes of memory each and returns a pointer to the
     allocated memory.  The allocated memory is filled with bytes of value
     zero.
RETURN VALUES
     If successful, calloc(), malloc(), realloc(), reallocf(), valloc(), and
     aligned_alloc() functions return a pointer to allocated memory.  If there
     is an error, they return a NULL pointer and set errno to ENOMEM.
*/

#include "../inc/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_s;
	void	*p;

	total_s = count * size;
	p = malloc(total_s);
	if (p == NULL)
		return (NULL);
	else
	{
		ft_memset(p, 0, total_s);
		return (p);
	}
}
