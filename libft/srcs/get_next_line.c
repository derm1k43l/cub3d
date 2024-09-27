/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:02:17 by mrusu             #+#    #+#             */
/*   Updated: 2024/03/29 15:47:13 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name get_next_line
// Prototype char *get_next_line(int fd);
// Turn in files get_next_line.c, get_next_line_utils.c,
// get_next_line.h
// Parameters fd: The file descriptor to read from
// Return value Read line: correct behavior
// NULL: there is nothing else to read, or an error
// occurred
// External functs. read, malloc, free
// Description Write a function hat returns a line read from a
// file descriptor

#include "../inc/libft.h"

static char	*extract_update(char *r_buffer)
{
	char	*unprocessed;
	ssize_t	i;

	i = 0;
	while (r_buffer[i] != '\n' && r_buffer[i] != '\0')
		i++;
	if (r_buffer[i] == 0)
		return (NULL);
	unprocessed = ft_substr(r_buffer, i + 1, ft_strlen(r_buffer) - i);
	if (*unprocessed == 0)
	{
		free(unprocessed);
		unprocessed = NULL;
	}
	r_buffer[i + 1] = '\0';
	return (unprocessed);
}

static char	*read_concatenate(int fd, char *unprocessed, char *r_buffer)
{
	ssize_t	bytes_r;
	char	*temp;

	bytes_r = 69;
	while (bytes_r > 0)
	{
		bytes_r = read(fd, r_buffer, BUFFER_SIZE);
		if (bytes_r == -1)
		{
			free(unprocessed);
			return (NULL);
		}
		else if (bytes_r == 0)
			break ;
		r_buffer[bytes_r] = '\0';
		if (!unprocessed)
			unprocessed = ft_strdup("");
		temp = unprocessed;
		unprocessed = ft_strjoin(temp, r_buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(unprocessed, '\n'))
			break ;
	}
	return (unprocessed);
}

char	*get_next_line(int fd)
{
	static char	*unprocessed;
	char		*line;
	char		*r_buffer;

	r_buffer = NULL;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(unprocessed);
		free(r_buffer);
		unprocessed = NULL;
		r_buffer = NULL;
		return (NULL);
	}
	r_buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!r_buffer)
		return (NULL);
	line = read_concatenate(fd, unprocessed, r_buffer);
	free(r_buffer);
	r_buffer = NULL;
	if (!line)
		return (NULL);
	unprocessed = extract_update(line);
	return (line);
}

// --------FOR TESTING PORPUS OF THIS ALONE-----------

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("text.txt", O_RDONLY);
// 	while (69)
// 	{
// 		line = get_next_line(fd);
// 		if (line == NULL)
// 			break ;
// 		printf("%s", line);
// 		free(line);
// 	}
// 	return (0);
// }
