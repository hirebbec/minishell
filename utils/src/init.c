/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:25:28 by hirebbec          #+#    #+#             */
/*   Updated: 2022/05/15 20:38:18 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*get_envp(char	**envp)
{
	char	*tmp;
	char	*name;
	char	*value;
	t_env	*env;
	int		i;

	i = 0;
	while (envp[i])
	{
		tmp = ft_strchr(envp[i], (int) '=');
		name = ft_substr(envp[i], 0, ft_strlen(envp[i]) - ft_strlen(tmp));
		value = ft_substr(envp[i], ft_strlen(envp[i]) - ft_strlen(tmp) + 1, \
		ft_strlen(tmp) - 1);
		if (i == 0)
			env = new_element(ft_strdup(name), ft_strdup(value));
		else
			add_back_element(&env, ft_strdup(name), ft_strdup(value));
		free(name);
		free(value);
		i++;
	}
	return (env);
}

void	get_paths(t_shell *shell)
{
	ft_first_element(&shell->env);
	while (shell->env->next)
	{
		if (!ft_strncmp(shell->env->name, "PATH", 4) \
		&& ft_strlen(shell->env->name) == 4)
		{
			shell->paths = ft_split(shell->env->value, ':');
			return ;
		}
		shell->env = shell->env->next;
	}
	if (!ft_strncmp(shell->env->name, "PATH", 4) \
	&& ft_strlen(shell->env->name) == 4)
	{
		shell->paths = ft_split(shell->env->value, ':');
		return ;
	}
	shell->paths = NULL;
}

void	ft_tmp10(t_shell *shell)
{
	if (!ft_strncmp(shell->env->name, "SHLVL", 5) \
	&& ft_strlen(shell->env->name) == 5)
	{
		free(shell->env->value);
		shell->env->value = ft_itoa(ft_atoi(shell->env->value) + 1);
	}
	else if (!ft_strncmp(shell->env->name, "_", 1) \
	&& ft_strlen(shell->env->name) == 1)
	{
		free(shell->env->value);
		shell->env->value = ft_strdup("/usr/bin/env");
	}
}

void	env_init(t_shell *shell)
{
	ft_first_element(&shell->env);
	while (shell->env->next)
	{
		if (!ft_strncmp(shell->env->name, "SHLVL", 5) \
		&& ft_strlen(shell->env->name) == 5)
		{
			free(shell->env->value);
			shell->env->value = ft_itoa(ft_atoi(shell->env->value) + 1);
		}
		else if (!ft_strncmp(shell->env->name, "_", 1) \
		&& ft_strlen(shell->env->name) == 1)
		{
			free(shell->env->value);
			shell->env->value = ft_strdup("/usr/bin/env");
		}
		shell->env = shell->env->next;
	}
	ft_tmp10(shell);
}

void	init(t_shell *shell, char **envp)
{
	signal_main();
	shell->env = get_envp(envp);
	shell->export = get_envp(envp);
	get_paths(shell);
	env_init(shell);
	shell->std_in = dup(STDIN_FILENO);
	shell->std_out = dup(STDOUT_FILENO);
	shell->cd_flag = 0;
}
