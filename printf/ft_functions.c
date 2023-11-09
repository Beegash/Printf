/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iozmen <iozmen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:36:43 by iozmen            #+#    #+#             */
/*   Updated: 2023/11/09 16:12:34 by iozmen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *printed)
{
	if (!str)
	{
		write (1, "(null)", 6);
		*printed += 6;
		return ;
	}
	while (*str)
	{
		write(1, str, 1);
		str++;
		*printed += 1;
	}
}

void	ft_putnbr(int nbr, int *printed)
{
	if (nbr == -2147483648)
	{
		return (ft_putstr("-2147483648", printed));
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
		*printed += 1;
	}
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10, printed);
		ft_putnbr(nbr % 10, printed);
	}
	else
	{
		nbr += '0';
		write(1, &nbr, 1);
		*printed += 1;
	}
}

void	ft_putptr(unsigned long long n, int *printed)
{
	if (n == 0)
	{
		write(1, "0x0", 3);
		*printed += 3;
	}
	else
	{
		write(1, "0x", 2);
		*printed += 2;
		ft_shex(n, printed);
	}
}

void	ft_shex(unsigned long long n, int *printed)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n >= 16)
	{
		ft_shex(n / 16, printed);
		ft_shex(n % 16, printed);
	}
	else
	{
		n = hex[n];
		write(1, &n, 1);
		*printed += 1;
	}
}

void	ft_bhex(unsigned long long n, int *printed)
{
	char	*hex;

	hex = "0123456789ABCDEF";
	if (n >= 16)
	{
		ft_bhex(n / 16, printed);
		ft_bhex(n % 16, printed);
	}
	else
		ft_putchar(hex[n], printed);
}
