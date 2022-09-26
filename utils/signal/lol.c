/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lol.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:10:27 by hirebbec          #+#    #+#             */
/*   Updated: 2022/05/20 19:48:36 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	sig_lol(int sig);
void	sig_kek(int sig);

void	sig_ctrl_c_main(int sig)
{
	(void)sig;
	rl_on_new_line();
	rl_redisplay();
	ft_putstr_fd("  \n", 0);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	signal_child_cat(void)
{
	signal(SIGTERM, SIG_IGN);
	signal(SIGQUIT, sig_kek);
	signal(SIGINT, sig_lol);
}
