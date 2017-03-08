# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astepano <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/03 15:03:21 by astepano          #+#    #+#              #
#    Updated: 2017/03/08 19:03:12 by astepano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FOLDER = libft/
NAME = libftprintf.a

all: $(NAME)

$(NAME): copy
	cp $(FOLDER)$(NAME) .

copy:
	make -C $(FOLDER)

clean:
	make -C $(FOLDER) clean

fclean: clean
	make -C $(FOLDER) fclean
	rm -f $(NAME)

re: fclean all
