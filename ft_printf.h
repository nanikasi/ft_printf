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

# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define DEC_FORMAT "0123456789"
# define LO_HEX_FORMAT "0123456789abcdef"
# define UP_HEX_FORMAT "0123456789ABCDEF"

typedef unsigned long long	t_ullong;

int		ft_printf(const char *format, ...);

ssize_t	ft_putchr(unsigned int n);
ssize_t	ft_putstr(char *str);
ssize_t	ft_putptr(t_ullong pointer);
ssize_t	ft_putuns(char *format, unsigned int nbr);
ssize_t	ft_putsig(char *format, int nbr);
size_t	ft_strlen(const char *s);

#endif