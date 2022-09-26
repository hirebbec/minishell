/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:18:47 by hirebbec          #+#    #+#             */
/*   Updated: 2022/05/20 18:59:34 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_unset_export(char	*arg)
{
	int	i;

	i = 0;
	if (!arg)
		return (0);
	if (arg[0] == '_' || (arg[0] >= 'A' && arg[0] <= 'Z') \
	|| (arg[0] >= 'a' && arg[0] <= 'z'))
		i++;
	else
		return (1);
	while (arg[i])
	{
		if (arg[i] == '_' || (arg[i] >= 'A' && arg[i] <= 'Z') \
		|| (arg[i] >= 'a' && arg[i] <= 'z') || (arg[i] >= '0' && arg[i] <= '9'))
			i++;
		else
			return (1);
	}
	return (0);
}

int	lol2(char *str)
{
	ft_printf(2, GREEN "MiniShell: " WHITE);
	ft_printf(2, "unset: `%s': not a valid identifier\n", str);
	return (1);
}

void	kek2(t_shell *shell, char *str)
{
	ft_first_element(&shell->env);
	while (shell->env->next)
	{
		if (!strncmp(str, shell->env->name, ft_strlen(str)) \
		&& ft_strlen(str) == ft_strlen(shell->env->name))
		{	
			delete_elem(&shell->env);
			break ;
		}
		else
			shell->env = shell->env->next;
	}
	if (!strncmp(str, shell->env->name, ft_strlen(str)) \
	&& ft_strlen(str) == ft_strlen(shell->env->name))
		delete_elem(&shell->env);
}

int	ft_unset(t_shell *shell, char	**cmds)
{
	int	i;

	i = 1;
	while (cmds[i])
	{
		if (check_unset_export(cmds[i]))
			i = i + lol2(cmds[i]);
		else
		{
			kek2(shell, cmds[i]);
			i++;
		}
	}
	g_status = 0;
	return (0);
}
