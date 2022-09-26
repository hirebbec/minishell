/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:56:12 by hirebbec          #+#    #+#             */
/*   Updated: 2022/04/08 20:56:13 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dst, const char *src, int dstsize)
{
	int	i;
	int	k;
	int	len;

	i = 0;
	k = 0;
	len = ft_strlen(dst);
	if (dstsize <= ft_strlen(dst))
		return (ft_strlen(src) + dstsize);
	if (dstsize > ft_strlen(dst) + 1)
	{
		k = ft_strlen(dst);
		while (k < dstsize - 1 && src[i])
		{
			dst[k] = src[i];
			i++;
			k++;
		}
		dst[k] = '\0';
	}
	return (len + ft_strlen(src));
}
