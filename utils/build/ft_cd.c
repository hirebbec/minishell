/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:16:39 by hirebbec          #+#    #+#             */
/*   Updated: 2022/05/18 21:36:34 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	change_pwd(t_env *env, char *new_pwd)
{
	ft_first_element(&env);
	while (env->next)
	{
		if (!strncmp("PWD", env->name, 3) && ft_strlen(env->name) == 3)
		{
			free(env->value);
			env->value = ft_strdup(new_pwd);
			return ;
		}
		env = env->next;
	}
	if (!strncmp("PWD", env->name, 3) && ft_strlen(env->name) == 3)
	{
		free(env->value);
		env->value = ft_strdup(new_pwd);
		return ;
	}
}

void	change_oldpwd(t_env *env, char *new_pwd)
{
	ft_first_element(&env);
	while (env->next)
	{
		if (!strncmp("OLDPWD", env->name, 6) && ft_strlen(env->name) == 6)
		{
			free(env->value);
			env->value = ft_strdup(new_pwd);
			return ;
		}
		env = env->next;
	}
	if (!strncmp("OLDPWD", env->name, 6) && ft_strlen(env->name) == 6)
	{
		free(env->value);
		env->value = ft_strdup(new_pwd);
		return ;
	}
}

int	minus_case(t_env *env, char *oldpwd)
{
	char	*pwd;

	ft_first_element(&env);
	while (env->next)
	{
		if (!strncmp("OLDPWD", env->name, 6) && ft_strlen(env->name) == 6)
		{
			pwd = ft_strdup(env->value);
			ft_first_element(&env);
			break ;
		}
		env = env->next;
	}
	if (!strncmp("OLDPWD", env->name, 6) && ft_strlen(env->name) == 6)
		pwd = ft_strdup(env->value);
	change_oldpwd(env, oldpwd);
	chdir(pwd);
	change_pwd(env, pwd);
	free(pwd);
	free(oldpwd);
	return (1);
}

int		cd_tmp1(t_env **env, char **pwd, char **oldpwd);
int		cd_tmp2(t_env **env, char **pwd, char **oldpwd);
int		cd_tmp(char *oldpwd);
int		cd_tmp3(t_env **env, char **oldpwd);
int		cd_tmp4(t_env **env, char **oldpwd, char **path);
void	cd_tmp6(char **pwd, char **path, char *c);
void	cd_tmp7(char **oldpwd, t_env **env);

int	cd_tmp5(char *path, char *msg, char *oldpwd)
{
	free(path);
	free(oldpwd);
	ft_printf(2, GREEN "MiniShell: " WHITE);
	ft_printf(2, "cd: %s: No such file or directory\n", msg);
	g_status = 0;
	return (-1);
}

int	ft_cd(char **c, t_env *env)
{
	char	*path;
	char	*pwd;
	char	*oldpwd;

	cd_tmp7(&oldpwd, &env);
	if (c[1] == NULL || (!ft_strncmp(c[1], "~", 1) && ft_strlen(c[1]) == 1))
	{
		while (env->next)
		{
			if (!strncmp("HOME", env->name, 4) && ft_strlen(env->name) == 4)
				return (cd_tmp1(&env, &pwd, &oldpwd));
			env = env->next;
		}
		if (!strncmp("HOME", env->name, 4) && ft_strlen(env->name) == 4)
			return (cd_tmp2(&env, &pwd, &oldpwd));
		return (cd_tmp(oldpwd));
	}
	else if (!ft_strncmp(c[1], "-", 1) && ft_strlen(c[1]) == 1)
		return (minus_case(env, oldpwd));
	else if (chdir(c[1]) == 0)
		return (cd_tmp3(&env, &oldpwd));
	cd_tmp6(&pwd, &path, c[1]);
	if (chdir(path) == 0)
		return (cd_tmp4(&env, &oldpwd, &path));
	return (cd_tmp5(path, c[1], oldpwd));
}
