/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:54:39 by macote            #+#    #+#             */
/*   Updated: 2023/02/27 09:27:55 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <limits.h>
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	pf_putchar(int c);
int	pf_putstr(char *c);
int	pf_putnbr(int nb);
int	pf_puthexa(unsigned int nb, int is_upper);
int	pf_puthexa_adress(unsigned long nb);
int	pf_putnbr_u(unsigned int nb);

#endif
