# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astepano <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/03 15:03:21 by astepano          #+#    #+#              #
#    Updated: 2017/02/13 15:59:13 by astepano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
SRCS =  ft_printf.c                                              \
         ft_put/ft_putstr.c ft_put/ft_write.c                \
        libft/ft_itoa_base.c libft/libft.h libft/ft_strcchr.c               \
        libft/ft_strlen.c libft/ft_isdigit.c libft/ft_atoi.c                \
        libft/ft_strjoin.c libft/ft_nbrlen.c libft/ft_strdup.c              \
        libft/ft_wint_to_str.c libft/ft_wchar_to_str.c libft/ft_strcut.c    \
        libft/ft_utoa_base.c libft/ft_tolower.c                             \
        put_form/put_decimal.c put_form/put_unsigned.c   \
        put_form/put_signed.c put_form/put_form.c put_form/put_string.c     \
        put_form/put_char.c put_form/put_apostrophe.c                       \
        parser/parse_all.c  parser/parse_flags.c          \
        parser/parse_type.c parser/parse_minwidth.c                         \
        parser/parse_precision.c parser/parse_modifier.c

OBJS = $(SRCS:.c=.o)
INCLUDES = -I ft_printf.h ft_put/ft_put.h put_form/put_form.h parser/parse_all.h
NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
