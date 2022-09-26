/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:56:35 by hirebbec          #+#    #+#             */
/*   Updated: 2022/05/12 17:57:29 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((*(s1 + i) || *(s2 + i)) && i < n)
	{	
		if (*(s1 + i) != *(s2 + i))
			return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
		i++;
	}
	return (0);
}

int	ft_rev_strncmp(const char *s1, const char *s2, int n)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	j = ft_strlen(s2) - 2;
	i = ft_strlen(s1) - 1;
	while ((j > -1 || i > -1) && k < n)
	{
		if (s1[i] != s2[j])
			return (1);
		i--;
		j--;
		k++;
	}
	return (0);
}
