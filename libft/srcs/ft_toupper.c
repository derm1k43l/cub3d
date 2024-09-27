/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:34:02 by mrusu             #+#    #+#             */
/*   Updated: 2024/03/19 13:32:45 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
     The toupper() function converts a lower-case letter to the corresponding
     upper-case letter.  The argument must be representable as an unsigned
     char or the value of EOF.

     Although the toupper() function uses the current locale, the toupper_l()
     function may be passed a locale directly. See xlocale(3) for more infor-
     mation.

RETURN VALUES
     If the argument is a lower-case letter, the toupper() function returns
     the corresponding upper-case letter if there is one; otherwise, the argu-
     ment is returned unchanged.
*/

#include "../inc/libft.h"

int	ft_toupper(int i)
{
	if (i >= 97 && i <= 122)
		return (i -= 32);
	else
		return (i);
}
