/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 10:11:35 by macote            #+#    #+#             */
/*   Updated: 2023/02/27 09:12:03 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	pf_putchar(int c)
{
	if (write(1, &c, 1) == -1)
		return (INT_MIN);
	return (1);
}

int	pf_putstr(char *c)
{
	int	char_count;

	if (!c)
	{
		if (write(1, "(null)", 6) == -1)
			return (INT_MIN);
		return (6);
	}
	char_count = 0;
	while (*c)
	{
		if (write(1, c, 1) == -1)
			return (INT_MIN);
		char_count++;
		c++;
	}
	return (char_count);
}
