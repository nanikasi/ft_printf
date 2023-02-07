/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nanakani <nanakani@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:07:10 by nanakani          #+#    #+#             */
/*   Updated: 2023/02/06 12:07:10 by nanakani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>

ssize_t	ft_putstr(char *str)
{
	ssize_t	length;

	length = 0;
	if (str == NULL)
		return (ft_putstr("(null)"));
	while (str[length] != '\0')
	{
		write(1, &(str[length]), 1);
		length++;
	}
	return (length);
}
