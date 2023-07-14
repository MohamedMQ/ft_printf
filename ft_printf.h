/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:15:22 by mmaqbour          #+#    #+#             */
/*   Updated: 2022/12/20 10:15:24 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define B10 "0123456789"
# define L10 10
# define BU16 "0123456789ABCDEF"
# define BL16 "0123456789abcdef"
# define L16 16

int		ft_printf(char const *str, ...);
void	ft_do_format(int *cnt, char c, va_list args);
void	ft_imp_char(int *cnt, char c);
void	ft_imp_str(int *cnt, char *cad);
void	ft_imp_snb(int *cnt, char *base, int bsize, int num);
void	ft_imp_nb(int *cnt, char *base, int bsize, unsigned long long num);
void	ft_imp_mem(int *cnt, char *base, int bsize, unsigned long long num);

#endif
