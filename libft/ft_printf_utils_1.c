/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:19:03 by vzashev           #+#    #+#             */
/*   Updated: 2023/10/31 05:06:43 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_char(int c)
{
	return (write(1, &c, 1));
}

int	ft_print_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
		ft_print_char(str[i++]);
	return (i);
}

int	ft_print_num(int nb)
{
	int	i;

	i = 0;
	if (nb == -2147483648)
	{
		i += ft_print_char('-');
		i += ft_print_char('2');
		nb = (147483648);
	}
	if (nb < 0)
	{
		i += ft_print_char('-');
		nb = -nb;
	}
	if (nb > 9)
		i += ft_print_num(nb / 10);
	i += ft_print_char(nb % 10 + 48);
	return (i);
}

int	ft_convert_add(unsigned long nb, char *s)
{
	int	i;

	i = 0;
	if (nb >= 16)
		i += ft_convert_add(nb / 16, s);
	i += ft_print_char(s[nb % 16]);
	return (i);
}

int	ft_print_point(unsigned long nb, char *s)
{
	int	i;

	i = 2;
	ft_print_char('0');
	ft_print_char('x');
	i += ft_convert_add(nb, s);
	return (i);
}
