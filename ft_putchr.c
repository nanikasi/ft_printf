/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nanakani <nanakani@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:13:21 by nanakani          #+#    #+#             */
/*   Updated: 2023/02/06 12:13:21 by nanakani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>

ssize_t	ft_putchr(unsigned int n)
{
	ssize_t			length;
	unsigned char	c;

	c = (unsigned char)n;
	length = write(1, &c, 1);
	return (length);
}
