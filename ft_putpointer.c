/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nanakani <nanakani@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:09:59 by nanakani          #+#    #+#             */
/*   Updated: 2023/02/06 12:09:59 by nanakani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libftprintf.h"

static void	recursive(unsigned long long n, size_t* length);

size_t	ft_putpointer(long long pointer)
{
	size_t	length;
	unsigned long long	num;

	length = ft_putstr("0x");
	num = (unsigned long long)pointer;
	recursive(num, &length);
	return (length);
}

static void	recursive(unsigned long long n, size_t* length)
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
