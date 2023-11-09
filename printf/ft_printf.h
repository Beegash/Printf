/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iozmen <iozmen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:36:37 by iozmen            #+#    #+#             */
/*   Updated: 2023/11/09 16:12:36 by iozmen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_type(va_list *args, char ch, int *printed);
void	ft_putchar(char ch, int *printed);
void	ft_putstr(char *str, int *printed);
void	ft_putnbr(int nbr, int *printed);
void	ft_putptr(unsigned long long n, int *printed);
void	ft_shex(unsigned long long n, int *printed);
void	ft_bhex(unsigned long long n, int *printed);
void	ft_putunsigned(unsigned int n, int *printed);

#endif
