/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                     +:+ +:+        +:+     */
/*   By: nanakani <nanakani@student.42tokyo.jp>      +#+  +:+      +#+        */
/*                                                 +#+#+#+#+#+  +#+           */
/*   Created: 2022/11/27 02:52:37 by nanakani          #+#    #+#             */
/*   Updated: 2022/11/27 02:52:37 by nanakani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static ssize_t	ft_printf_router(char spec, va_list *args);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	size_t	length;
	ssize_t	tmplen;

	i = 0;
	length = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			tmplen = ft_printf_router(format[i++], &args);
			if (tmplen == -1)
				return (-1);
			length += (size_t)tmplen;
			continue ;
		}
		length += (size_t)ft_putchr(format[i++]);
	}
	va_end(args);
	return ((int)length);
}

static ssize_t	ft_printf_router(char spec, va_list *args)
{
	ssize_t	length;

	if (spec == 'c')
		length = ft_putchr(va_arg(*args, unsigned int));
	else if (spec == 's')
		length = ft_putstr(va_arg(*args, char *));
	else if (spec == 'p')
		length = ft_putptr(va_arg(*args, t_ullong));
	else if (spec == 'd')
		length = ft_putsig(DEC_FORMAT, va_arg(*args, int));
	else if (spec == 'i')
		length = ft_putsig(DEC_FORMAT, va_arg(*args, int));
	else if (spec == 'u')
		length = ft_putuns(DEC_FORMAT, va_arg(*args, unsigned int));
	else if (spec == 'x')
		length = ft_putuns(LO_HEX_FORMAT, va_arg(*args, t_ullong));
	else if (spec == 'X')
		length = ft_putuns(UP_HEX_FORMAT, va_arg(*args, t_ullong));
	else if (spec == '%')
		length = ft_putchr('%');
	else
		return (-1);
	return (length);
}
