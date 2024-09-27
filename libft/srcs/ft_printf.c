/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:24:39 by mrusu             #+#    #+#             */
/*   Updated: 2024/04/01 16:44:38 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_print_chr(int c)
{
	return (write(1, &c, 1));
}

static int	ft_putnbrlong(long n)
{
	int		count;

	count = 0;
	if (n < 0)
	{
		count += write(1, "-", 1);
		n *= -1;
	}
	if (n >= 10)
		count += ft_putnbrlong(n / 10);
	count += ft_print_chr(n % 10 + '0');
	return (count);
}

static int	ft_print_float(double n)
{
	int			count;
	long		integer_part;
	double		fractional_part;

	count = 0;
	if (n < 0)
		n *= -1;
	integer_part = (long)n;
	fractional_part = n - integer_part;
	count += ft_putnbrlong(integer_part);
	count += write(1, ".", 1);
	while (fractional_part > 0.000001 && count < 10)
	{
		fractional_part *= 10;
		count += ft_print_chr((int)fractional_part + '0');
		fractional_part -= (int)fractional_part;
	}
	return (count);
}

static int	ft_printf_chk(char conversions, va_list ap)
{
	int	return_v;

	return_v = 0;
	if (conversions == 'c')
		return_v += ft_print_chr(va_arg(ap, int));
	else if (conversions == 's')
		return_v += ft_putsrt(va_arg(ap, char *));
	else if (conversions == 'p')
		return_v += ft_print_ptr(va_arg(ap, size_t));
	else if (conversions == 'd' || conversions == 'i')
		return_v += ft_print_digits((long)va_arg(ap, int), 10, 'x');
	else if (conversions == 'u')
		return_v += ft_print_unsigned((unsigned long)va_arg(ap, unsigned int));
	else if (conversions == 'x')
		return_v += ft_print_digits((long)va_arg(ap, unsigned int), 16, 'x');
	else if (conversions == 'X')
		return_v += ft_print_digits((long)va_arg(ap, unsigned int), 16, 'X');
	else if (conversions == '%')
		return_v += write(1, &conversions, 1);
	else if (conversions == 'f')
		return_v += ft_print_float(va_arg(ap, double));
	return (return_v);
}

int	ft_printf(const char *str, ...)
{
	int			return_v;
	va_list		ap;

	va_start (ap, str);
	return_v = 0;
	while (*str)
	{
		if (*str == '%')
			return_v += ft_printf_chk(*(++str), ap);
		else
			return_v += write(1, str, 1);
		++str;
	}
	va_end(ap);
	return (return_v);
}
