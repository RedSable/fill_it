# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aapricot <aapricot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/31 19:04:48 by aapricot          #+#    #+#              #
#    Updated: 2019/11/12 22:40:20 by aapricot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -I.
LIBFT_DIR := libft/
NAME := fillit
SRCS := main.c ft_reader.c solution.c
OBJECTS := $(SRCS:.c=.o)
all: $(NAME)
$(NAME): $(OBJECTS)
	make -C $(LIBFT_DIR)
	gcc -o $(NAME) $(OBJECTS) -L$(LIBFT_DIR) -lft
$(OBJECTS): %.o: %.c
	gcc $(CFLAGS) -o $@ -c $<
clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJECTS)
fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)
	rm -f libft.a
re: fclean all
