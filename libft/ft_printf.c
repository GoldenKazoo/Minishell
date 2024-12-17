/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsougoum <vsougoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:51:16 by vsougoum          #+#    #+#             */
/*   Updated: 2024/09/27 12:07:01 by vsougoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_puthexa(unsigned long n, char format)
{
	char	*base;
	int		count;

	count = 0;
	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n >= 16)
		count += ft_puthexa(n / 16, format);
	count += ft_putchar_fd(base[n % 16], 1);
	return (count);
}

static int	ft_putptr(void *ptr)
{
	unsigned long	n;
	int				count;

	if (ptr == NULL)
	{
		count = ft_putstr_fd("(nil)", 1);
		return (count);
	}
	count = 0;
	n = (unsigned long) ptr;
	count += ft_putstr_fd("0x", 1);
	count += ft_puthexa(n, 'x');
	return (count);
}

static int	ft_putunsigned_fd(unsigned int n, int fd)
{
	int	count;

	count = 0;
	if (n >= 10)
	{
		count += ft_putunsigned_fd(n / 10, fd);
		count += ft_putunsigned_fd(n % 10, fd);
	}
	else if (n <= 9)
		count += ft_putchar_fd(n + '0', fd);
	return (count);
}

static int	ft_format_print(va_list args, const char format_print)
{
	if (format_print == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	if (format_print == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	if (format_print == 'd' || format_print == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	if (format_print == 'u')
		return (ft_putunsigned_fd(va_arg(args, unsigned int), 1));
	if (format_print == 'x' || format_print == 'X')
		return (ft_puthexa(va_arg(args, unsigned int), format_print));
	if (format_print == 'p')
		return (ft_putptr(va_arg(args, void *)));
	if (format_print == '%')
		return (ft_putchar_fd('%', 1));
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		print_length;

	if (!str)
		return (-1);
	i = 0;
	print_length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && ft_strchr("cspdiuxX%", str[i + 1]))
		{
			print_length += ft_format_print(args, str[i + 1]);
			i++;
		}
		else
			print_length += ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(args);
	return (print_length);
}
