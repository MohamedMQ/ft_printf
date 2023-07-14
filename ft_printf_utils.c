/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:15:42 by mmaqbour          #+#    #+#             */
/*   Updated: 2022/12/20 10:15:44 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_imp_char(int *cnt, char c)
{
	write(1, &c, 1);
	*cnt += 1;
}

void	ft_imp_str(int *cnt, char *cad)
{
	int	i;

	if (!cad)
		ft_imp_str(cnt, "(null)");
	else
	{
		i = 0;
		while (cad[i])
			ft_imp_char(cnt, cad[i++]);
	}
}

void	ft_imp_nb(int *cnt, char *base, int bsize, unsigned long long num)
{
	if (num >= (unsigned long long)bsize)
	{
		ft_imp_nb(cnt, base, bsize, (num / bsize));
		ft_imp_char(cnt, base[num % bsize]);
	}
	else
		ft_imp_char(cnt, base[num]);
}

void	ft_imp_snb(int *cnt, char *base, int bsize, int num)
{
	long int	n;

	n = (long int)num;
	if (n < 0)
	{
		ft_imp_char(cnt, '-');
		n = n * (-1);
	}
	ft_imp_nb(cnt, base, bsize, n);
}

void	ft_imp_mem(int *cnt, char *base, int bsize, unsigned long long num)
{
	write(1, "0x", 2);
	*cnt += 2;
	ft_imp_nb(cnt, base, bsize, num);
}
