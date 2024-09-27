/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:02:57 by mrusu             #+#    #+#             */
/*   Updated: 2024/03/19 13:32:41 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
     The tolower() function converts an upper-case letter to the corresponding
     lower-case letter.  The argument must be representable as an unsigned
     char or the value of EOF.

     Although the tolower() function uses the current locale, the tolower_l()
     function may be passed a locale directly. See xlocale(3) for more infor-
     mation.

RETURN VALUES
     If the argument is an upper-case letter, the tolower() function returns
     the corresponding lower-case letter if there is one; otherwise, the argu-
     ment is returned unchanged.
*/

#include "../inc/libft.h"

int	ft_tolower(int i)
{
	if (i >= 65 && i <= 90)
		return (i += 32);
	else
		return (i);
}
