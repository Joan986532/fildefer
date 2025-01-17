# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/13 16:14:05 by jnauroy           #+#    #+#              #
#    Updated: 2025/01/17 11:45:54 by jnauroy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SOURCES = fdf.c \
		  parsing_tab.c \
		  fdf_utils.c \
		  get_next_line.c \

OBJECTS = $(SOURCES:.c=.o)

MACROLIBX = minilibx-linux/libmlx_Linux.a

LIBFT = Libft/libft.a

INCLUDE = -lm -lXext -lX11

CFLAGS = -Wall -Wextra -Werror -g

#------------------------------------------------#

all: $(NAME)

$(NAME): $(OBJECTS)
	$(MAKE) -C Libft
	$(MAKE) -C minilibx-linux -j
	cc $(OBJECTS) $(INCLUDE) $(MACROLIBX) $(LIBFT) $(CFLAGS) -o $(NAME)

clean:
	$(MAKE) clean -C Libft
	$(MAKE) clean -C minilibx-linux
	rm -f $(OBJECTS)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: clean fclean re all 
