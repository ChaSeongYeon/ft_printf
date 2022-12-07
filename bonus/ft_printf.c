/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 08:57:09 by seocha            #+#    #+#             */
/*   Updated: 2022/12/05 11:42:30 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_reset(t_list *flag)
{
	flag.minus = 0;
	flag.zero = 0;
	flag.hash = 0;
	flag.space = 0;
	flag.minus = 0;
	flag.plus = 0;
	flag.width = 0;
	flag.precision = 0;
}

void	ft_type(char **format, t_list *flag, va_list ap, int *cnt)
{
	format++;
	if (!(**format))
		return ;
	else if (**format == 'c')
		ft_check_char(format, flag, ap, cnt);
	else if (**format == 's')
		ft_check_str(flag, ap, cnt);
	else if (**format == 'p')
		ft_check_addr(format, flag, ap, cnt);
	else if (**format == 'd' || *format == 'i')
		ft_check_int(flag, ap, cnt);
	else if (**format == 'x' || *format == 'X' || *format == 'u')
		ft_check_hexu(flag, ap, cnt);
}

int	ft_printf(const char *format, ...)
{
	int		cnt;
	t_list	*flag;
	va_list	ap;

	cnt = 0;
	flag = (t_list *)malloc(sizeof(t_list));
	if (!flag)
		return (0);
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			ft_check((char **)&format, flag, ap, &cnt);
		else
			ft_putchar(*format);
		format++;
	}
	va_end(ap);
	free(flag);
	return (cnt);
}

/*
void	ft_mandt(va_list ap, char c)
{
	if (c == 'c')
		ft_char(ap);
	else if (c == 's')
		ft_string(ap);
	else if (c == 'p')
		ft_hex(ap);
	else if (c == 'd')
		ft_dec(ap);
	else if (c == 'i')
		ft_dec(ap);
	else if (c == 'u')
		ft_udec(ap);
	else if (c == 'x')
		ft_hexlow(ap);
	else if (c == 'X')
		ft_hexupp(ap);
	else if (c == '%')
		ft_putchar(c);
}
*/
