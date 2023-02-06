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

#include <unistd.h>
#include <stddef.h>

ssize_t	ft_putchar(unsigned char c)
{
	ssize_t	length;
	
	length = write(1, &c, 1);
	return (length);
}
