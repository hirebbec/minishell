/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:12:09 by hirebbec          #+#    #+#             */
/*   Updated: 2022/05/13 19:08:24 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_elem(t_env *elem)
{
	free(elem->name);
	free(elem->value);
	free(elem);
}

void	ft_tmp(t_env **env)
{
	t_env	*prev;

	(*env) = (*env)->next;
	prev = (*env)->prev;
	free_elem(prev);
	(*env)->prev = NULL;
}

void	ft_tmp2(t_env **env)
{
	t_env	*next;

	(*env) = (*env)->prev;
	next = (*env)->next;
	free_elem(next);
	(*env)->next = NULL;
}

void	ft_tmp3(char *str)
{
	ft_printf(2, GREEN "MiniShell: " WHITE);
	ft_printf(2, "%s: command not found\n", str);
	g_status = 127;
}

void	ft_tmp4(char *str)
{
	ft_printf(2, GREEN "MiniShell: " WHITE);
	ft_printf(2, "%s: command not found\n", str);
	exit(127);
}
