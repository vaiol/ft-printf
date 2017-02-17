
#include "ft_handlers.h"

size_t	handle_sc(const char c, va_list valist)
{
	if (c == 's')
		ft_putstr(va_arg(valist, char *));
	else if (c == 'c')
		ft_putchar(va_arg(valist, char));
	return (1);
}

size_t	handle_SC(const char c, va_list valist)
{
	if (c == 'S')
		ft_putwstr(va_arg(valist, wchar_t *));
	else if (c == 'C')
		ft_putwint(va_arg(valist, wint_t));
	return (1);
}

size_t	handle_DOU(const char c, va_list valist)
{
	if (c == 'D')
		ft_putnbr(va_arg(valist, long int));
	else if (c == 'U')
		ft_putnbr_unsigned(va_arg(valist, unsigned long int));
	else if (c == 'O')
		ft_putnbr_base(va_arg(valist, unsigned long int), 8, c);
	return (1);
}
size_t	handle_diouxX(const char c, va_list valist)
{
	if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(valist, int));
	else if (c == 'u')
		ft_putnbr_unsigned(va_arg(valist, unsigned int));
	else if (c == 'o')
		ft_putnbr_base(va_arg(valist, unsigned int), 8, c);
	else if (c == 'x' || c == 'X')
		ft_putnbr_base(va_arg(valist, unsigned int), 16, c);
	return (1);
}

size_t	handle_hh_diouxX(const char c, va_list valist)
{
	if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(valist, char));
	else if (c == 'u')
		ft_putnbr_unsigned(va_arg(valist, unsigned char));
	else if (c == 'o')
		ft_putnbr_base(va_arg(valist, unsigned char), 8, c);
	else if (c == 'x' || c == 'X')
		ft_putnbr_base(va_arg(valist, unsigned char), 16, c);
	return (3);
}

size_t	handle_h_diouxX(const char c, va_list valist)
{
	if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(valist, short));
	else if (c == 'u')
		ft_putnbr_unsigned(va_arg(valist, unsigned short));
	else if (c == 'o')
		ft_putnbr_base(va_arg(valist, unsigned short), 8, c);
	else if (c == 'x' || c == 'X')
		ft_putnbr_base(va_arg(valist, unsigned short), 16, c);
	return (2);
}

size_t	handle_l_diouxX(const char c, va_list valist)
{
	if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(valist, long));
	else if (c == 'u')
		ft_putnbr_unsigned(va_arg(valist, unsigned long));
	else if (c == 'o')
		ft_putnbr_base(va_arg(valist, unsigned long), 8, c);
	else if (c == 'x' || c == 'X')
		ft_putnbr_base(va_arg(valist, unsigned long), 16, c);
	return (2);
}

size_t	handle_ll_diouxX(const char c, va_list valist)
{
	if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(valist, long long));
	else if (c == 'u')
		ft_putnbr_unsigned(va_arg(valist, unsigned long long));
	else if (c == 'o')
		ft_putnbr_base(va_arg(valist, unsigned long long), 8, c);
	else if (c == 'x' || c == 'X')
		ft_putnbr_base(va_arg(valist, unsigned long long), 16, c);
	return (3);
}

size_t	handle_j_diouxX(const char c, va_list valist)
{
	if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(valist, intmax_t));
	else if (c == 'u')
		ft_putnbr_unsigned(va_arg(valist, uintmax_t));
	else if (c == 'o')
		ft_putnbr_base(va_arg(valist, uintmax_t), 8, c);
	else if (c == 'x' || c == 'X')
		ft_putnbr_base(va_arg(valist, uintmax_t), 16, c);
	return (2);
}

size_t	handle_t_diouxX(const char c, va_list valist)
{
	if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(valist, ptrdiff_t));
	else if (c == 'u')
		ft_putnbr_unsigned(va_arg(valist, size_t));
	else if (c == 'o')
		ft_putnbr_base(va_arg(valist, size_t), 8, c);
	else if (c == 'x' || c == 'X')
		ft_putnbr_base(va_arg(valist, size_t), 16, c);
	return (2);
}

size_t	handle_z_diouxX(const char c, va_list valist)
{
	if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(valist, ssize_t));
	else if (c == 'u')
		ft_putnbr_unsigned(va_arg(valist, size_t));
	else if (c == 'o')
		ft_putnbr_base(va_arg(valist, size_t), 8, c);
	else if (c == 'x' || c == 'X')
		ft_putnbr_base(va_arg(valist, size_t), 16, c);
	return (2);
}

size_t	handle_q_diouxX(const char c, va_list valist)
{
	if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(valist, quad_t));
	else if (c == 'u')
		ft_putnbr_unsigned(va_arg(valist, u_quad_t));
	else if (c == 'o')
		ft_putnbr_base(va_arg(valist, u_quad_t), 8, c);
	else if (c == 'x' || c == 'X')
		ft_putnbr_base(va_arg(valist, u_quad_t), 16, c);
	return (2);
}


size_t 	handle_l(const char *str, size_t i, va_list valist)
{
	if (str[i] == 'l')
		if (ft_str_contains_chr("diouxX", str[i + 1]))
			return (handle_ll_diouxX(str[i + 1], valist));
	if (ft_str_contains_chr("diouxX", str[i]))
		return (handle_l_diouxX(str[i], valist));
	if (str[i] == 's')
		return (handle_SC('S', valist) + 1);
	if (str[i] == 'c')
		return (handle_SC('C', valist) + 1);
	return (ft_strlen(str) - i);
}

size_t 	handle_h(const char *str, size_t i, va_list valist)
{
	if (str[i] == 'h')
		if (ft_str_contains_chr("diouxX", str[i + 1]))
			return (handle_hh_diouxX(str[i + 1], valist));
	if (ft_str_contains_chr("diouxX", str[i]))
		return (handle_h_diouxX(str[i], valist));
	return (ft_strlen(str) - i);
}

size_t 	handle_jtzq(const char *str, size_t i, va_list valist)
{
	if (str[i] == 'j')
	{
		if (ft_str_contains_chr("diouxX", str[i + 1]))
			return (handle_j_diouxX(str[i + 1], valist));
	}
	else if (str[i] == 't')
	{
		if (ft_str_contains_chr("diouxX", str[i + 1]))
			return (handle_t_diouxX(str[i + 1], valist));
	}
	else if (str[i] == 'z')
	{
		if (ft_str_contains_chr("diouxX", str[i + 1]))
			return (handle_z_diouxX(str[i + 1], valist));
	}
	else if (str[i] == 'q')
	{
		if (ft_str_contains_chr("diouxX", str[i + 1]))
			return (handle_q_diouxX(str[i + 1], valist));
	}
	return (ft_strlen(str) - i);
}

//hh, h, ll, l, j, t, z, q
size_t	handle_modifier(const char *str, size_t i, va_list valist)
{
	if (str[i] == 'l')
		return (handle_l(str, i + 1, valist));
	if (str[i] == 'h')
		return (handle_h(str, i + 1, valist));
	if (ft_str_contains_chr("jtzq", str[i]))
		return (handle_jtzq(str, i, valist));
	return (ft_strlen(str) - i);
}

//DOU diouxX SC sc p
size_t	handle_conversions(const char *str, size_t i, va_list valist)
{
	if (ft_str_contains_chr("hljtzq", str[i]))
		return (handle_modifier(str, i, valist));
	if (ft_str_contains_chr("DOU", str[i]))
		return (handle_DOU(str[i], valist));
	if (ft_str_contains_chr("diouxX", str[i]))
		return (handle_diouxX(str[i], valist));
	if (ft_str_contains_chr("SC", str[i]))
		return (handle_SC(str[i], valist));
	if (ft_str_contains_chr("sc", str[i]))
		return (handle_sc(str[i], valist));
	if (str[i] == 'p')
		ft_putmem(va_arg(valist, void *));
	return (1);
}