/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:50:32 by mrusu             #+#    #+#             */
/*   Updated: 2024/03/19 13:31:26 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
     The memset() function writes len bytes of value c (converted to an
     unsigned char) to the string b.

RETURN VALUES
     The memset() function returns its first argument.
*/

#include "../inc/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	uc;

	uc = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		*((unsigned char *)b + i) = uc;
		i++;
	}
	return (b);
}
