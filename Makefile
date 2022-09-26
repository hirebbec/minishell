# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/08 20:59:52 by hirebbec          #+#    #+#              #
#    Updated: 2022/05/15 20:10:37 by hirebbec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

SRCS_F		=	src/ft_find.c src/init.c build/ft_pwd.c build/ft_echo.c build/ft_env.c \
				src/create_list.c build/ft_unset.c src/utils_for_list.c src/free.c \
				parth/close_check.c parth/ft_parth.c src/cmd_list.c build/ft_export.c \
				signal/signal.c build/ft_cd.c build/ft_exit.c shell_cmds/shell_cmds.c parth/redirect.c \
				src/file_list.c parth/pipe.c parth/true_cmd.c parth/convert.c signal/lol.c src/call_cmds.c \
				parth/tmp.c build/tmp.c src/tmp.c  src/tmp_2.c src/tmp_3.c parth/tmp_2.c parth/tmp_3.c \
				parth/tmp_4.c get_next_line/get_next_line.c bonus/star_bonus.c bonus/utils.c \
				src/alph_env.c bonus/and_or.c bonus/tmp.c bonus/tmp2.c

SRCS_D		=	utils/

INCLUDE		=	-I./libft/ -I./utils -I./printf

OBJS		=	$(SRCS:.c=.o)

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra

SRCS		=	$(addprefix $(SRCS_D),$(SRCS_F))

LIBFT		=	./libft/libft.a

PRINTF		=	./printf/ft_printf.h
LIB_PRINTF	=	./printf/libftprintf.a

$(NAME)		:	$(OBJS) main.c 
				$(MAKE) -C $(dir $(LIBFT))
				$(MAKE) -C $(dir $(PRINTF))
				$(CC) $(CFLAGS) $(INCLUDE) $(LIBFT) $(LIB_PRINTF) $(OBJS) main.c  -lreadline -L ~/.brew/opt/readline/lib -o $(NAME)


all		:	$(NAME) libft/libft.h

%.o		:	%.c
			$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean	:	
			$(MAKE) clean -C $(dir $(LIBFT))
			$(MAKE) clean -C $(dir $(PRINTF))
			rm -f $(OBJS)

fclean	:	clean
			$(MAKE) fclean -C $(dir $(PRINTF))
			$(MAKE) fclean -C $(dir $(LIBFT))
			rm -rf $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re bonus

-include	$(OBJS:.o=.d)