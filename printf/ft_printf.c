/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:54:17 by macote            #+#    #+#             */
/*   Updated: 2023/03/02 15:14:25 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	flag_case(char flag, va_list arg)
{
	if (flag == '%')
		return (pf_putchar('%'));
	else if (flag == 'c')
		return (pf_putchar(va_arg(arg, int)));
	else if (flag == 's')
		return (pf_putstr(va_arg(arg, char *)));
	else if (flag == 'd' || flag == 'i')
		return (pf_putnbr(va_arg(arg, int)));
	else if (flag == 'u')
		return (pf_putnbr_u(va_arg(arg, unsigned int)));
	else if (flag == 'x')
		return (pf_puthexa(va_arg(arg, unsigned int), 0));
	else if (flag == 'X')
		return (pf_puthexa(va_arg(arg, unsigned int), 1));
	else if (flag == 'p')
		return (pf_puthexa_adress(va_arg(arg, unsigned long long)));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		char_count;
	va_list	args;
	int		i;

	if (!str)
		return (-1);
	va_start(args, str);
	char_count = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			if (char_count >= 0)
				char_count += flag_case(str[i++ + 1], args);
		}
		else
		{
			if (char_count >= 0)
				char_count += pf_putchar(str[i]);
		}
	}
	if (char_count < 0)
		return (-1);
	return (char_count);
}

// int main(void)
// {
// 	printf("%d", ft_printf("\001\002\007\v\010\f\r\n"));
// 	printf("\n\n");
// 	printf("%d", printf("\001\002\007\v\010\f\r\n"));
// 	return (0);
// }
