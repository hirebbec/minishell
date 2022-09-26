/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:22:05 by hirebbec          #+#    #+#             */
/*   Updated: 2022/05/17 19:34:00 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*new_element(char *name, char	*value)
{
	t_env	*new;

	new = malloc(sizeof(t_env));
	if (new == NULL)
		exit(1);
	new->name = name;
	new->value = value;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	add_back_element(t_env **env, char *name, char	*value)
{
	t_env	*new;

	new = new_element(name, value);
	ft_last_element(env);
	new->prev = (*env);
	(*env)->next = new;
}

void	ft_first_element(t_env **env)
{
	while ((*env)->prev)
		*env = (*env)->prev;
}

void	ft_last_element(t_env **env)
{
	while ((*env)->next)
		*env = (*env)->next;
}

void	ft_tmp2(t_env **env);
void	ft_tmp(t_env **env);
void	*last(t_env **env);

void	delete_elem(t_env **env)
{
	t_env	*next;
	t_env	*prev;

	if (!env)
		return ;
	if (list_len(*env) == 1)
		(*env) = last(env);
	else
	{
		if ((*env)->prev == NULL)
			ft_tmp(env);
		else if ((*env)->next == NULL)
			ft_tmp2(env);
		else
		{
			(*env) = (*env)->prev;
			next = (*env)->next;
			prev = (*env)->next->next;
			free_elem(next);
			(*env)->next = prev;
			prev->prev = (*env);
		}
	}
}
