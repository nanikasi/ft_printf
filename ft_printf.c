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

static ssize_t	ft_printf_router(char spec, va_list *args, size_t *length);

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
		if (format[i] == '%')
		{
			i++;
			if (ft_printf_router(format[i], &args, &length) == -1)
				return (-1);
			i++;
			continue ;
		}
		length += ft_putchar(format[i++]);
	}
	va_end(args);
	return (length);
}

static ssize_t	ft_printf_router(char spec, va_list *args, size_t *length)
{
	if (spec == 'c')
		*length += ft_putchar((unsigned char)va_arg(*args, int));
	else if (spec == 's')
		*length += ft_putstr(va_arg(*args, char *));
	else if (spec == 'p')
		*length += ft_putptr(va_arg(*args, long long));
	else if (spec == 'd' || spec == 'i')
		*length += ft_putsig(va_arg(*args, int), DEC_FORMAT);
	else if (spec == 'u')
		*length += ft_putuns(va_arg(*args, unsigned int), DEC_FORMAT);
	else if (spec == 'x')
		*length += ft_putuns((long long)va_arg(*args, long long),
				LO_HEX_FORMAT);
	else if (spec == 'X')
		*length += ft_putuns((long long)va_arg(*args, long long),
				UP_HEX_FORMAT);
	else if (spec == '%')
		*length += ft_putchar(spec);
	else
		return (-1);
	return (0);
}
