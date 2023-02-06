/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_in.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: nanakani <nanakani@student.42tokyo.jp>     +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2023/02/06 23:54:41 by nanakani          #+#    #+#             */
/*   Updated: 2023/02/06 23:54:41 by nanakani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"
#include "ft_printf.h"
#include <limits.h>
#include <stddef.h>
#include <unistd.h>

size_t	ft_puthex(char *format, long long long_num)
{
	return (ft_putunsigned((unsigned int)long_num, format));
}
