/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 08:36:45 by seocha            #+#    #+#             */
/*   Updated: 2022/12/05 10:28:40 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isin(char c, char *charset)
{
	int	idx;

	idx = 0;
	if (!charset)
		return (0);
	while (charset[idx])
	{
		if (c == charset[idx])
			return (1);
		idx++;
	}
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_putstr(char *str)
{
	int	idx;

	idx = 0;
	if (!str)
		return (0);
	while (str[idx])
	{
		ft_putchar(str[idx]);
		idx++;
	}
	return (idx);
}

void	ft_print_hexlow(unsigned long num, int base)
{
	if (num == 0)
		return ;
	ft_print_hexlow(num / base, base);
	ft_putchar("0123456789abcdef"[num % base]);
}

void	ft_print_hexupp(unsigned long num, int base)
{
	if (num == 0)
		return ;
	ft_print_hexupp(num / base, base);
	ft_putchar("0123456789ABCDEF"[num % base]);
}
