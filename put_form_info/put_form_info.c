#include "put_form_info.h"

void		put_type(t_type type)
{
	switch (type)
	{
		case DECIMAL: ft_putstr("d");
			break;
		case STRING: ft_putstr("s");
			break;
		case CHAR: ft_putstr("c");
			break;
		case POINTER: ft_putstr("p");
			break;
	}
}

void		put_flag(t_flag flag)
{
	switch (flag)
	{
		case HH: ft_putstr("hh");
			break;
		case H: ft_putstr("h");
			break;
		case L: ft_putstr("l");
			break;
		case LL: ft_putstr("ll");
			break;
		case J: ft_putstr("j");
			break;
		case Z: ft_putstr("z");
			break;
	}
}

void		put_form(t_format *form)
{
	ft_putchar('%');
	if (form->hashtag)
		ft_putchar('#');
	if (form->apostrophe)
		ft_putchar('\'');
	if (form->padding)
		ft_putchar(form->padding);
	if (form->sign)
		ft_putchar(form->sign);
	if (form->minimum_width)
		ft_putnbr(form->minimum_width);
	if (form->precision)
	{
		ft_putchar('.');
		ft_putnbr(form->precision);
	}
}