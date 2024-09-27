/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:10:23 by mrusu             #+#    #+#             */
/*   Updated: 2024/03/19 13:31:38 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Parameters s: The string to output.
fd: The file descriptor on which to write.
Return value None
External functs. write
Description Outputs the string ’s’ to the given file descriptor
followed by a newline.
*/

#include "../inc/libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
	write(fd, "\n", 1);
}
