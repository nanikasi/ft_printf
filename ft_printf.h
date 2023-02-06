/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nanakani <nanakani@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 07:52:45 by nanakani          #+#    #+#             */
/*   Updated: 2023/02/06 07:52:45 by nanakani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

#define DEC_FORMAT "0123456789"
#define LO_HEX_FORMAT "0123456789abcdef"
#define UP_HEX_FORMAT "0123456789ABCDEF"

int ft_printf(const char *format, ...);

ssize_t	ft_putchar(unsigned char c);
// size_t	ft_putnbr_in(char* format, long long num);
size_t	ft_putstr(char* str);
size_t	ft_putpointer(long long pointer);
ssize_t	ft_putunsigned(unsigned int nbr, char* format);
ssize_t	ft_putsigned(int nbr, char* format);
size_t	ft_puthex(char* format, long long long_num);

#endif