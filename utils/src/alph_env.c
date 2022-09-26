/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alph_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:46:00 by hirebbec          #+#    #+#             */
/*   Updated: 2022/05/17 19:39:13 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*get_envp(char	**envp);

void	print_smallest(t_env **env)
{
	t_env	*min;

	min = (*env);
	while ((*env)->next)
	{
		if (ft_stralp(min->name, (*env)->name) == 2)
			min = (*env);
		(*env) = (*env)->next;
	}
	if (ft_stralp(min->name, (*env)->name) == 2)
	{
		min = (*env);
		(*env) = (*env)->prev;
	}
	printf("declare -x %s=\"%s\"\n", min->name, min->value);
	delete_elem(&min);
}

void	update(t_shell *shell)
{
	ft_first_element(&shell->export);
	while (shell->export)
		delete_elem(&shell->export);
	ft_first_element(&shell->env);
	shell->export = new_element(ft_strdup(shell->env->name), \
	ft_strdup(shell->env->value));
	while (shell->env->next)
	{
		shell->env = shell->env->next;
		add_back_element(&shell->export, \
		ft_strdup(shell->env->name), ft_strdup(shell->env->value));
	}
	add_back_element(&shell->export, \
	ft_strdup(shell->env->name), ft_strdup(shell->env->value));
}

int	alph_env(t_shell *shell)
{
	update(shell);
	ft_first_element(&shell->export);
	while (shell->export->next)
	{
		print_smallest(&shell->export);
		ft_first_element(&shell->export);
	}
	return (0);
}

void	*last(t_env **env)
{
	free((*env)->name);
	free((*env)->value);
	free((*env));
	return (NULL);
}
