/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 09:58:42 by eric              #+#    #+#             */
/*   Updated: 2025/03/24 16:34:01 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

void	print_str(const char *str, int *len)
{
	int i = -1;
	if (!str)
		str = "(null)";

	while (str[++i])
		*len += write (1, &str[i], 1);
}

void	print_deci(long long int nb, int *len)
{
	char *deci = "0123456789";

	if (nb == -2147483648)
	{
		*len += write (1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		*len += write (1, "-", 1);
		nb *= -1;
	}
	if (nb >= 10)
		print_deci(nb / 10, len);
	*len += write (1, &deci[nb % 10], 1);
}

void	print_hexa(unsigned int nb, int *len)
{
	char *hexa = "0123456789abcdef";

	if (nb >= 16)
		print_hexa(nb / 16, len);
	*len += write (1, &hexa[nb % 16], 1);
}

int ft_printf(const char *format, ...)
{
	va_list args;
	int	i = 0;
	int len = 0;

	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 's')
				print_str(va_arg(args, char *), &len);
			else if (format[i] == 'd')
				print_deci((long long int)va_arg(args, int), &len);
			else if (format[i] == 'x')
				print_hexa(va_arg(args, unsigned int), &len);
		}
		else
			len += write (1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}

int main(void)
{
	int deci = -2147483648;
	char *s = "Salut les connards\n";
	unsigned int hexa = 42;

	ft_printf("My printf %d\n", deci);
	printf("OG : %d\n", deci);
	ft_printf("My printf : %s", s);
	printf("OG : %s", s);
	ft_printf("My printf : %x\n", hexa);
	printf("OG : %x\n", hexa);
}
