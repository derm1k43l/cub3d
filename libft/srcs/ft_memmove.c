/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:40:01 by mrusu             #+#    #+#             */
/*   Updated: 2024/03/19 13:31:22 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
     The memmove() function copies len bytes from string src to string dst.
     The two strings may overlap; the copy is always done in a non-destructive
     manner.

RETURN VALUES
     The memmove() function returns the original value of dst.
*/

#include "../inc/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	if (d < s)
	{
		while (len--)
			*d++ = *s++;
	}
	else if (d > s)
	{
		d += len;
		s += len;
		while (len--)
			*(--d) = *(--s);
	}
	return (dst);
}
