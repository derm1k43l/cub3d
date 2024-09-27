/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:55:13 by mrusu             #+#    #+#             */
/*   Updated: 2024/03/19 13:32:18 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Parameters s: The string on which to iterate.
f: The function to apply to each character.
Return value The string created from the successive applications
of ’f’.
Returns NULL if the allocation fails.
External functs. malloc
Description Applies the function ’f’ to each character of the
string ’s’, and passing its index as first argument
to create a new string (with malloc(3)) resulting
from successive applications of ’f’.
*/

#include "../inc/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	unsigned int	i;
	char			*result;

	len = 0;
	result = ft_strdup(s);
	if (!s || !f)
		return (NULL);
	while (s[len])
		len++;
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = f(i, result[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
