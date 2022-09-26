/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:54:23 by hirebbec          #+#    #+#             */
/*   Updated: 2022/05/18 21:23:45 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	change_oldpwd(t_env *env, char *new_pwd);
void	change_pwd(t_env *env, char *new_pwd);

int	cd_tmp1(t_env **env, char **pwd, char **oldpwd)
{
	(*pwd) = (*env)->value;
	change_oldpwd((*env), (*oldpwd));
	free((*oldpwd));
	chdir(*pwd);
	(*oldpwd) = getcwd(NULL, 1024);
	change_pwd((*env), (*oldpwd));
	free(*oldpwd);
	return (0);
}

int	cd_tmp2(t_env **env, char **pwd, char **oldpwd)
{
	free(*oldpwd);
	(*pwd) = (*env)->value;
	*oldpwd = getcwd(NULL, 1024);
	change_oldpwd((*env), (*oldpwd));
	free(*oldpwd);
	chdir(*pwd);
	*oldpwd = getcwd(NULL, 1024);
	change_pwd((*env), (*oldpwd));
	free(*oldpwd);
	return (0);
}

int	cd_tmp(char *oldpwd)
{
	free(oldpwd);
	ft_printf(2, GREEN "MiniShell: " WHITE);
	ft_printf(2, "cd: HOME not set\n");
	return (-1);
}

int	cd_tmp3(t_env **env, char **oldpwd)
{
	change_oldpwd((*env), (*oldpwd));
	free((*oldpwd));
	(*oldpwd) = getcwd(NULL, 1024);
	change_pwd((*env), (*oldpwd));
	free((*oldpwd));
	return (0);
}

int	cd_tmp4(t_env **env, char **oldpwd, char **path)
{
	change_oldpwd((*env), (*oldpwd));
	free((*oldpwd));
	(*oldpwd) = getcwd(NULL, 1024);
	change_pwd((*env), (*oldpwd));
	free((*oldpwd));
	free((*path));
	return (0);
}
