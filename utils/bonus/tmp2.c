/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 20:10:12 by hirebbec          #+#    #+#             */
/*   Updated: 2022/05/18 21:04:01 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_new_input(char *input, int i)
{
	char	*new;
	char	*before;
	char	*after;

	i = 0;
	while (input[i] && input[i] != '/')
		i++;
	after = ft_substr(input, i + 1, ft_strlen(input) - i);
	while (i > -1 && input[i] != ' ')
		i--;
	before = ft_substr(input, 0, i + 1);
	new = ft_strjoin_full_free(before, after);
	free(input);
	return (new);
}

void	return_pwd(t_shell *shell)
{
	char	**cmds;

	cmds = malloc(sizeof(char *) * 3);
	cmds[0] = "cd";
	cmds[1] = ft_strdup(shell->oldpwd);
	cmds[2] = NULL;
	free(cmds[1]);
	ft_cd(cmds, shell->env);
	free(cmds);
}
