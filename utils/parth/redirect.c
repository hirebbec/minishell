/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 18:33:45 by hirebbec          #+#    #+#             */
/*   Updated: 2022/05/20 15:00:35 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		red_tmp(void);
int		red_tmp2(void);
int		red_tmp3(char *name, char *before, char *after);
char	*red_tmp4(t_shell *shell, int i, char **name, char *before);
void	red_tmp5(int *start, int *i, t_shell *shell, char **name);
void	red_tmp6(int *i, int *start, t_shell *shell, char **name);
void	red_tmp7(int *i, int *start, t_shell *shell, char **name);
void	red_tmp8(int *i, int *start, t_shell *shell, char **name);
void	red_tmp9(int *status, int *i);
int		red_tmp10(void);

int	redirect_infile(int *i, t_shell *shell, int status, int start)
{
	char	*name;
	char	*before;
	char	*after;

	(*i)++;
	if (!shell->call->cmd[(*i)])
		return (red_tmp());
	if (shell->call->cmd[(*i)] == '<')
	{
		red_tmp9(&status, i);
		if (shell->call->cmd[(*i)] == '<')
			return (red_tmp2());
	}
	while (shell->call->cmd[(*i)] == ' ')
		(*i)++;
	if (!shell->call->cmd[(*i)])
		return (red_tmp());
	red_tmp8(i, &start, shell, &name);
	if (!shell->call->file)
		shell->call->file = new_file(ft_strdup(name), status, 0);
	else
		add_back_file(&shell->call->file, ft_strdup(name), status, 0);
	before = ft_substr(shell->call->cmd, 0, start - status - 1);
	after = red_tmp4(shell, *i, &name, before);
	return (red_tmp3(name, before, after));
}

int	redirect_outfile(int *i, t_shell *shell, int status, int start)
{
	char	*name;
	char	*before;
	char	*after;

	(*i)++;
	if (!shell->call->cmd[(*i)])
		return (red_tmp());
	if (shell->call->cmd[(*i)] == '>')
	{
		red_tmp9(&status, i);
		if (shell->call->cmd[(*i)] == '>')
			return (red_tmp10());
	}
	while (shell->call->cmd[(*i)] == ' ')
		(*i)++;
	if (!shell->call->cmd[(*i)])
		return (red_tmp());
	red_tmp8(i, &start, shell, &name);
	if (!shell->call->file)
		shell->call->file = new_file(ft_strdup(name), status, 1);
	else
		add_back_file(&shell->call->file, ft_strdup(name), status, 1);
	before = ft_substr(shell->call->cmd, 0, start - status - 1);
	after = red_tmp4(shell, *i, &name, before);
	return (red_tmp3(name, before, after));
}

void	two_case(int *i, char *cmd)
{
	(*i)++;
	while (cmd[(*i)] && cmd[(*i)] != TWO)
		(*i)++;
	(*i)++;
}

void	one_case(int *i, char *cmd)
{
	(*i)++;
	while (cmd[(*i)] && cmd[(*i)] != ONE)
		(*i)++;
	(*i)++;
}

int		redic_tmp(t_shell *shell, int *i);
int		redic_tmp2(t_shell *shell, int *i);
void	redic_tmp3(t_shell *shell, int *i);
void	redic_tmp4(t_shell *shell, int *i);

int	redirect(t_shell *shell, int i)
{
	ft_first_call(&shell->call);
	while (shell->call->next)
	{
		while (shell->call->cmd[i])
		{
			if (shell->call->cmd[i] == '>')
			{
				if (!redic_tmp2(shell, &i))
					return (-1);
			}
			else if (shell->call->cmd[i] == '<')
			{
				if (!redic_tmp(shell, &i))
					return (-1);
			}
			else
				redic_tmp4(shell, &i);
		}
		redic_tmp3(shell, &i);
	}
	return (1);
}
