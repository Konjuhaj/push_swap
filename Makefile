# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/17 15:14:05 by bkonjuha          #+#    #+#              #
#    Updated: 2020/02/21 21:16:15 by bkonjuha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC_PATH = ./srcs/
SRC_FILES = push_swap.c errno.c printer.c sort_small.c move_functions.c
SRC = $(addprefix $(SRC_PATH), $(SRC_FILES))

OBJ_PATH = ./objs/
OBJ_FILES = $(subst .c,.o,$(SRC_FILES))
OBJS = $(addprefix $(OBJ_PATH), $(OBJ_FILES))

INCLUDES = -I ./includes/
HEADER_PATH = ./includes/
HEADER_FILES = push_swap.h
HEADERS = $(addprefix $(HEADER_PATH), $(HEADER_FILES))
COMPILE = gcc -Wall -Werror -Wextra -g #remove -g flag

LIBFT_PATH = libraries/ft_printf/libft/
LIBFT_FILE = libft.a
LIBFT = $(addprefix $(LIBFT_PATH), $(LIBFT_FILE))
PRINTF_SRCS = libraries/ft_printf/srcs/
PRINTF_PATH = libraries/ft_printf/
PRINTF_FILE = libftprintf.a
PRINTF = $(addprefix $(PRINTF_PATH), $(PRINTF_FILE))

COLOR_RESET = \033[0m
COLOR_PENDING = \033[0;33m
COLOR_SUCCESS = \033[0;32m
COLOR_DEFAULT = \033[1;34m

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS) $(LIBFT) $(PRINTF)
		@$(COMPILE) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)
		@echo "[$(COLOR_PENDING)Putting everything togeather$(COLOR_RESET)]"
		@echo "[$(COLOR_SUCCESS)Executable $(NAME) created$(COLOR_RESET)]"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEADERS)
		@mkdir $(OBJ_PATH) 2>/dev/null || echo "" >/dev/null
		@$(COMPILE) -c $< -o $@ $(INCLUDES)

$(PRINTF) $(LIBFT): $(PRINTF_SRCS)*.c $(LIBFT_PATH)*.c
		@echo "Recompiling libraries"
		@make -C $(PRINTF_PATH)

clean:
		@rm -fv $(OBJS) >/dev/null
		@rm -rf $(OBJ_PATH) > /dev/null
		@make clean -C libraries/ft_printf/ >/dev/null

fclean: clean
		@rm -fv $(NAME) > /dev/null
		@make fclean -C libraries/ft_printf/ >/dev/null

re: fclean all

.PHONY = all clean fclean re
