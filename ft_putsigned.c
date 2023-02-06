/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_digit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: nanakani <nanakani@student.42tokyo.jp>     +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2023/02/06 07:41:51 by nanakani          #+#    #+#             */
/*   Updated: 2023/02/06 07:41:51 by nanakani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"
#include "ft_printf.h"
#include <limits.h>
#include <stddef.h>
#include <unistd.h>

static void	recursive(int n, size_t *length, size_t base, char *format);

ssize_t	ft_putsigned(int nbr, char *format)
{
	size_t	length;
	size_t	base;

	length = 0;
	base = ft_strlen(format);
	if (nbr == INT_MIN)
		return (ft_putstr("-2147483648"));
	if (nbr < 0)
	{
		write(1, "-", 1);
		length++;
		nbr *= -1;
	}
	recursive(nbr, &length, base, format);
	return (length);
}

static void	recursive(int n, size_t *length, size_t base, char *format)
{
	if (n < (int)base)
	{
		write(1, &format[n], 1);
		(*length)++;
	}
	else
	{
		recursive(n / base, length, base, format);
		recursive(n % base, length, base, format);
	}
}
