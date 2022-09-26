/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_strlen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:59:04 by hirebbec          #+#    #+#             */
/*   Updated: 2022/04/08 20:59:05 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen_p(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] != '\0')
		i++;
	return (i);
}

int	ft_strlen_nb(unsigned long nb)
{
	unsigned int	count;

	count = 1;
	while ((nb / 10) != 0)
	{
		count += 1;
		nb /= 10;
	}
	return (count);
}

int	ft_strlen_inint(unsigned int nb)
{
	unsigned int	count;

	count = 1;
	while ((nb / 10) != 0)
	{
		count += 1;
		nb /= 10;
	}
	return (count);
}

int	ft_diglen16(unsigned int nb)
{
	unsigned int	count;

	count = 1;
	while ((nb / 16) != 0)
	{
		count += 1;
		nb /= 16;
	}
	return (count);
}

int	ft_diglenlong(unsigned long nb)
{
	unsigned int	count;

	count = 1;
	while ((nb / 16) != 0)
	{
		count += 1;
		nb /= 16;
	}
	return (count);
}
