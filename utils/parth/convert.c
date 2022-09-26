/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 15:34:51 by hirebbec          #+#    #+#             */
/*   Updated: 2022/05/20 19:35:34 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*dollar_zero(int *i, char *str, t_shell *shell);

char	*case_one(char *str, int *i);

char	*case_two(char *str, int *i, t_shell *shell)
{
	char	*res;

	res = malloc(1);
	res[0] = 0;
	(*i)++;
	while (str[(*i)] && !(str[(*i)] == TWO && str[(*i) - 1] != '\\'))
	{
		if (str[(*i)] == '$')
			res = ft_strjoin_full_free(res, dollar(i, str, shell));
		else
		{
			res = ft_charjoin_free(res, str[(*i)]);
			(*i)++;
		}
	}
	(*i)++;
	return (res);
}

void	ft_tmp11(char **cmd, char *str, int *i);

char	*case_one(char *str, int *i)
{
	char	*res;

	res = malloc(1);
	res[0] = 0;
	(*i)++;
	while (str[(*i)] && str[(*i)] != ONE)
	{
		res = ft_charjoin_free(res, str[(*i)]);
		(*i)++;
	}
	(*i)++;
	return (res);
}

char	*case_zero(char *str, int *i, t_shell *shell)
{
	char	*res;

	res = malloc(1);
	res[0] = 0;
	while (str[(*i)])
	{
		if (str[(*i)] == ONE)
			res = ft_strjoin_full_free(res, case_one(str, i));
		else if (str[(*i)] == TWO)
			res = ft_strjoin_full_free(res, case_two(str, i, shell));
		else if (str[(*i)] == '$')
			res = ft_strjoin_full_free(res, dollar_zero(i, str, shell));
		else
		{
			res = ft_charjoin_free(res, str[(*i)]);
			(*i)++;
		}
	}
	return (res);
}

char	*convert(char *str, t_shell *shell)
{
	int		i;
	char	*res;

	res = malloc(1);
	res[0] = 0;
	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
		res = ft_strjoin_full_free(res, case_zero(str, &i, shell));
	return (res);
}

char	**ft_convert(char **cmds, t_shell *shell)
{
	int		i;
	char	*tmp;

	i = 0;
	while (cmds[i])
	{
		tmp = ft_strdup(cmds[i]);
		free(cmds[i]);
		cmds[i] = convert(tmp, shell);
		free(tmp);
		i++;
	}
	return (cmds);
}
