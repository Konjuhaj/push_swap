# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/17 15:14:05 by bkonjuha          #+#    #+#              #
#    Updated: 2020/03/08 15:34:57 by bkonjuha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP = push_swap
CHECKER = checker

SRC_PATH = ./srcs/
SRC_FILES = errno.c printer.c sort_small.c move_functions.c helper.c scan_stack.c sort_big.c \
			validate.c read_input.c
SRC = $(addprefix $(SRC_PATH), $(SRC_FILES))

MAIN_PATH = ./mains/
PS_MAIN = push_swap.c
C_MAIN = checker.c
PS = $(addprefix $(MAIN_PATH), $(PS_MAIN))
C = $(addprefix $(MAIN_PATH), $(C_MAIN))

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

all: $(PUSH_SWAP) $(CHECKER)

$(PUSH_SWAP): $(HEADERS) $(LIBFT) $(PRINTF)
		@$(COMPILE) $(PS) $(SRC) $(LIBFT) $(PRINTF) -o $(PUSH_SWAP)
		@$(COMPILE) $(C) $(SRC) $(LIBFT) $(PRINTF) -o $(CHECKER)
		@echo "[$(COLOR_PENDING)Putting everything togeather$(COLOR_RESET)]"
		@echo "[$(COLOR_SUCCESS)Executable $(PUSH_SWAP) created$(COLOR_RESET)]"

$(PRINTF) $(LIBFT): $(PRINTF_SRCS)*.c $(LIBFT_PATH)*.c
		@echo "Recompiling libraries"
		@make -C $(PRINTF_PATH)

clean:
		@make clean -C libraries/ft_printf/ >/dev/null

fclean: clean
		@rm -fv $(PUSH_SWAP) > /dev/null
		@make fclean -C libraries/ft_printf/ >/dev/null

re: fclean all

.PHONY = all clean fclean re
