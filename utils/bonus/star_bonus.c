/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   star_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 19:10:57 by hirebbec          #+#    #+#             */
/*   Updated: 2022/05/15 21:14:00 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	skip(char *input, int *i)
{
	if (input[(*i)] == ONE)
	{
		(*i)++;
		while (input[(*i)] && input[(*i)] != ONE)
			(*i)++;
		(*i)++;
	}
	else if (input[(*i)] == TWO)
	{
		(*i)++;
		while (input[(*i)] && input[(*i)] != TWO)
			(*i)++;
		(*i)++;
	}
}

int	get_word(int *i, t_star *star, char *input)
{
	int		j;

	j = (*i) + 1;
	star->after = malloc(1);
	star->before = malloc(1);
	while (input[j] && input[j] != ' ')
	{
		star->after = ft_charjoin_free(star->after, input[j]);
		j++;
	}
	star->end = j;
	j = (*i) - 1;
	while (j > -1 && input[j] != ' ')
	{
		star->before = ft_joinchar_free(star->before, input[j]);
		j--;
	}
	star->start = j;
	return (1);
}

int	star_check(char *input, t_star *star)
{
	int	i ;

	i = 0;
	while (input[i])
	{
		if (input[i] == ONE || input[i] == TWO)
			skip(input, &i);
		else if (input[i] == '*')
			return (get_word(&i, star, input));
		else
			i++;
	}
	return (0);
}

void	return_fd(t_shell *shell);

char	**get_ls(int pid, char *line)
{
	int		fd[2];
	char	*arg[2];
	char	**ls;

	ls = malloc(sizeof(char *));
	ls[0] = NULL;
	arg[0] = "ls";
	arg[1] = NULL;
	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		dup2(fd[1], 1);
		close(fd[0]);
		execve("/bin/ls", arg, NULL);
	}
	wait(NULL);
	close(fd[1]);
	line = get_next_line(fd[0]);
	while (ft_strlen(line) > 0)
	{
		ls = add_string(ls, line);
		line = get_next_line(fd[0]);
	}
	return (ls);
}

void	return_pwd(char *pwd, t_shell *shell);

char	*star(char *input, t_shell *shell, int i)
{
	char	*output;
	char	**ls;
	t_star	star;

	output = malloc(1);
	go_pwd(&input, shell, 0, NULL);
	ls = get_ls(0, "lol");
	while (star_check(input, &star))
	{
		ft_bonus(&star, &output, &input, ls);
		i = 1;
	}
	if (i == 0)
	{
		free(output);
		free_mat(ls);
		return (input);
	}
	free(input);
	free(star.after);
	free(star.before);
	free_mat(ls);
	return (output);
}
