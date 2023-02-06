/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: nanakani <nanakani@student.42tokyo.jp>     +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2022/11/27 02:52:37 by nanakani          #+#    #+#             */
/*   Updated: 2022/11/27 02:52:37 by nanakani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static ssize_t	ft_printf_router(const char *format, size_t i, va_list *args,
					size_t *length);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	size_t	length;

	va_start(args, format);
	i = 0;
	length = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			length += ft_putchar(format[i++]);
			continue ;
		}
		i++;
		if (ft_printf_router(format, i, &args, &length) == -1)
			return (-1);
		i++;
	}
	va_end(args);
	return (length);
}

static ssize_t	ft_printf_router(const char *format, size_t i, va_list *args,
		size_t *length)
{
	if (format[i] == 'c')
		*length += ft_putchar((unsigned char)va_arg(*args, int));
	else if (format[i] == 's')
		*length += ft_putstr(va_arg(*args, char *));
	else if (format[i] == 'p')
		*length += ft_putpointer(va_arg(*args, long long));
	else if (format[i] == 'd' || format[i] == 'i')
		*length += ft_putsigned(va_arg(*args, int), DEC_FORMAT);
	else if (format[i] == 'u')
		*length += ft_putunsigned(va_arg(*args, unsigned int), DEC_FORMAT);
	else if (format[i] == 'x')
		*length += ft_putunsigned((long long)va_arg(*args, long long),
				LO_HEX_FORMAT);
	else if (format[i] == 'X')
		*length += ft_putunsigned((long long)va_arg(*args, long long),
				UP_HEX_FORMAT);
	else if (format[i] == '%')
		*length += ft_putchar(format[i]);
	else
		return (-1);
	return (0);
}
