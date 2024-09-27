/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 22:47:29 by mrusu             #+#    #+#             */
/*   Updated: 2024/03/19 13:30:06 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
     The isalnum() function tests for any character for which isalpha(3) or
     isdigit(3) is true.  The value of the argument must be representable as
     an unsigned char or the value of EOF.

     In the ASCII character set, this includes the following characters (pre-
     ceded by their numeric values, in octal):
*/

#include "../inc/libft.h"

int	ft_isalnum(int i)
{
	return (ft_isalpha(i) || ft_isdigit(i));
}
