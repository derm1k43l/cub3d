/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 22:58:02 by mrusu             #+#    #+#             */
/*   Updated: 2024/03/19 13:30:14 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
     The isascii() function tests for an ASCII character, which is any charac-
     ter between 0 and octal 0177 inclusive.
*/

#include "../inc/libft.h"

int	ft_isascii(int i)
{
	return (i >= 0 && i <= 127);
}
