/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:56:55 by hirebbec          #+#    #+#             */
/*   Updated: 2022/05/07 20:56:24 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char *s1, char *set)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	if (!set)
		return ((char *)s1);
	if (!s1)
		return (NULL);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	j = ft_strlen(s1) - 1;
	while (j > 0 && ft_strchr(set, s1[j]))
		j--;
	res = ft_substr(s1, i, j + 1 - i);
	return (res);
}

char	*ft_strtrim_free(char *s1, char *set)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	if (!set)
		return ((char *)s1);
	if (!s1)
		return (NULL);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	j = ft_strlen(s1) - 1;
	while (j > 0 && ft_strchr(set, s1[j]))
		j--;
	res = ft_substr(s1, i, j + 1 - i);
	free(s1);
	return (res);
}
