/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:15:30 by mmaqbour          #+#    #+#             */
/*   Updated: 2022/12/20 10:15:32 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_do_format(int *cnt, char c, va_list args)
{
	if ((c == 'd') || (c == 'i'))
		ft_imp_snb(cnt, B10, L10, va_arg(args, int));
	if (c == 'u')
		ft_imp_nb(cnt, B10, L10, va_arg(args, unsigned int));
	if (c == 'c')
		ft_imp_char(cnt, va_arg(args, int));
	if (c == '%')
		ft_imp_char(cnt, '%');
	if (c == 's')
		ft_imp_str(cnt, va_arg(args, char *));
	if (c == 'x')
		ft_imp_nb(cnt, BL16, L16, va_arg(args, unsigned int));
	if (c == 'X')
		ft_imp_nb(cnt, BU16, L16, va_arg(args, unsigned int));
	if (c == 'p')
		ft_imp_mem(cnt, BL16, L16, va_arg(args, unsigned long long));
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		cnt;
	va_list	args;

	va_start(args, str);
	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] == '%')
			ft_do_format(&cnt, str[++i], args);
		else
			ft_imp_char(&cnt, str[i]);
		i++;
	}
	va_end(args);
	return (cnt);
}
