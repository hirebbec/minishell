/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:52:10 by hirebbec          #+#    #+#             */
/*   Updated: 2022/05/20 19:04:13 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_temp5(char **tmp, char *cmd, int *i);
int		ft_temp3(int *i, char **tmp, char *cmd);
void	ft_temp4(t_shell *shell, char **tmp, char *cmd);
void	ft_temp6(char *cmd, t_shell *shell, char **tmp);
int		tmp_tmp(char *tmp);

int	ft_export(t_shell *shell, char **cmds, int i, char *tmp)
{
	if (cmds[i])
		if (!ft_strrchr(cmds[i], (int) '='))
			return (0);
	while (cmds[i])
	{
		if (ft_strlen(ft_strrchr(cmds[i], (int) '=')) > 0)
		{
			tmp = ft_substr(cmds[i], 0, ft_len_dif(cmds[i], \
			ft_strrchr(cmds[i], (int) '=')));
			if (check_unset_export(tmp))
				return (ft_temp3(&i, &tmp, cmds[i]));
			else
			{
				ft_first_element(&shell->env);
				ft_temp4(shell, &tmp, cmds[i]);
				ft_temp6(cmds[i], shell, &tmp);
				i++;
			}
		}
		else
			ft_temp5(&tmp, cmds[i], &i);
	}
	if (!cmds[1])
		return (alph_env(shell));
	return (tmp_tmp(tmp));
}

void	ft_temp6(char *cmd, t_shell *shell, char **tmp)
{
	if (!strncmp((*tmp), shell->env->name, ft_strlen((*tmp))) \
	&& ft_strlen((*tmp)) == ft_strlen(shell->env->name))
	{
		free(shell->env->value);
		shell->env->value = \
		ft_strtrim(ft_strrchr(cmd, (int) '='), "=");
	}
	else
		add_back_element(&shell->env, ft_strdup(*tmp), \
		ft_strtrim(ft_strrchr(cmd, (int) '='), "="));
}

void	ft_temp4(t_shell *shell, char **tmp, char *cmd)
{
	while (shell->env->next)
	{
		if (!strncmp((*tmp), shell->env->name, ft_strlen((*tmp))) \
		&& ft_strlen((*tmp)) == ft_strlen(shell->env->name))
		{
			shell->env->value = \
			ft_strtrim(ft_strrchr(cmd, (int) '='), "=");
			break ;
		}
		else
			shell->env = shell->env->next;
	}
}

int	ft_temp3(int *i, char **tmp, char *cmd)
{
	ft_printf(2, GREEN "MiniShell: " WHITE);
	ft_printf(2, "export: `%s': not a valid identifier\n", cmd);
	free((*tmp));
	(*i)++;
	return (0);
}

void	ft_temp5(char **tmp, char *cmd, int *i)
{
	(*tmp) = cmd;
	if (check_unset_export((*tmp)))
	{
		ft_printf(2, GREEN "MiniShell: " WHITE);
		ft_printf(2, "export: `%s': not a valid identifier\n", cmd);
	}
	(*i)++;
}
