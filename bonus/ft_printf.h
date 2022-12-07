/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 08:53:21 by seocha            #+#    #+#             */
/*   Updated: 2022/12/07 08:36:44 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_list
{
	int	minus;
	int	zero;
	int	hash;
	int	space;
	int	plus;
	int	width;
	int	precision;
}	t_list;

int		ft_printf(const char *format, ...);
void	ft_mandt(va_list ap, char c);

void	ft_char(va_list ap);
void	ft_string(va_list ap);
void	ft_hex(va_list ap);
void	ft_dec(va_list ap);
void	ft_udec(va_list ap);
void	ft_hexlow(va_list ap);
void	ft_hexupp(va_list ap);

int		ft_isin(char c, char *charset);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_print_hexlow(unsigned long num, int base);
void	ft_print_hexupp(unsigned long num, int base);
char	*ft_itoa(int n);
int		ft_nbr_len(long long int nbr);

#endif
