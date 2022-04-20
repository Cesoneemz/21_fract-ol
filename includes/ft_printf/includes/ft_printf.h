/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 19:20:39 by wlanette          #+#    #+#             */
/*   Updated: 2021/10/18 19:52:54 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

int		ft_printf(const char *input, ...);
int		ft_type_is_valid(char c);
int		ft_putchar(char c);
int		ft_printf_split_by_args(char c, va_list argptr);
int		ft_putstr(char *str, int prec);
char	*ft_tolower_str(char *str);
char	*ft_uint_itoa(unsigned int nbr);
char	*ft_convert_to_base(unsigned long long addr, int base);
int		ft_char_treatment(char c);
int		ft_string_treatment(char *str);
int		ft_pointer_treatment(unsigned long long addr);
int		ft_integer_treatment(int nbr);
int		ft_uint_treatment(unsigned int nbr);
int		ft_hex_treatment(unsigned int nbr, char c);

#endif
