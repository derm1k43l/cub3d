/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 23:04:51 by mrusu             #+#    #+#             */
/*   Updated: 2024/03/19 13:30:19 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
     The isprint() function tests for any printing character, including space
     (` ').  The value of the argument must be representable as an unsigned
     char or the value of EOF.
*/

#include "../inc/libft.h"

int	ft_isprint(int i)
{
	return (i >= 32 && i <= 126);
}
