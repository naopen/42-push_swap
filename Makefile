# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/01 12:08:09 by nkannan           #+#    #+#              #
#    Updated: 2024/06/04 05:30:27 by nkannan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SANITIZE = -fsanitize=address -g

LIBFT = libft/libft.a
LIBFT_DIR = libft

SRC_DIR = srcs
OBJ_DIR = objs
INC_DIR = includes
SRCS = args.c errors.c init_free.c main.c sort.c sort_small.c sort_large.c utils.c \
		actions/push.c actions/rotate.c actions/swap.c actions/rev_rotate.c
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
NAME = push_swap

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(LIBFT) $(CFLAGS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -rf $(NAME).dSYM
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

leak: $(LIBFT)
	$(CC) $(SRCS:%=$(SRC_DIR)/%) $(LIBFT) $(CFLAGS) $(SANITIZE) -I$(INC_DIR) -I$(LIBFT_DIR) -o $(NAME)
	./$(NAME) 2 1 0