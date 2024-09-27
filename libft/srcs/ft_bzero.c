/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:32:30 by mrusu             #+#    #+#             */
/*   Updated: 2024/03/19 13:29:23 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DESCRIPTION
// The bzero() function writes n zeroed bytes to the string s.  
// If n is zero, bzero() does nothing.

#include "../inc/libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (n != 0)
	{
		*((unsigned char *)s + i) = 0;
		i++;
		n--;
	}
}
