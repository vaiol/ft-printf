#include "put_form.h"

void 		put_form(t_format *form, va_list valist)
{
	if (form->conversion.type == DECIMAL)
		put_decimal(form, valist);
	else if (form->conversion.type == STRING)
		put_string(form, valist);
	else if (form->conversion.type == CHAR)
		put_char(form, valist);
	else if (form->conversion.type == POINTER)
		ft_putmem(va_arg(valist, void *));
}