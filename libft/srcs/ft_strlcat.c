/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 21:30:06 by mrusu             #+#    #+#             */
/*   Updated: 2024/03/19 13:32:06 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
     The strlcpy() and strlcat() functions copy and concatenate strings with
     the same input parameters and output result as snprintf(3).  They are
     designed to be safer, more consistent, and less error prone replacements
     for the easily misused functions strncpy(3) and strncat(3).

     strlcpy() and strlcat() take the full size of the destination buffer and
     guarantee NUL-termination if there is room.  Note that room for the NUL
     should be included in dstsize.

     strlcpy() copies up to dstsize - 1 characters from the string src to dst,
     NUL-terminating the result if dstsize is not 0.

     strlcat() appends string src to the end of dst.  It will append at most
     dstsize - strlen(dst) - 1 characters.  It will then NUL-terminate, unless
     dstsize is 0 or the original dst string was longer than dstsize (in prac-
     tice this should not happen as it means that either dstsize is incorrect
     or that dst is not a proper string).

     If the src and dst strings overlap, the behavior is undefined.

RETURN VALUES
     Besides quibbles over the return type (size_t versus int) and signal han-
     dler safety (snprintf(3) is not entirely safe on some systems), the fol-
     lowing two are equivalent:

           n = strlcpy(dst, src, len);
           n = snprintf(dst, len, "%s", src);

     Like snprintf(3), the strlcpy() and strlcat() functions return the total
     length of the string they tried to create.  For strlcpy() that means the
     length of src.  For strlcat() that means the initial length of dst plus
     the length of src.

     If the return value is >= dstsize, the output string has been truncated.
     It is the caller's responsibility to handle this.
*/

#include "../inc/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;

	dst_len = 0;
	src_len = 0;
	while (dst[dst_len] && dst_len < dstsize)
		dst_len++;
	while (src[src_len] && (dst_len + src_len + 1) < dstsize)
	{
		dst[dst_len + src_len] = src[src_len];
		src_len++;
	}
	if (dst_len < dstsize)
		dst[dst_len + src_len] = '\0';
	return (dst_len + ft_strlen(src));
}
