/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:52:20 by hirebbec          #+#    #+#             */
/*   Updated: 2022/04/08 20:52:21 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*d;
	size_t	i;

	d = malloc(count * size);
	if (d == 0)
		return (0);
	i = 0;
	while (i < size * count)
	{
		d[i] = 0;
		i++;
	}
	return ((void *)d);
}
