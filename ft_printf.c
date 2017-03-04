#include "ft_printf.h"

int 		ft_printf(const char *restrict format, ...)
{
	size_t 		len;
	size_t 		i;
	va_list		valist;

	if (!format)
		return (-1);
	va_start(valist, format);
	len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			ft_write(1, format + len, i - len);
			i++;
			if (format[i] != '%')
				len = parser(format, i, valist);
			else
				len = i;
		}
		i++;
	}
	ft_write(1, format + len, i - len);
	va_end(valist);
	return (get_count_symbols());
}