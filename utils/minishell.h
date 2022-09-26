/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:19:18 by hirebbec          #+#    #+#             */
/*   Updated: 2022/05/20 19:43:30 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include "./../libft/libft.h"
# include "./../printf/ft_printf.h"
# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

# define GREEN			"\033[0;32m"
# define YELLOW			"\033[0;33m"
# define WHITE			"\033[0;37m"
# define BLUE			"\033[0;34m"
# define RED			"\033[0;31m"
# define ONE			39
# define TWO			34
# define THREE			92
# define BUFFER_SIZE	100

int		g_status;

typedef struct s_env
{
	struct s_env		*next;
	struct s_env		*prev;
	char				*name;
	char				*value;
}	t_env;

typedef struct s_file
{
	char				*name;
	int					status;
	int					type;
	int					fd[2];
	struct s_file		*next;
	struct s_file		*prev;
}	t_file;

typedef struct s_pipe
{
	int		fd[2];
}	t_pipe;

typedef struct s_call
{
	struct s_call		*next;
	struct s_call		*prev;
	char				*cmd;
	struct s_file		*file;
	struct s_pipe		*pipe_out;
	struct s_pipe		*pipe_in;
	int					status;
}	t_call;

typedef struct s_cmd
{
	struct s_cmd		*next;
	struct s_cmd		*prev;
	char				*tr_cmd;
}	t_cmd;

typedef struct s_star
{
	int		start;
	int		end;
	char	*before;
	char	*after;
}	t_star;

typedef struct s_shell
{
	struct s_env		*env;
	struct s_env		*export;
	struct s_call		*call;
	struct s_cmd		*cmd;
	char				**paths;
	int					std_in;
	int					std_out;
	int					cd_flag;
	char				*oldpwd;
}	t_shell;
//
//BUILD
//
int		ft_pwd(void);
int		ft_echo(char **cmds, int i);
int		ft_env(t_shell *shell, char **cmds);
int		ft_unset(t_shell *shell, char	**cmds);
int		ft_export(t_shell *shell, char **cmds, int i, char *tmp);
int		ft_cd(char **cmds, t_env *env);
int		ft_exit(char **cmds);
//
//UTILS_FUNC
//
int		ft_find(t_shell *shell);
void	init(t_shell *shell, char **envp);
//
//FOR_LIST
//
void	ft_first_element(t_env **env);
void	add_back_element(t_env **env, char *name, char	*value);
t_env	*new_element(char *name, char *value);
void	ft_last_element(t_env **env);
int		list_len(t_env *env);
void	free_elem(t_env *elem);
void	delete_elem(t_env **env);
//////////////////
void	ft_last_call(t_call **call);
void	ft_first_call(t_call **call);
void	add_back_call(t_call **call, char *cmd);
t_call	*new_call(char *cmd);
void	delete_call(t_call **call);
//////////////////
void	add_back_cmd(t_cmd **cmd, char *comd);
t_cmd	*new_cmd(char *cmd);
void	ft_last_cmd(t_cmd **cmd);
void	ft_first_cmd(t_cmd **cmd);
//////////////////
t_file	*new_file(char *name, int status, int type);
void	ft_first_file(t_file **file);
void	ft_last_file(t_file **file);
void	add_back_file(t_file **file, char *name, int status, int type);
t_pipe	*new_pipe(int fd[2]);
//
//PARTH
//
char	*close_check(char *input);
t_call	*ft_parth(char *input, t_shell *shell);
int		check_unset_export(char	*arg);
int		redirect(t_shell *shell, int i);
int		spaces(char *input);
char	**true_cmds(char *line);
char	**ft_convert(char **cmds, t_shell *shell);
char	*find_value(t_env *env, char *name);
char	*dollar(int *i, char *str, t_shell *shell);
void	two_cs(char *str, int *i);
void	one_cs(char *str, int *i);
//
//SIGNAL
//
void	signal_main(void);
void	sig_ctrl_d_main(int sig);
void	here_doc_signal(void);
void	status_child(int pid);
void	sig_ctrl_c_main(int sig);
void	signal_child_cat(void);
//
//FOR_SHELL_CMDS
//
void	get_paths(t_shell *shell);
int		shell_cmd_try(char **cmds, t_shell *shell);
//
//PIPE
//
int		ft_pipe(t_shell *shell);
char	*get_next_line(int fd);
///
///BONUS
///
char	*star(char *input, t_shell *shell, int i);
void	ft_bonus(t_star *star, char **output, char **input, char **ls);
int		alph_env(t_shell *shell);
void	go_pwd(char **input, t_shell *shell, int i, char **cmds);
#endif