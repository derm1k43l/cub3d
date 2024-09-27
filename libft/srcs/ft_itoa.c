/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:06:06 by mrusu             #+#    #+#             */
/*   Updated: 2024/03/19 13:30:29 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Return value The string representing the integer.
NULL if the allocation fails.
External functs. malloc
Description Allocates (with malloc(3)) and returns a string
representing the integer received as an argument.
Negative numbers must be handled.
*/

#include "../inc/libft.h"

static void	cnv_num(char *str, long n, int l, int sign)

{
	str[l] = '\0';
	while (l > 0)
	{
		str[--l] = n % 10 * sign + '0';
		n /= 10;
	}
	if (sign == -1)
		str[0] = '-';
}

static int	get_len(long n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len = 1;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		sign;
	int		len;
	char	*str;

	sign = 1;
	if (n < 0)
		sign = -1;
	len = get_len(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	cnv_num(str, (long)n, len, sign);
	return (str);
}
