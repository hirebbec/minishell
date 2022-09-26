/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:48:52 by hirebbec          #+#    #+#             */
/*   Updated: 2022/05/12 16:53:14 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_num_dup(int *i)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	if (!i)
		return (0);
	while (1)
	{
		if (j == (*i))
			return (j);
		if (k == (*i))
			return (k);
		i++;
		k--;
	}
	return (0);
}