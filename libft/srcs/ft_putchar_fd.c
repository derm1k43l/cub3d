/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:13:57 by mrusu             #+#    #+#             */
/*   Updated: 2024/03/19 13:31:34 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Parameters c: The character to output.
fd: The file descriptor on which to write.
Return value None
External functs. write
Description Outputs the character ’c’ to the given file
descriptor.
*/

#include "../inc/libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
