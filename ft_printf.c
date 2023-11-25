/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:36:56 by wnocchi           #+#    #+#             */
/*   Updated: 2023/11/24 09:48:05 by wnocchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[1])
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
		ft_putchar_hexa('-');
		nb *= -1;
	}
	if (nb >= 10)
	{
		len += ft_putnbr_hexa(nb / 16);
		len += ft_putnbr_hexa(nb % 16);
	}
	else
		len += ft_putchar_hexa(nb + 48);
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
}

int	is_c(const char *s)
{
	ft_putchar(*s);
	return (1);
}

int	is_di(int nb)
{
	return (ft_putnbr);
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
		ft_putstr(s);
	return (ft_strlen(s));
}

int	is_percent(int c)
{
	return (ft_putchar(c));
}

int	mandatory(char *fmt, va_list args)
{
	size_t	i;
	char	*s;
	int		d;
	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			i++;
			if(fmt[i] == 's')
				*s = va_arg(args, char *);
				is_s(s);
		}
	}
}

