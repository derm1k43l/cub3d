/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:52:56 by mrusu             #+#    #+#             */
/*   Updated: 2024/03/19 13:31:10 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DESCRIPTION
// The memchr() function locates the first occurrence of c 
// (converted to an unsigned char) in string s.

// RETURN VALUES
// the memchr() function returns a pointer to the byte located, 
// or NULL if no such byte exists within n bytes.

#include "../inc/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	c = (unsigned char)c;
	while (n > 0 && *p != c)
	{
		++p;
		--n;
	}
	if (n == 0)
		return (NULL);
	else
		return ((void *)p);
}
