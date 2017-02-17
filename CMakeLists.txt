cmake_minimum_required(VERSION 3.6)
project(ft_printf)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
    ft_printf.c
    ft_printf.h
        main.c
        ft_put/ft_put.h
        ft_put/ft_putnbr.c
        ft_put/ft_putchar.c
        ft_put/ft_putstr.c
        ft_put/ft_write.c
        libft/ft_itoa_base.c
        libft/libft.h
        libft/ft_str_contains_chr.c
        libft/ft_strlen.c
        libft/ft_isdigit.c
        libft/ft_atoi.c
        libft/ft_strjoin.c
        libft/ft_nbrlen.c
        parser/format_parser.c
        put_form/put_decimal.c
        put_form/put_unsigned.c
        put_form/put_form.h
        put_form/put_signed.c
        put_form/put_form.c
        put_form/put_string.c
        put_form/put_char.c
#        put_form_info/put_form_info.c
#        put_form_info/put_form_info.h
#        ft_handlers/ft_handlers.c
#        ft_handlers/ft_handlers.h
        )

add_executable(ft_printf ${SOURCE_FILES})