/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:02:04 by mrusu             #+#    #+#             */
/*   Updated: 2024/03/19 13:29:15 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
     The atoi() function converts the initial portion of the string pointed to
     by str to int representation.

     It is equivalent to:

           (int)strtol(str, (char **)NULL, 10);

     While the atoi() function uses the current locale, the atoi_l() function
     may be passed a locale directly. See xlocale(3) for more information.

IMPLEMENTATION NOTES
     The atoi() and atoi_l() functions are thread-safe and async-cancel-safe.

     The strtol() and strtol_l() functions are recommended instead of atoi()
     and atoi_l() functions, especially in new code.
*/

#include "../inc/libft.h"

int	ft_atoi(const char *str)
{
	long	negative;
	long	result;
	long	i;

	negative = 0;
	result = 0;
	i = 0;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t' || \
	str[i] == '\n' || str[i] == '\r' || str[i] == '\f' || str[i] == '\v'))
		i++;
	if (str[i] != '\0' && str[i] == '-')
	{
		negative = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '\0' && ft_isdigit(str[i]))
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	if (negative == 1)
		return (-result);
	return (result);
}
