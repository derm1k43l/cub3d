/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:21:33 by mrusu             #+#    #+#             */
/*   Updated: 2024/03/19 13:31:18 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
     The memcpy() function copies n bytes from memory area src to memory area
     dst.  If dst and src overlap, behavior is undefined.  Applications in
     which dst and src might overlap should use memmove(3) instead.

RETURN VALUES
     The memcpy() function returns the original value of dst.
*/

#include "../inc/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	size_t		i;

	d = dst;
	s = src;
	i = 0;
	if (src == dst)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
