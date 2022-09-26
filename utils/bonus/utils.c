/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:05:04 by hirebbec          #+#    #+#             */
/*   Updated: 2022/05/13 20:54:14 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		and_tmp(void);
void	add_after_and(char *cmd, t_shell *shell);
void	delete_this(t_shell *shell);

int	ft_it(t_star *star, char *str)
{
	if (!(ft_strncmp(star->before, str, ft_strlen(star->before))))
	{
		if (!(ft_rev_strncmp(star->after, str, ft_strlen(star->after))))
			return (1);
		return (0);
	}
	return (0);
}

void	ft_bonus(t_star *star, char **output, char **input, char **ls)
{
	int	i;

	i = 0;
	free(*output);
	(*output) = ft_substr((*input), 0, star->start);
	while (ls[i])
	{
		if (ft_it(star, ls[i]))
		{
			(*output) = ft_strjoin_free((*output), " ");
			(*output) = ft_strjoin_free((*output), ls[i]);
			(*output) = ft_substr_free((*output), 0, ft_strlen((*output)) - 1);
		}
		i++;
	}
	(*output) = ft_strjoin_full_free((*output), ft_substr((*input), \
	star->end, ft_strlen((*input)) - star->end));
	free((*input));
	(*input) = ft_strdup((*output));
}

int	or_tmp(void)
{
	ft_printf(2, GREEN "MiniShell: " \
	WHITE "syntax error unexpected token `||'\n");
	return (-1);
}

void	share_call_and(t_shell *shell, int i)
{
	char	*before;
	char	*after;

	before = ft_substr(shell->call->cmd, 0, i - 1);
	after = ft_substr(shell->call->cmd, i + 1, \
	ft_strlen(shell->call->cmd) - i);
	add_after_and(after, shell);
	add_after_and(before, shell);
	shell->call->next->status = 0;
	delete_this(shell);
}

int	and_case(t_shell *shell, int *i)
{
	int	j;

	(*i)++;
	j = (*i) + 1;
	while (shell->call->cmd[j] == ' ')
		j++;
	if (shell->call->cmd[j] == '\0')
		return (and_tmp());
	j = (*i) - 1;
	while (j >= 0)
	{
		if (shell->call->cmd[j] != ' ' && shell->call->cmd[j] != '&')
			break ;
		j--;
	}
	if (j == -1)
	{
		ft_printf(2, GREEN "MiniShell: " \
		WHITE "syntax error unexpected token `&&'\n");
		ft_first_call(&shell->call);
		return (-1);
	}
	share_call_and(shell, *i);
	return (1);
}
