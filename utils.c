/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hinel-mo <hinel-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:30:02 by hinel-mo          #+#    #+#             */
/*   Updated: 2024/12/06 11:55:17 by hinel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "utils.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putnum(long nb, int unsi)
{
	int	count;

	count = 0;
	if (!unsi && nb == -2147483648)
		return (ft_putstr("-2147483648"));
	if (!unsi && nb < 0)
	{
		count += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		count += ft_putnum(nb / 10, unsi);
	count += ft_putchar((nb % 10) + '0');
	return (count);
}

int	ft_puthexptr(unsigned long n, char format, int ptrr)
{
	char	*hex;
	int		len;

	len = 0;
	if (ptrr && !n)
		return (ft_putstr("(nil)"));
	if (ptrr)
		len += ft_putstr("0x");
	if (format == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (n >= 16)
		len += ft_puthexptr(n / 16, format, 0);
	len += ft_putchar(hex[n % 16]);
	return (len);
}

int	ft_putpercent(void)
{
	return (ft_putchar('%'));
}
