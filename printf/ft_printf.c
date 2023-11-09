/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iozmen <iozmen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:36:41 by iozmen            #+#    #+#             */
/*   Updated: 2023/11/09 16:12:29 by iozmen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunsigned(unsigned int nbr, int *printed)
{
	if (nbr >= 10)
	{
		ft_putunsigned(nbr / 10, printed);
		ft_putunsigned(nbr % 10, printed);
	}
	else
	{
		nbr += '0';
		write(1, &nbr, 1);
		*printed += 1;
	}
}

void	ft_putchar(char ch, int *printed)
{
	write(1, &ch, 1);
	*printed += 1;
}

void	ft_type(va_list *args, char ch, int *printed)
{
	if (ch == 'c')
		ft_putchar(va_arg(*args, int), printed);
	else if (ch == 's')
		ft_putstr(va_arg(*args, char *), printed);
	else if (ch == 'i' || ch == 'd')
		ft_putnbr(va_arg(*args, int), printed);
	else if (ch == 'p')
		ft_putptr(va_arg(*args, unsigned long long), printed);
	else if (ch == 'X')
		ft_bhex(va_arg(*args, unsigned int), printed);
	else if (ch == 'x')
		ft_shex(va_arg(*args, unsigned int), printed);
	else if (ch == 'u')
		ft_putunsigned(va_arg(*args, unsigned int), printed);
	else if (ch == '%')
		ft_putchar('%', printed);
	else
		ft_putchar(va_arg(*args, int), printed);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		printed;
	va_list	args;

	i = 0;
	printed = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			ft_type(&args, format[i], &printed);
		}
		else
		{
			ft_putchar(format[i], &printed);
		}
		i++;
	}
	va_end(args);
	return (printed);
}
