/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:09:12 by mrusu             #+#    #+#             */
/*   Updated: 2024/03/19 13:31:42 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Parameters n: The integer to output.
fd: The file descriptor on which to write.
Return value None
External functs. write
Description Outputs the integer ’n’ to the given file
descriptor.
*/

#include "../inc/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = -n;
		}
		if (n >= 10)
			ft_putnbr_fd(n / 10, fd);
		c = n % 10 + '0';
		write(fd, &c, 1);
	}
}
