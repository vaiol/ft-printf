
#ifndef FT_HANDLERS_H
#define FT_HANDLERS_H

#include "../ft_put/ft_put.h"
#include "../ft_printf.h"
#include <stdarg.h>
#include <ntsid.h>
#include <stddef.h>

size_t	handle_conversions(const char *str, size_t i, va_list valist);

#endif
