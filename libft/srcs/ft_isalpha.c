/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:17:58 by mrusu             #+#    #+#             */
/*   Updated: 2024/03/19 13:30:10 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
     The isalpha() function tests for any character for which isupper(3) or
     islower(3) is true.  The value of the argument must be representable as
     an unsigned char or the value of EOF.
*/

#include "../inc/libft.h"

int	ft_isalpha(int i)
{
	return ((i >= 97 && i <= 122) || (i >= 65 && i <= 90));
}
