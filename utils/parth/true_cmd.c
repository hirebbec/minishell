/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   true_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:32:42 by hirebbec          #+#    #+#             */
/*   Updated: 2022/05/20 19:47:06 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	one_cs(char *str, int *i)
{
	(*i)++;
	while (str[(*i)] != ONE && str[(*i)])
		(*i)++;
	(*i)++;
}

void	two_cs(char *str, int *i)
{
	(*i)++;
	while (str[(*i)] != TWO && str[(*i)])
		(*i)++;
	(*i)++;
}

char	*get_piece(char *line, int *i)
{
	int	start;

	start = (*i);
	while (line[(*i)] && line[(*i)] != ' ')
	{
		if (line[(*i)] == TWO)
		{
			(*i)++;
			while (line[(*i)] != TWO && line[(*i)])
				(*i)++;
			(*i)++;
		}
		else if (line[(*i)] == ONE)
		{
			(*i)++;
			while (line[(*i)] != ONE && line[(*i)])
				(*i)++;
			(*i)++;
		}
		else
			(*i)++;
	}
	return (ft_substr(line, start, (*i) - start));
}

char	**true_cmds(char *line)
{
	char	**m;
	int		i;

	i = 0;
	m = malloc(sizeof(char *));
	m[0] = NULL;
	while (line[i])
	{
		m = add_string(m, get_piece(line, &i));
		while (line[i] == ' ')
			i++;
	}
	return (m);
}

void	sig_lol(int sig)
{
	(void)sig;
	write(1, "\n", 1);
}
