/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parth.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:48:05 by hirebbec          #+#    #+#             */
/*   Updated: 2022/05/20 18:40:25 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_cmd(char *input)
{
	int	flag;
	int	i;

	i = 0;
	flag = 0;
	while (input[i])
	{
		if (input[i] == ONE && flag == 1 && input[i - 1] != '\\')
			flag = 0;
		else if (input[i] == ONE && flag == 0 && input[i - 1] != '\\')
			flag = 1;
		else if (input[i] == TWO && flag == 0 && input[i - 1] != '\\')
			flag = 2;
		else if (input[i] == TWO && flag == 2 && input[i - 1] != '\\')
			flag = 0;
		else if (input[i] == ';' && flag == 0)
			return (ft_substr(input, 0, i));
		i++;
	}
	return (ft_strdup(input));
}

t_call	*ft_parth(char *input, t_shell *shell)
{
	t_call	*call;

	call = NULL;
	shell->oldpwd = getcwd(NULL, 1024);
	shell->cd_flag = 0;
	input = close_check(input);
	add_history(input);
	input = star(input, shell, 0);
	if (!ft_strchr(input, (int) ';'))
		call = new_call(ft_strdup(input));
	else
		ft_printf(2, GREEN "MiniShell: " \
		WHITE "unexpected symbol `;'\n");
	if (!call)
		call = new_call("last");
	else
		add_back_call(&call, "last");
	free(input);
	return (call);
}

int	spaces(char *input)
{
	char	*tmp;

	tmp = ft_strtrim(input, " 	");
	if (ft_strlen(tmp) == 0)
	{
		free(tmp);
		return (0);
	}
	free(tmp);
	return (1);
}

char	*dollar_zero(int *i, char *str, t_shell *shell)
{
	char	*name;

	name = malloc(1);
	name[0] = 0;
	(*i)++;
	if (!str[(*i)])
	{
		free(name);
		return (ft_strdup("$"));
	}
	while (str[(*i)] && str[(*i)] != ' ' && str[(*i)] != '\\')
	{
		name = ft_charjoin_free(name, str[(*i)]);
		(*i)++;
	}
	if (!ft_strncmp(name, "?", 1) && ft_strlen(name) == 1)
	{
		free(name);
		return (ft_itoa(g_status));
	}
	return (ft_strdup(find_value(shell->env, name)));
}
