/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 20:43:18 by astepano          #+#    #+#             */
/*   Updated: 2017/03/07 20:43:25 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *restrict format, ...)
{
	size_t		len;
	size_t		i;
	va_list		valist;

	if (!format)
		return (-1);
	va_start(valist, format);
	len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' || format[i] == '{')
		{
			ft_write(1, format + len, i - len);
			len = parse(format, i + 1, valist);
			i = len - 1;
		}
		i++;
	}
	ft_write(1, format + len, i - len);
	va_end(valist);
	return (printed_count());
}

//int main(void)
//{
////	double nan[] = {0.0, -0.0, 0.0 / 0.0, -0.0 / 0.0, 0.0 / -0.0, 1.0 / 0.0, -1.0 / 0.0, 1.0 / 0.0};
//	long double nan[] = {1.9999999999999, 14.34, 2.0, 2434124.1234, 123455343546745344567655676545678765434567865643457.43564456, 0.0000000000000000000000000000123124234234, 0.1, 5.0, 0.5, 1.0, 2.0, 100.3, 2.3};
//	for (int i = 0; i < (sizeof(nan) / sizeof(nan[0])); i++)
//	{
//		printf("%La\n", nan[i]);
//		ft_printf("%La\n", nan[i]);
//	}
//}