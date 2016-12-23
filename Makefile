# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: epillot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/14 19:24:31 by epillot           #+#    #+#              #
#    Updated: 2016/12/23 14:45:49 by epillot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAG = -Wall -Wextra -Werror

OPTION = -c

SRC = get_option.c\
	  get_param.c\
	  is_format_info.c\
	  d_convert.c\
	  u_convert.c\
	  c_convert.c\
	  s_convert.c\
	  wc_convert.c\
	  ws_convert.c\
	  str_format.c\
	  encode_unicode.c\
	  tools_for_convert.c\
	  ft_printf.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	make -C libft/
	cp libft/libft.a ./$(NAME)
	gcc $(FLAG) $(OPTION) $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	make fclean -C libft/
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re : fclean all
