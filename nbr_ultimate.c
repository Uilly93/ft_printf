/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_ultimate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:32:57 by wnocchi           #+#    #+#             */
/*   Updated: 2023/11/23 17:33:29 by wnocchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

int	ft_putnbr_p(long long nb)
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
		len += ft_putchar(nb + '0');
	return (len);
}
