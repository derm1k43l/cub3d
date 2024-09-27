/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:01:14 by mrusu             #+#    #+#             */
/*   Updated: 2024/03/19 13:30:02 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_print_digits(long long nbr, int base, char letter_case)
{
	int		c;
	char	*s;

	if (letter_case == 'X')
		s = "0123456789ABCDEF";
	else if (letter_case == 'x')
		s = "0123456789abcdef";
	if (nbr < 0)
	{
		write(1, "-", 1);
		return (ft_print_digits(-nbr, base, letter_case) + 1);
	}
	else if (nbr < base)
	{
		return (ft_print_chr(s[nbr]));
	}
	else
	{
		c = ft_print_digits(nbr / base, base, letter_case);
		return (c + ft_print_digits(nbr % base, base, letter_case));
	}
}

int	ft_print_digits_ptr(size_t nbr, int base)
{
	int		c;
	char	*s;

	s = "0123456789abcdef";
	if (nbr < (size_t)base)
	{
		return (ft_print_chr(s[nbr]));
	}
	else
	{
		c = ft_print_digits_ptr(nbr / base, base);
		return (c + ft_print_digits_ptr(nbr % base, base));
	}
}

int	ft_print_unsigned(unsigned long long nbr)
{
	int		c;
	char	digit;

	if (nbr < 10)
	{
		digit = nbr + '0';
		write(1, &digit, 1);
		return (1);
	}
	else
	{
		c = ft_print_unsigned(nbr / 10);
		digit = nbr % 10 + '0';
		write(1, &digit, 1);
		return (c + 1);
	}
}

int	ft_print_ptr(size_t ptr)
{
	int			c;
	size_t		nbr;

	nbr = (size_t)ptr;
	c = 0;
	c += write(1, "0x", 2);
	if (nbr == 0)
		c += write(1, "0", 1);
	else
		c += ft_print_digits_ptr(nbr, 16);
	return (c);
}

int	ft_putsrt(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		i += 6;
		return (i);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
