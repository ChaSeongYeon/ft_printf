/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandatory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:37:55 by seocha            #+#    #+#             */
/*   Updated: 2022/12/05 11:45:49 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_char(char *format, t_list *flag, va_list ap, int *cnt)
{
	char	c;

	if (*format == '%')
		c = '%';
	else
		c = va_arg(ap, int);
	if (flag->width <= 1)
	{
		ft_putchar(c);
		(*cnt)++;
	}
	else
		ft_char_print(c, flag, cnt);
}

void	ft_check_str(t_list *flag, va_list ap, int *val)
{
	char	*str;

	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	if (flag->precision == -1)
		ft_str_minus(s, flag, cnt);
	else if (flag->precision == 0)
		ft_str_zero(falg, cnt);
	else if (flag->precision > 0)
		ft_str_plus(s, flag, val);
}
