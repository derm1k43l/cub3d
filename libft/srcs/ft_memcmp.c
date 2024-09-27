/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:34:29 by mrusu             #+#    #+#             */
/*   Updated: 2024/03/19 13:31:14 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DESCRIPTION
//      The memcmp() function compares byte string s1 against byte string s2.
// Both strings are assumed to be n bytes long.

// RETURN VALUES
// The memcmp() function returns zero if the two strings are identical,
// otherwise returns the difference between the first two differing bytes 
// (treated as unsigned char values, so that `\200' is greater than
// `\0', for example).  Zero-length strings are always identical.  
// This behavior is not required by C and
// portable code should only depend on the sign of the returned value.

#include "../inc/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;
	size_t				i;

	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}
