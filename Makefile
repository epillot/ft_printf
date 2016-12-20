# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: epillot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/14 19:24:31 by epillot           #+#    #+#              #
#    Updated: 2016/12/20 15:49:27 by epillot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAG = -Wall -Wextra -Werror

OPTION = -c

SRC = find_conv_id.c\
	  get_format_info.c\
	  get_param.c\
	  is_format_info.c\
	  itoa_signed_conv.c\
	  itoa_unsigned_conv.c\
	  char_to_formated_string.c\
	  string_convert.c\
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
