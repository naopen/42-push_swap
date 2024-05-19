# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/01 12:08:09 by nkannan           #+#    #+#              #
#    Updated: 2024/05/19 10:57:10 by nkannan          ###   ########.fr        #
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
SRCS = args.c errors.c init_free.c main.c sort.c sort_small.c sort_large.c transfer.c utils.c \
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
	./$(NAME) 100 99 98 97 96 95 94 93 92 91 90 89 88 87 86 85 84 83 82 81 80 79 78 77 76 75 74 73 72 71 70 69 68 67 66 65 64 63 62 61 60 59 58 57 56 55 54 53 52 51 50 49 48 47 46 45 44 43 42 41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1