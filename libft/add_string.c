/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:35:13 by hirebbec          #+#    #+#             */
/*   Updated: 2022/05/07 21:08:59 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	**add_string(char **m, char *str)
{
	char	**new_m;
	int		i;

	i = ft_matrix_len(m);
	if (!str)
		return (m);
	new_m = malloc(sizeof(char *) * (i + 2));
	while (i > 0)
	{
		new_m[i - 1] = ft_strdup(m[i - 1]);
		i--;
	}
	new_m[ft_matrix_len(m)] = ft_strdup(str);
	new_m[ft_matrix_len(m) + 1] = NULL;
	free(str);
	free_mat(m);
	return (new_m);
}
