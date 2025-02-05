/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:15:48 by mmaqbour          #+#    #+#             */
/*   Updated: 2022/12/20 10:15:50 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_imp_char(t_flag *flags, char c)
{
	write(1, &c, 1);
	flags->cnt += 1;
}

void	ft_imp_str(t_flag *flags, char const *cad)
{
	int	i;

	if (!cad)
		ft_imp_str(flags, "(null)");
	else
	{
		i = 0;
		while (cad[i])
			ft_imp_char(flags, cad[i++]);
	}
}

void	ft_imp_m(t_flag *flags, char *base, int bsize, unsigned long long num)
{
	write(1, "0x", 2);
	flags->cnt += 2;
	ft_imp_nb(flags, base, bsize, num);
}

void	ft_imp_nb(t_flag *flags, char *base, int bsize, unsigned long long num)
{
	if (num >= (unsigned long long)bsize)
	{
		ft_imp_nb(flags, base, bsize, (num / bsize));
		ft_imp_char(flags, base[num % bsize]);
	}
	else
		ft_imp_char(flags, base[num]);
}

void	ft_clear_flags(t_flag *flags)
{
	flags->hashtag = 0;
	flags->plus = 0;
	flags->spce = 0;
}
