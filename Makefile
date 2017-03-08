# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astepano <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/03 15:03:21 by astepano          #+#    #+#              #
#    Updated: 2017/03/08 20:42:11 by astepano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FOLDER = libft/
NAME = libftprintf.a
DEL = deleted_folder_everrr

all: $(NAME)

$(NAME):
	make -C $(FOLDER)
	cp $(FOLDER)$(NAME) .

clean:
	make -C $(FOLDER) clean

fclean: clean
	make -C $(FOLDER) fclean
	rm -f $(NAME)

pre_re:
	rm -rf $(DEL)
	touch $(NAME)
	mkdir $(DEL)
	mv $(NAME) $(DEL)
 
post_re:
	rm -rf $(DEL)

re: fclean pre_re all post_re
