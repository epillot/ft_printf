# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: epillot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/14 19:24:31 by epillot           #+#    #+#              #
#    Updated: 2016/12/21 16:41:23 by epillot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAG = -Wall -Wextra -Werror

OPTION = -c

SRC = find_conv_id.c\
	  get_option.c\
	  get_param.c\
	  is_format_info.c\
	  d_to_formated_string.c\
	  u_to_formated_string.c\
	  c_to_formated_string.c\
	  wc_to_formated_string.c\
	  ws_to_formated_string.c\
	  s_to_formated_string.c\
	  nb_convert.c\
	  char_convert.c\
	  string_format.c\
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
