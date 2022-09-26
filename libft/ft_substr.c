/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:57:02 by hirebbec          #+#    #+#             */
/*   Updated: 2022/05/05 19:05:02 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, int start, int len)
{
	char	*dst;
	int		j;

	j = 0;
	if (s == 0)
		return (NULL);
	if (start > ft_strlen(s))
	{
		dst = malloc(sizeof(char));
		if (dst == 0)
			return (0);
	}
	else
	{
		if (ft_strlen(s) - start >= len)
			dst = malloc(sizeof(char) * (len + 1));
		else
			dst = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
		if (dst == 0)
			return (0);
		while (s[start] && len--)
			dst[j++] = s[start++];
	}
	dst[j] = '\0';
	return (dst);
}

char	*kek(char *s, char *dst)
{
	free(s);
	return (dst);
}

char	*ft_substr_free(char *s, int start, int len)
{
	char	*dst;
	int		j;

	j = 0;
	if (s == 0)
		return (NULL);
	if (start > ft_strlen(s))
	{
		dst = malloc(sizeof(char));
		if (dst == 0)
			return (0);
	}
	else
	{
		if (ft_strlen(s) - start >= len)
			dst = malloc(sizeof(char) * (len + 1));
		else
			dst = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
		if (dst == 0)
			return (0);
		while (s[start] && len--)
			dst[j++] = s[start++];
	}
	dst[j] = '\0';
	return (kek(s, dst));
}
