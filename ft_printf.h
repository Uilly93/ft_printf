/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:40:32 by wnocchi           #+#    #+#             */
/*   Updated: 2023/11/23 17:24:23 by wnocchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stddef.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);
int		ft_putchar(char c);
int		ft_putnbr_xu(long long nb);
int		ft_putnbr_xl(long long nb);
int		ft_putnbr_p(long long nb);
int		ft_putchar(char c);
size_t	ft_strlen(char *s);
int		ft_putstr(char *s);
int		ft_putnbr_hexa(long long nb);
int		ft_putnbr(long int nb);
int		is_c(const char *s);
int		is_di(int nb);
int		is_xu(int hexa);
int		is_u(unsigned int nb);
int		is_s(const char *s);


#endif