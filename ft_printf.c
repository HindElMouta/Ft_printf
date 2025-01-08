/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hinel-mo <hinel-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:21:10 by hinel-mo	       #+#    #+#             */
/*   Updated: 2024/12/06 11:53:46 by hinel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "utils.h"

int	ft_form(char c, va_list *args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(*args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(*args, char *)));
	if (c == 'p')
		return (ft_puthexptr((unsigned long)va_arg(*args, void *), 'x', 1));
	if (c == 'd' || c == 'i')
		return (ft_putnum(va_arg(*args, int), 0));
	if (c == 'u')
		return (ft_putnum(va_arg(*args, unsigned int), 1));
	if (c == 'x' || c == 'X')
		return (ft_puthexptr(va_arg(*args, unsigned int), c, 0));
	if (c == '%')
		return (ft_putpercent());
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, format);
	i = 0;
	len = 0;
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
			len += ft_form(format[++i], &args);
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}

/*
#include <stdio.h>
int main()
{
	ft_printf("Character: %c\n", 'A');
	printf("printf Character: %c\n", 'A');
	ft_printf("String: %s\n", "Hello, world!");
	printf("printf String: %s\n", "Hello, world!");
	ft_printf("Pointer: %p\n", &main);
	printf("printf Pointer: %p\n", &main);
	ft_printf("Decimal: %d\n", 42);
	printf("printf Decimal: %d\n", 42);
	ft_printf("Integer: %i\n", -42);
	printf("printf Integer: %i\n", -42);
	ft_printf("Unsigned: %u\n", 123456789);
	printf("printf Unsigned: %u\n", 123456789);
	ft_printf("Hex lowercase: %x\n", 255);
	printf("printf Hex lowercase: %x\n", 255);
	ft_printf("Hex uppercase: %X\n", 255);
	printf("printf Hex uppercase: %X\n", 255);
	ft_printf("Percent: %%\n");
	printf("printf Percent: %%\n");
	ft_printf("ft_printf Multiple formats: %c %s %p %d %i %u %x %X %%\n", 'B', 
	"Test", &main, 123, -123, 456, 789, 789);
    printf("printf Multiple formats: %c %s %p %d %i %u %x %X %%\n", 
	'B', "Test", &main, 123, -123, 456, 789, 789);
	return 0;
}*/
