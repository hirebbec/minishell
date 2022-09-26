/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_for_write.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:59:00 by hirebbec          #+#    #+#             */
/*   Updated: 2022/04/08 20:59:01 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_struct	ft_putchar(t_struct ptf, char c)
{
	write(ptf.fd, &c, 1);
	ptf.count++;
	return (ptf);
}

t_struct	ft_putnbr(t_struct ptf, unsigned int n)
{
	unsigned int	x;

	x = 0;
	if (n == 4294967295)
	{
		write(ptf.fd, "4294967295", 10);
		ptf.count += 10;
		return (ptf);
	}
	if (ptf.accuracy == 0 && n == 0)
		return (ptf);
	if (n >= 10)
	{
		ptf = ft_putnbr(ptf, n / 10);
		x = n % 10 + '0';
		ptf = ft_putchar(ptf, x);
	}
	else
	{
		x = n + '0';
		ptf = ft_putchar(ptf, x);
	}
	return (ptf);
}

static	unsigned int	mini(unsigned int n, unsigned int x, unsigned int t)
{
	if (n < 10)
		x = n + '0';
	else
		x = n + 'a' - 10 + t;
	return (x);
}

t_struct	ft_putnbr16(t_struct ptf, unsigned int n, int type)
{
	unsigned int	x;
	unsigned int	t;

	t = 0;
	if (type == 'X')
		t = -32;
	x = 0;
	if (ptf.accuracy == 0 && n == 0)
		return (ptf);
	if (n >= 16)
	{
		ptf = ft_putnbr16(ptf, n / 16, type);
		x = n % 16;
		if (x < 10)
			x = x + '0';
		else
			x = x + 'a' - 10 + t;
	}
	else
		x = mini(n, x, t);
	ptf = ft_putchar(ptf, x);
	return (ptf);
}

t_struct	ft_putnbrlong(t_struct ptf, unsigned long n)
{
	unsigned int	x;
	unsigned int	t;

	t = 0;
	x = 0;
	if (ptf.accuracy == 0 && n == 0)
		return (ptf);
	if (n >= 16)
	{
		ptf = ft_putnbrlong(ptf, n / 16);
		x = n % 16;
		if (x < 10)
			x = x + '0';
		else
			x = x + 'a' - 10 + t;
	}
	else
	{
		if (n < 10)
			x = n + '0';
		else
			x = n + 'a' - 10 + t;
	}
	ptf = ft_putchar(ptf, x);
	return (ptf);
}
