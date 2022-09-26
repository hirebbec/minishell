/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:35:19 by hirebbec          #+#    #+#             */
/*   Updated: 2022/05/06 18:34:32 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_env(t_shell *shell, char **cmds)
{
	int	i;

	i = 0;
	if (cmds[1])
	{
		ft_printf(2, "env: %s: No such file or directory\n", cmds[1]);
		return (0);
	}
	ft_first_element(&shell->env);
	while (shell->env->next)
	{
		ft_printf(1, "%s=%s\n", shell->env->name, shell->env->value);
		shell->env = shell->env->next;
	}
	ft_printf(1, "%s=%s\n", shell->env->name, shell->env->value);
	return (0);
}

void	cd_tmp6(char **pwd, char **path, char *c)
{
	(*pwd) = getcwd(NULL, 1024);
	(*path) = ft_strjoin((*pwd), "/");
	(*path) = ft_strjoin_free((*path), c);
	free((*pwd));
}

void	cd_tmp7(char **oldpwd, t_env **env)
{
	(*oldpwd) = getcwd(NULL, 1024);
	ft_first_element(env);
}
