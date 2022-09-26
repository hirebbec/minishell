/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_unsigned.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:58:37 by hirebbec          #+#    #+#             */
/*   Updated: 2022/04/08 20:58:39 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	t_struct	ft_for_else(t_struct ptf, unsigned int nb)
{
	if (nb > 0)
	{
		while (ptf.accuracy > ft_strlen_nb(nb))
		{
			ptf = ft_putchar(ptf, '0');
			ptf.accuracy--;
		}
		ptf = ft_putnbr(ptf, nb);
	}
	else if ((unsigned int)nb == 0)
	{
		while (ptf.accuracy--)
			ptf = ft_putchar(ptf, '0');
	}
	else
	{
		while (ptf.accuracy - ptf.width > 0)
		{
			ptf = ft_putchar(ptf, '0');
			ptf.accuracy--;
		}
		ptf = ft_putnbr(ptf, nb);
	}
	return (ptf);
}

static	t_struct	flag_minus(t_struct ptf, int nb)
{
	int	count;

	count = 0;
	if (ptf.width >= ptf.accuracy)
	{
		while (ptf.accuracy > ft_strlen_nb(nb))
		{
			ptf = ft_putchar(ptf, '0');
			ptf.accuracy--;
			count++;
		}
		ptf = ft_putnbr(ptf, nb);
		while ((ptf.width - ft_strlen_inint(nb) - count) > 0)
		{
			ptf = ft_putchar(ptf, ' ');
			ptf.width--;
		}
	}
	else
		ptf = ft_for_else(ptf, nb);
	return (ptf);
}

static	t_struct	flag_zero(t_struct ptf, int nb)
{
	if (ptf.accuracy < ft_strlen_nb(nb) && ptf.accuracy != -2 && nb >= 0)
		ptf.accuracy = ft_strlen_nb(nb);
	else if (ptf.accuracy < ft_strlen_nb(nb) && ptf.accuracy != -2 && nb < 0)
		ptf.accuracy = ft_strlen_inint(nb);
	if (ptf.width >= ptf.accuracy)
	{
		if (ptf.accuracy == -2)
		{
			while ((ptf.width-- > ft_strlen_inint(nb)) && ptf.width)
				ptf = ft_putchar(ptf, '0');
			ptf = ft_putnbr(ptf, nb);
		}
		else if (ptf.accuracy == 0 && nb != 0)
		{
			while (ptf.width - ft_strlen_inint(nb) > 0 && ptf.width-- > 0)
				ptf = ft_putchar(ptf, ' ');
			ptf = ft_putnbr(ptf, nb);
		}
		else
			ptf = about_u(ptf, nb);
	}
	else
		ptf = ft_for_else(ptf, nb);
	return (ptf);
}

static	t_struct	without_flag(t_struct ptf, int nb)
{
	if (ptf.accuracy < ft_strlen_nb(nb) && ptf.accuracy != -2 && nb >= 0)
		ptf.accuracy = ft_strlen_nb(nb);
	else if (ptf.accuracy < ft_strlen_nb(nb) && ptf.accuracy != -2 && nb < 0)
		ptf.accuracy = ft_strlen_inint(nb);
	if (ptf.accuracy == 0)
	{
		while (ptf.width - ft_strlen_inint(nb) > 0 && ptf.width-- > 0)
			ptf = ft_putchar(ptf, ' ');
		if (nb != 0)
			ptf = ft_putnbr(ptf, nb);
	}
	else if (ptf.width >= ptf.accuracy)
	{
		if (ptf.accuracy == -2)
		{
			while ((ptf.width > ft_strlen_inint(nb)) && ptf.width-- > 0)
				ptf = ft_putchar(ptf, ' ');
			ptf = ft_putnbr(ptf, nb);
		}
		else
			ptf = about_u(ptf, nb);
	}
	else
		ptf = ft_for_else(ptf, nb);
	return (ptf);
}

t_struct	for_unsigned(t_struct ptf)
{
	unsigned int	nb;

	nb = va_arg(ptf.ap, unsigned int);
	if (ptf.accuracy == 0 && nb == 0)
	{
		while (ptf.width--)
			ptf = ft_putchar(ptf, ' ');
	}
	else if (ptf.flag == '-')
	{
		if (ptf.accuracy < ft_strlen_nb(nb) && ptf.accuracy != 0)
			ptf.accuracy = ft_strlen_nb(nb);
		else if (ptf.accuracy < ft_strlen_nb(nb) && ptf.accuracy != 0)
			ptf.accuracy = ft_strlen_inint(nb);
		ptf = flag_minus(ptf, nb);
	}
	else if (ptf.flag == 0)
		ptf = flag_zero(ptf, nb);
	else
		ptf = without_flag(ptf, nb);
	return (ptf);
}
