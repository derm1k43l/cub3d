/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:59:34 by mrusu             #+#    #+#             */
/*   Updated: 2024/03/19 13:31:56 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
     The strdup() function allocates sufficient memory for a copy of the
     string s1, does the copy, and returns a pointer to it.  The pointer may
     subsequently be used as an argument to the function free(3).

     If insufficient memory is available, NULL is returned and errno is set to
     ENOMEM.

     The strndup() function copies at most n characters from the string s1
     always NUL terminating the copied string.
*/

#include "../inc/libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*copy;

	len = ft_strlen(s1);
	copy = (char *)malloc(len +1);
	if (copy == NULL)
		return (NULL);
	ft_strlcpy(copy, s1, len +1);
	return (copy);
}
