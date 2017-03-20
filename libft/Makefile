# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astepano <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/03 15:03:21 by astepano          #+#    #+#              #
#    Updated: 2017/03/08 20:25:18 by astepano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
PRINTF = ft_printf/
PUTCONV = put_conversion/
FLOAT = $(PRINTF)$(PUTCONV)handle/float/
UTIL = $(PRINTF)$(PUTCONV)/util/
CONV = $(PRINTF)$(PUTCONV)/put_
HANDLE = $(PRINTF)$(PUTCONV)/handle/handle_
PUT = $(PRINTF)$(PUTCONV)/put/
PARSE = $(PRINTF)parse_format/parse_

LIB_SRCS = ft_itoa_base.c ft_strcchr.c	ft_strlen.c ft_isdigit.c ft_atoi.c \
		   ft_strjoin.c ft_strdup.c ft_strcut.c ft_tolower.c ft_pow.c ft_abs.c \
		   ft_memset.c ft_atoi_base.c ft_strjoin_free.c ft_isprint.c
PRINTF_SRCS = $(PRINTF)ft_printf.c \
            $(PUT)putstr.c $(PUT)ft_write.c $(PUT)printed_count.c\
		   $(UTIL)strjoinchr_begin.c $(UTIL)strjoinchr.c $(UTIL)winttostr.c \
		   $(UTIL)wstrtostr.c $(UTIL)utoa_base.c $(UTIL)strclear.c \
		   $(UTIL)zerocut.c \
		   $(CONV)unsigned.c $(CONV)signed.c $(CONV)conversion.c \
		   $(CONV)float.c unprintable.c \
		   $(CONV)string.c $(CONV)char.c $(CONV)memory.c $(CONV)printed.c \
		   $(PARSE)all.c  $(PARSE)flags.c $(PARSE)type.c $(PARSE)minwidth.c \
		   $(PARSE)precision.c $(PARSE)size.c $(PARSE)color.c \
		   $(HANDLE)minwidth.c $(HANDLE)precision.c $(HANDLE)apostrophe.c \
		   $(HANDLE)time.c \
		   $(FLOAT)additionals.c $(FLOAT)float.c $(FLOAT)frexpl.c \
		   $(FLOAT)parsers.c $(FLOAT)rounder.c $(FLOAT)handle_e.c \
		   $(FLOAT)handle_f.c $(FLOAT)handle_g.c $(FLOAT)handle_a.c
SRCS = $(LIB_SRCS) $(PRINTF_SRCS)

LIB_OBJS = $(LIB_SRCS:.c=.o)
PRINTF_OBJS = $(PRINTF_SRCS:.c=.o)
OBJS = $(SRCS:.c=.o)

INCLUDES = -I $(PRINTF)ft_printf.h

LIB_NAME = libft.a
PRINTF_NAME = printf.a
NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

$(PRINTF_NAME): $(PRINTF_OBJS)
	ar rc $(PRINTF_NAME) $(PRINTF_OBJS)

$(LIB_NAME): $(LIB_OBJS)
	ar rc $(LIB_NAME) $(LIB_OBJS)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(LIB_NAME) $(PRINTF_NAME)

re: fclean all
