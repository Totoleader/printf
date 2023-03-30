/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_num_flags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:10:25 by macote            #+#    #+#             */
/*   Updated: 2023/02/27 09:12:27 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	count_chars_u(unsigned int nb)
{
	unsigned int	count;

	count = 0;
	if (nb <= 0)
		count++;
	while (nb)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

static int	case0_(void)
{
	if (write(1, "0", 1) == -1)
		return (-1);
	return (1);
}

static int	put_unsigned_nbr(unsigned int nb)
{
	int	modulo;
	int	tableau[11];
	int	i;

	if (nb == 0)
		return (case0_());
	i = 0;
	while (nb != 0)
	{
		modulo = nb % 10;
		tableau[i++] = modulo + 48;
		nb -= modulo;
		nb /= 10;
	}
	while (--i >= 0)
	{
		if (tableau[i])
		{
			if (write(1, &tableau[i], 1) == -1)
				return (-1);
		}
	}
	return (0);
}

int	pf_putnbr_u(unsigned int nb)
{
	if (put_unsigned_nbr(nb) == -1)
		return (-1);
	return (count_chars_u(nb));
}
