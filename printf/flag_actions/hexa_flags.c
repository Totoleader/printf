/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 11:51:34 by macote            #+#    #+#             */
/*   Updated: 2023/02/27 10:02:01 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	case0(void)
{
	if (write(1, "0", 1) == -1)
		return (INT_MIN);
	return (1);
}

int	pf_puthexa(unsigned int nb, int is_upper)
{
	char				buffer[20];
	char				*ref;
	unsigned long long	modulo;
	int					i;
	int					count_char;

	if (nb == 0)
		return (case0());
	ref = "0123456789abcdef";
	if (is_upper)
		ref = "0123456789ABCDEF";
	i = 0;
	while (nb > 0)
	{
		modulo = nb % 16;
		buffer[i++] = ref[modulo];
		nb /= 16;
	}
	count_char = i--;
	while (i >= 0)
	{
		if (write(1, &buffer[i--], 1) == -1)
			return (INT_MIN);
	}
	return (count_char);
}

static int	case00(void)
{
	if (write(1, "0", 1) == -1)
		return (INT_MIN);
	return (3);
}

int	pf_puthexa_adress(unsigned long nb)
{
	char				buffer[20];
	char				*ref;
	unsigned long long	modulo;
	int					i;
	int					count_char;

	if (write(1, "0x", 2) == -1)
		return (INT_MIN);
	if (nb == 0)
		return (case00());
	ref = "0123456789abcdef";
	i = 0;
	while (nb > 0)
	{
		modulo = nb % 16;
		buffer[i++] = ref[modulo];
		nb /= 16;
	}
	count_char = 2 + i--;
	while (i >= 0)
	{
		if (write(1, &buffer[i--], 1) == -1)
			return (INT_MIN);
	}
	return (count_char);
}
