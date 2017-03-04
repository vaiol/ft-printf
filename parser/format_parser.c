#include "../ft_printf.h"

static t_format	*create_form(void)
{
	t_format	*form;

	form = (t_format *)malloc(sizeof(t_format));
	form->precision = -1;
	form->minimum_width = 0;
	form->hashtag = 0;
	form->apostrophe = 0;
	form->padding = '\0';
	form->sign = '\0';
	form->conversion.type = UNDEFINED;
	form->conversion.flag = N;
	form->conversion.an_unsigned = d;
	form->conversion.undefined = '\0';
	return (form);
}

static size_t	parse_flags(const char *format, size_t i, t_format *form)
{
	while (format[i])
	{
		if (format[i] == '#')
			form->hashtag = 1;
		else if (format[i] == '\'')
			form->apostrophe = 1;
		else if (format[i] == ' ' && form->sign != '+')
			form->sign = ' ';
		else if (format[i] == '+')
			form->sign = '+';
		else if (format[i] == '0' && form->padding != '-')
			form->padding = '0';
		else if (format[i] == '-')
			form->padding = '-';
		else
			break ;
		i++;
	}
	return (i);
}

/*
** parsing precision and minimum width
*/

static size_t	parse_minwidth(const char *format, size_t i, t_format *form)
{
	if (ft_isdigit(format[i]))
	{
		form->minimum_width = ft_atoi(format + i);
		while (format[i] && (format[i] <= '9' && format[i] >= '0'))
			i++;
	}
	return (i);
}


static size_t	parse_precision(const char *format, size_t i, t_format *form)
{
	if (format[i] && format[i] == '.')
	{
		i++;
		if (ft_isdigit(format[i]))
		{
			form->precision = ft_atoi(format + i);
			while (format[i] && (format[i] <= '9' && format[i] >= '0'))
				i++;
		}
	}
	return (i);
}

static size_t 	  set_SDOUC(const char *f, size_t i, t_format *form)
{
	form->conversion.flag = L;
	if (f[i] == 'S')
		form->conversion.type = STRING;
	else if (f[i] == 'C')
		form->conversion.type = CHAR;
	else if (ft_str_contains_chr("DOU", f[i]))
	{
		form->conversion.type = DECIMAL;
		if (f[i] == 'O')
			form->conversion.an_unsigned = o;

		else if (f[i] == 'U')
			form->conversion.an_unsigned = u;
	}
}

static size_t	parse_conversions_flags(const char *f, size_t i, t_format *form)
{
	if (f[i] == 'h')
	{
		if (f[i + 1] == 'h')
		{
			i++;
			form->conversion.flag = HH;
		}
		else
			form->conversion.flag = H;
	}
	else if (f[i] == 'l')
	{
		if (f[i + 1] == 'l')
		{
			i++;
			form->conversion.flag = LL;
		}
		else
			form->conversion.flag = L;
	}
	else if (f[i] == 'j')
		form->conversion.flag = J;
	else if (f[i] == 'z')
		form->conversion.flag = Z;
	else
		return (i);
	return (i + 1);
}

static size_t	parse_conversions(const char *f, size_t i, t_format *form)
{
	if (f[i] == 's')
		form->conversion.type = STRING;
	else if (f[i] == 'c')
		form->conversion.type = CHAR;
	else if (f[i] == 'p')
		form->conversion.type = POINTER;
	else if (ft_str_contains_chr("diouxX", f[i]))
	{
		form->conversion.type = DECIMAL;
		if (f[i] == 'o')
			form->conversion.an_unsigned = o;
		else if (f[i] == 'u')
			form->conversion.an_unsigned = u;
		else if (f[i] == 'x')
			form->conversion.an_unsigned = x;
		else if (f[i] == 'X')
			form->conversion.an_unsigned = X;
	}
	else if (ft_str_contains_chr("SDOUC", f[i]))
		set_SDOUC(f, i, form);
	else
		form->conversion.undefined = f[i];
	return (i + 1);
}

size_t		parser(const char *format, size_t i, va_list valist)
{
	t_format	*form;

	form = create_form();
	i = parse_flags(format, i, form);
	i = parse_minwidth(format, i, form);
	i = parse_flags(format, i, form);
	i = parse_precision(format, i, form);
	i = parse_flags(format, i, form);
	i = parse_conversions_flags(format, i, form);
	i = parse_conversions(format, i, form);
	put_form(form, valist);
	return (i);
}