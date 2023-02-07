/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nanakani <nanakani@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 08:42:05 by nanakani          #+#    #+#             */
/*   Updated: 2023/02/07 08:42:05 by nanakani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	recursive(t_ullong n, ssize_t *length);

ssize_t	ft_putptr(t_ullong pointer)
{
	ssize_t	length;

	length = ft_putstr("0x");
	recursive(pointer, &length);
	return (length);
}

static void	recursive(t_ullong n, ssize_t *length)
{
	if (n < 16)
	{
		write(1, &LO_HEX_FORMAT[n], 1);
		(*length)++;
	}
	else
	{
		recursive(n / 16, length);
		recursive(n % 16, length);
	}
}
