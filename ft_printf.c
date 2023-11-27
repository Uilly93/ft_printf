/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:36:56 by wnocchi           #+#    #+#             */
/*   Updated: 2023/11/27 16:24:14 by wnocchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdarg.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putstr(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr_hexa(long long nb)
{
	size_t	len;

	len = 0;
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 10)
	{
		len += ft_putnbr_hexa(nb / 16);
		len += ft_putnbr_hexa(nb % 16);
	}
	else
		len += ft_putchar(nb + 48);
	return (len);
}

int	ft_putnbr(long int nb)
{
	size_t		len;

	len = 0;
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 10)
	{
		len += ft_putnbr(nb / 10);
		len += ft_putnbr(nb % 10);
	}
	else
		len += ft_putchar(nb + 48);
	return (len);
}

int	ft_putnbr_xu(long long nb)
{
	size_t	len;

	len = 0;
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 16)
	{
		len += ft_putnbr_hexa(nb / 16);
		len += ft_putnbr_hexa(nb % 16);
	}
	else
		len += ft_putchar(nb + 'A');
	return (len);
}

int	ft_putnbr_xl(long long nb)
{
	size_t	len;

	len = 0;
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 16)
	{
		len += ft_putnbr_hexa(nb / 16);
		len += ft_putnbr_hexa(nb % 16);
	}
	else
		len += ft_putchar(nb + 'a');
	return (len);
}


int	is_c(char c)
{
	ft_putchar(c);
	return (1);
}

int	is_di(int nb)
{
	return (ft_putnbr(nb));
}

int	is_xu(int hexa)
{
	return (ft_putnbr_xu(hexa));
}

int	is_xl(int hexa)
{
	return (ft_putnbr_xl(hexa));
}

int	is_u(unsigned int nb)
{
	return (ft_putnbr(nb));
}

int	is_s(const char *s)
{
	if (!s)
	{
		ft_putstr("(null)");
		return (6);
	}
	else
		ft_putstr((char *)s);
	return (ft_strlen((char *)s));
}

int is_p(void *p)
{
	write(1, "0x", 2);
	return (ft_putnbr_hexa((unsigned long) p + 2));
}

int	mandatory(const char *fmt, va_list args)
{
	int		len;

	len = 0;
		if (*fmt == 's')
			len += is_s(va_arg(args, char *));
		else if (*fmt == 'c')
			len += is_c((char)va_arg(args, int));
		else if (*fmt == 'd' || *fmt == 'i')
			len += is_di(va_arg(args, int));
		else if (*fmt == 'p')
			len += is_p(va_arg(args, void *));
		else if (*fmt == 'u')
			len += is_u(va_arg(args, unsigned int));
		else if (*fmt == 'x')
			len += is_xl(va_arg(args, unsigned long));
		else if (*fmt == 'X')
			len += is_xu(va_arg(args, unsigned long));
		else if (*fmt == '%')
			len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *s, ...)
{
	int	i;
	int	len;

	va_list(args);

	i = 0;
	len = 0;
	va_start(args, s);
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			len += mandatory(&s[i++], args);
		}
		else
		{
			len += ft_putchar(s[i]);
			i++;
		}
	}
	va_end(args);
	return (len);
}

int	main(void)
{
	ft_printf("%d, 12");
}

