/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:46:45 by hirebbec          #+#    #+#             */
/*   Updated: 2022/05/07 14:55:14 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_temp2(int *j, char *c, int *flag, char *input);

void	ft_temp(int *i, char *c, int *flag, char *input)
{
	while (input[(*i)])
	{
		if (input[(*i)] == 34 && input[(*i) - 1] != 92)
		{
			(*c) = 34;
			(*flag) = 1;
			break ;
		}
		if (input[(*i)] == 39 && input[(*i) - 1] != 92)
		{
			(*c) = 39;
			(*flag) = 1;
			break ;
		}
		(*i)++;
	}
}

int	end_check(char	*input)
{
	int		i;
	char	c;
	int		flag;
	int		j;

	j = 0;
	flag = 0;
	while (input[j])
	{
		i = j;
		ft_temp(&i, &c, &flag, input);
		j = i + 1;
		ft_temp2(&j, &c, &flag, input);
		j++;
	}
	if (flag == 0 && input[ft_strlen(input) - 1] == 92)
		flag = 1;
	return (flag);
}

char	*close_check(char *input)
{
	char	*tmp;

	while (end_check(input))
	{
		if (input[ft_strlen(input) - 1] == 92)
		{
			tmp = ft_substr(input, 0, ft_strlen(input) - 1);
			free(input);
			input = ft_strdup(tmp);
			free(tmp);
		}
		else
			input = ft_strjoin_free(input, "\n");
		tmp = readline(">");
		input = ft_strjoin_free(input, tmp);
		free(tmp);
	}
	return (input);
}

char	*find_value(t_env *env, char *name)
{
	if (!name)
		return (NULL);
	ft_first_element(&env);
	while (env->next)
	{
		if (!ft_strncmp(env->name, name, ft_strlen(name)) \
		&& ft_len_dif(env->name, name) == 0)
		{
			free(name);
			return (env->value);
		}
		env = env->next;
	}
	if (!ft_strncmp(env->name, name, ft_strlen(name)) && \
	ft_len_dif(env->name, name) == 0)
	{
		free(name);
		return (env->value);
	}
	free(name);
	return (NULL);
}

char	*dollar(int *i, char *str, t_shell *shell)
{
	char	*name;

	name = malloc(1);
	name[0] = 0;
	(*i)++;
	if (!str[(*i) + 1])
	{
		free(name);
		return (ft_strdup("$"));
	}
	while (str[(*i) + 1] && str[(*i)] != ' ' \
	&& str[(*i)] != '\\' && str[(*i)] != ONE)
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
