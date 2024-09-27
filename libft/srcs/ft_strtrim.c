/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:34:02 by mrusu             #+#    #+#             */
/*   Updated: 2024/03/19 13:32:34 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Parameters s1: The string to be trimmed.
set: The reference set of characters to trim.
Return value The trimmed string.
NULL if the allocation fails.
External functs. malloc
Description Allocates (with malloc(3)) and returns a copy of
’s1’ with the characters specified in ’set’ removed
from the beginning and the end of the string.
*/

#include "../inc/libft.h"

static void	find_trim(const char *s, const char *set, size_t *strt, size_t *e)
{
	*strt = 0;
	*e = ft_strlen(s);
	while (s[*strt] && ft_strchr(set, s[*strt]))
		(*strt)++;
	while (*e > *strt && ft_strchr(set, s[(*e) - 1]))
		(*e)--;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	strt;
	size_t	e;
	size_t	i;
	char	*trim;

	strt = 0;
	e = 0;
	i = 0;
	find_trim(s1, set, &strt, &e);
	if (!s1 || !set)
		return (NULL);
	len = e - strt;
	trim = (char *)malloc(sizeof(char) *(len + 1));
	if (!trim)
		return (NULL);
	while (i < len)
	{
		trim[i] = s1[i + strt];
		i++;
	}
	trim[i] = '\0';
	return (trim);
}
