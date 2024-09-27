/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:47:20 by mrusu             #+#    #+#             */
/*   Updated: 2024/03/19 13:32:26 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
     The strnstr() function locates the first occurrence of the null-termi-
     nated string needle in the string haystack, where not more than len char-
     acters are searched.  Characters that appear after a `\0' character are
     not searched.  Since the strnstr() function is a FreeBSD specific API, it
     should only be used when portability is not a concern.
RETURN VALUES
     If needle is an empty string, haystack is returned; if needle occurs
     nowhere in haystack, NULL is returned; otherwise a pointer to the first
     character of the first occurrence of needle is returned.
*/

#include "../inc/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (needle[j] && haystack[i + j] == needle[j] && (i + j) < len)
			j++;
		if (!needle[j])
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
