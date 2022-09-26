/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:58:48 by hirebbec          #+#    #+#             */
/*   Updated: 2022/04/08 20:58:49 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdarg.h>

typedef struct s_struct
{
	va_list	ap;
	int		flag;
	int		width;
	int		accuracy;
	int		i;
	int		count;
	int		minus;
	int		space;
	int		temp;
	int		temp_w;
	int		fd;
}				t_struct;

t_struct	ft_atoi_width(t_struct ptf, char *str);
t_struct	ft_atoi_accuracy(t_struct ptf, char *str);
int			ft_printf(int fd, const char *s, ...);
t_struct	ft_putnbr(t_struct ptf, unsigned int n);
t_struct	ft_putstr(t_struct ptf, char *s);
t_struct	parsing(t_struct ptf, char *str);
t_struct	first_init_struct(t_struct ptf);
int			ft_strlen_p(char *str);
t_struct	ft_putchar(t_struct ptf, char c);
t_struct	for_char(t_struct ptf, char c);
t_struct	second_init_struct(t_struct ptf);
t_struct	for_string(t_struct ptf);
t_struct	for_poiner(t_struct ptf);
t_struct	for_digit(t_struct ptf);
int			ft_strlen_nb(unsigned long nb);
int			ft_strlen_inint(unsigned int nb);
t_struct	for_unsigned(t_struct ptf);
t_struct	about_u(t_struct ptf, unsigned int nb);
t_struct	for_hexadecimal(t_struct ptf, int type);
int			ft_diglen16(unsigned int nb);
t_struct	ft_putnbr16(t_struct ptf, unsigned int n, int type);
t_struct	ft_putnbrlong(t_struct ptf, unsigned long n);
t_struct	about_x(t_struct ptf, int nb, int type);
t_struct	about_p(t_struct ptf, unsigned long nb);
t_struct	for_pointer(t_struct ptf);
int			ft_diglenlong(unsigned long nb);
t_struct	ft_space(t_struct ptf, char *str);
t_struct	accuracy(t_struct ptf, char *str);
t_struct	width(t_struct ptf, char *str);
t_struct	flags(t_struct ptf, char *str);
int			if_s(t_struct ptf, char *str);
t_struct	ft_for_else_sminus(t_struct ptf, char *str);
t_struct	ft_space_1(t_struct ptf, char *str);
t_struct	ft_endof_accaracy(t_struct ptf, char *str);
t_struct	ft_dig_min(t_struct ptf, int nb);
t_struct	ft_dig_zero(t_struct ptf, int nb);
t_struct	ft_point_2(t_struct ptf, unsigned long nb);

#endif
