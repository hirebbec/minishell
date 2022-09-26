/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:56:05 by hirebbec          #+#    #+#             */
/*   Updated: 2022/05/20 18:02:24 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	size;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	size = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (size + 1));
	if (res == 0)
		return (NULL);
	while (*s1 != '\0')
		*res++ = *s1++;
	while (*s2 != '\0')
		*res++ = *s2++;
	*res = '\0';
	return (res - size);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char		*strjoin;
	size_t		strjoinlen;
	size_t		i;
	size_t		j;

	j = 0;
	if (!s1)
	{
		s1 = (char *)malloc(1);
		if (!s1)
			return (0);
		s1[0] = 0;
	}
	strjoinlen = ft_strlen(s1) + ft_strlen(s2) + 1;
	strjoin = (char *)malloc(strjoinlen);
	if (!strjoin)
		return (0);
	i = -1;
	while (s1[++i])
		strjoin[i] = s1[i];
	while (s2[j])
		strjoin[i++] = s2[j++];
	strjoin[i] = 0;
	free(s1);
	return (strjoin);
}

char	*lol(char *s)
{
	if (!s)
	{
		s = (char *)malloc(1);
		s[0] = 0;
	}
	return (s);
}

char	*ft_strjoin_full_free(char *s1, char *s2)
{
	char		*strjoin;
	size_t		strjoinlen;
	size_t		i;
	size_t		j;

	j = 0;
	s1 = lol(s1);
	s2 = lol(s2);
	strjoinlen = ft_strlen(s1) + ft_strlen(s2) + 1;
	strjoin = (char *)malloc(strjoinlen);
	if (!strjoin)
		return (0);
	i = -1;
	while (s1[++i])
		strjoin[i] = s1[i];
	while (s2[j])
		strjoin[i++] = s2[j++];
	strjoin[i] = 0;
	free(s1);
	free(s2);
	return (strjoin);
}
