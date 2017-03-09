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
LIB = $(PRINTF)lib/
PUT = $(PRINTF)put_format/put_
HANDLE = $(PRINTF)put_format/handle/handle_
PARSE = $(PRINTF)parse_format/parse_

LIB_SRCS = ft_itoa_base.c ft_strcchr.c	ft_strlen.c ft_isdigit.c ft_atoi.c \
		   ft_strjoin.c ft_strdup.c ft_strcut.c ft_tolower.c
PRINTF_SRCS = $(PRINTF)ft_printf.c $(LIB)lib_putstr.c $(LIB)lib_write.c \
           $(LIB)lib_utoa_base.c \
		   $(LIB)strjoinchr_begin.c $(LIB)strjoinchr.c $(LIB)lib_wint_to_str.c \
		   $(LIB)lib_wchar_to_str.c \
		   $(LIB)lib_get_apostrophe.c $(LIB)lib_strclear.c \
		   $(PUT)decimal.c $(PUT)unsigned.c $(PUT)signed.c $(PUT)format.c \
		   $(PUT)string.c $(PUT)char.c $(PUT)memory.c \
		   $(PARSE)all.c  $(PARSE)flags.c $(PARSE)type.c $(PARSE)minwidth.c \
		   $(PARSE)precision.c $(PARSE)size.c \
		   $(HANDLE)minwidth.c $(HANDLE)precision.c
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
