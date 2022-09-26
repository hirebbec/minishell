/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:58:42 by hirebbec          #+#    #+#             */
/*   Updated: 2022/04/08 20:58:43 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	t_struct	parsing_error(t_struct ptf, char *str)
{
	while (str[ptf.i])
	{
		if (str[ptf.i] == '%')
		{
			ptf.i++;
			ptf = second_init_struct(ptf);
			ptf = ft_space(ptf, str);
			ptf = flags(ptf, str);
			ptf = ft_space(ptf, str);
			if ((ptf.flag == '-') && (str[ptf.i] == '0'))
				ptf.i++;
			ptf = width(ptf, str);
			ptf = ft_space(ptf, str);
			if (str[ptf.i] == '.')
				ptf = accuracy(ptf, str);
			ptf = ft_space(ptf, str);
			if (ptf.count == -1)
				return (ptf);
		}
		ptf.i++;
	}
	return (ptf);
}

int	ft_printf(int fd, const char *s, ...)
{
	t_struct		ptf;
	char			*str;

	str = (char *)s;
	va_start(ptf.ap, s);
	ptf.flag = 1;
	ptf.fd = fd;
	ptf = first_init_struct(ptf);
	ptf = parsing_error(ptf, str);
	va_end(ptf.ap);
	if (ptf.count == -1)
		return (ptf.count);
	va_start(ptf.ap, s);
	ptf = first_init_struct(ptf);
	ptf = parsing(ptf, str);
	va_end(ptf.ap);
	return (ptf.count);
}
