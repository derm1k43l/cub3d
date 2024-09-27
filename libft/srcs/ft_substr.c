/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:52:45 by mrusu             #+#    #+#             */
/*   Updated: 2024/03/19 13:32:37 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Parameters s: The string from which to create the substring.
start: The start index of the substring in the
string ’s’.
len: The maximum length of the substring.
Return value The substring.
NULL if the allocation fails.
External functs. malloc
Description Allocates (with malloc(3)) and returns a substring
from the string ’s’.
The substring begins at index ’start’ and is of
maximum size ’len’.
*/

#include "../inc/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	str_len;
	size_t	sub_len;
	size_t	i;
	char	*substr;

	str_len = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start > str_len)
		return (ft_strdup(""));
	if (str_len - start < len)
		sub_len = str_len - start;
	else
		sub_len = len;
	substr = (char *)malloc(sizeof(char) * (sub_len +1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < sub_len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
