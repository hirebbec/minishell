# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/08 20:59:29 by hirebbec          #+#    #+#              #
#    Updated: 2022/05/13 18:07:20 by hirebbec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	=	ft_atoi.c		ft_bzero.c		ft_calloc.c\
		ft_isalnum.c	ft_isalpha.c	ft_isascii.c\
		ft_isdigit.c	ft_isprint.c	ft_memchr.c\
		ft_memcmp.c		ft_toupper.c	ft_memcpy.c\
		ft_memmove.c	ft_memset.c		ft_itoa.c\
		ft_putchar_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c\
		ft_putstr_fd.c	ft_strchr.c		ft_strdup.c\
		ft_striteri.c	ft_strjoin.c	ft_strlcat.c\
		ft_strlcpy.c	ft_strlen.c		ft_strmapi.c\
		ft_strncmp.c	ft_strnstr.c	ft_strrchr.c\
		ft_strtrim.c	ft_substr.c		ft_tolower.c\
		ft_split.c		ft_matrix_len.c	ft_charjoin.c \
		ft_len_dif.c	add_string.c	free_mat.c	\
		ft_num_dup.c	ft_stralp.c
FILES_BONUS =	ft_lstnew_bonus.c		ft_lstadd_front_bonus.c		ft_lstsize_bonus.c\
				ft_lstlast_bonus.c		ft_lstadd_back_bonus.c		ft_lstdelone_bonus.c\
				ft_lstclear_bonus.c		ft_lstiter_bonus.c			ft_lstmap_bonus.c
OBJ	= ${SRC:.c=.o}
OBJ_BONUS	=	${FILES_BONUS:.c=.o}
NAME	= libft.a
CC	= gcc
FLAGS	= -Wall -Werror -Wextra
HEADER	= libft.h
LIBC = ar rc
LIBR = ranlib
RM	= rm -f

.c.o:	${HEADER}
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I ${HEADER}

${NAME}: ${OBJ} ${HEADER}
	${LIBC} ${NAME} ${OBJ}
	${LIBR} ${NAME}

all: ${NAME}

bonus:		${OBJ_BONUS}
			${LIBC} ${NAME} ${OBJ_BONUS}

clean:
	${RM} ${OBJ} ${OBJ_BONUS}

fclean: clean
	${RM} ${NAME} ${OBJ_BONUS}

re: fclean all

.PHONY: .c.o all clean fclean re 