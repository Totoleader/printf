/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 11:12:18 by macote            #+#    #+#             */
/*   Updated: 2023/02/27 10:02:31 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	printnb_(int nb)
{
	int	modulo;
	int	tableau[11];
	int	i;

	i = 0;
	while (nb != 0)
	{
		modulo = nb % 10;
		tableau[i++] = modulo + 48;
		nb -= modulo;
		nb /= 10;
	}
	i--;
	while (i >= 0)
	{
		if (tableau[i])
		{
			if (write(1, &tableau[i], 1) == -1)
				return (-1);
		}
		i--;
	}
	return (0);
}

static int	pf_printnbr(int n)
{
	if (n == -2147483648)
	{
		if (write(1, "-2147483648", 11) == -1)
			return (-1);
		return (0);
	}
	if (n == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (0);
	}
	if (n < 0)
	{
		n *= -1;
		if (write(1, "-", 1) == -1)
			return (-1);
	}
	if (printnb_(n) == -1)
		return (-1);
	return (0);
}

static int	count_chars(int nb)
{
	int	count;

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

int	pf_putnbr(int nb)
{
	if (pf_printnbr(nb) == -1)
		return (INT_MIN);
	return (count_chars(nb));
}
