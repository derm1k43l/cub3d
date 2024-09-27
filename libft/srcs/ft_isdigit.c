/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 22:38:31 by mrusu             #+#    #+#             */
/*   Updated: 2024/03/19 13:30:16 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
     The isdigit() function tests for a decimal digit character.  Regardless
     of locale, this includes the following characters only:

     ``0''         ``1''         ``2''         ``3''         ``4''
     ``5''         ``6''         ``7''         ``8''         ``9''
*/

#include "../inc/libft.h"

int	ft_isdigit(int i)
{
	return (i >= 48 && i <= 57);
}
