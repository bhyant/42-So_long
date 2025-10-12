# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbhuiyan <tbhuiyan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/12 22:50:00 by tbhuiyan          #+#    #+#              #
#    Updated: 2025/10/12 23:17:58 by tbhuiyan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCDIR = srcs
INCDIR = includes
LIBFTDIR = libft
MLXDIR = minilibx-linux
OBJDIR = .obj

MAIN_SRC = main.c

GAME_SRC = game/control.c \
           game/display.c \
           game/gameplay.c \
           game/setup.c

PARSING_SRC = parsing/check_map.c \
              parsing/flood_fill.c

UTILS_SRC = utils/cleanup.c \
            utils/error.c \
            utils/game_utils.c \
            utils/map_utils.c \
            utils/parse_utils.c

ALL_SRC = $(MAIN_SRC) $(GAME_SRC) $(PARSING_SRC) $(UTILS_SRC)

OBJS = $(ALL_SRC:%.c=$(OBJDIR)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
INCLUDES = -I$(INCDIR) -I$(LIBFTDIR)/includes -I$(MLXDIR)

LIBFT = $(LIBFTDIR)/libft.a
LIBFT_SRCS = $(LIBFTDIR)/ft_atoi.c \
             $(LIBFTDIR)/ft_bzero.c \
             $(LIBFTDIR)/ft_calloc.c \
             $(LIBFTDIR)/ft_isalnum.c \
             $(LIBFTDIR)/ft_isalpha.c \
             $(LIBFTDIR)/ft_isascii.c \
             $(LIBFTDIR)/ft_isdigit.c \
             $(LIBFTDIR)/ft_isprint.c \
             $(LIBFTDIR)/ft_itoa.c \
             $(LIBFTDIR)/ft_lstadd_back_bonus.c \
             $(LIBFTDIR)/ft_lstadd_front_bonus.c \
             $(LIBFTDIR)/ft_lstclear_bonus.c \
             $(LIBFTDIR)/ft_lstdelone_bonus.c \
             $(LIBFTDIR)/ft_lstiter_bonus.c \
             $(LIBFTDIR)/ft_lstlast_bonus.c \
             $(LIBFTDIR)/ft_lstmap_bonus.c \
             $(LIBFTDIR)/ft_lstnew_bonus.c \
             $(LIBFTDIR)/ft_lstsize_bonus.c \
             $(LIBFTDIR)/ft_memchr.c \
             $(LIBFTDIR)/ft_memcmp.c \
             $(LIBFTDIR)/ft_memcpy.c \
             $(LIBFTDIR)/ft_memmove.c \
             $(LIBFTDIR)/ft_memset.c \
             $(LIBFTDIR)/ft_putchar_fd.c \
             $(LIBFTDIR)/ft_putendl_fd.c \
             $(LIBFTDIR)/ft_putnbr_fd.c \
             $(LIBFTDIR)/ft_putstr_fd.c \
             $(LIBFTDIR)/ft_split.c \
             $(LIBFTDIR)/ft_strchr.c \
             $(LIBFTDIR)/ft_strdup.c \
             $(LIBFTDIR)/ft_striteri.c \
             $(LIBFTDIR)/ft_strjoin.c \
             $(LIBFTDIR)/ft_strlcat.c \
             $(LIBFTDIR)/ft_strlcpy.c \
             $(LIBFTDIR)/ft_strlen.c \
             $(LIBFTDIR)/ft_strmapi.c \
             $(LIBFTDIR)/ft_strncmp.c \
             $(LIBFTDIR)/ft_strnstr.c \
             $(LIBFTDIR)/ft_strrchr.c \
             $(LIBFTDIR)/ft_strtrim.c \
             $(LIBFTDIR)/ft_substr.c \
             $(LIBFTDIR)/ft_tolower.c \
             $(LIBFTDIR)/ft_toupper.c \
             $(LIBFTDIR)/42-get_next_line/get_next_line.c \
             $(LIBFTDIR)/42-get_next_line/get_next_line_bonus.c \
             $(LIBFTDIR)/42-get_next_line/get_next_line_utils.c \
             $(LIBFTDIR)/42-get_next_line/get_next_line_utils_bonus.c \
             $(LIBFTDIR)/42-printf/ft_convert.c \
             $(LIBFTDIR)/42-printf/ft_convert2.c \
             $(LIBFTDIR)/42-printf/ft_printf.c

MLX = $(MLXDIR)/libmlx.a
MLX_FLAGS = -L$(MLXDIR) -lmlx -lXext -lX11 -lm
LIBS = $(LIBFT) $(MLX) $(MLX_FLAGS)

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
RESET = \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@echo "$(YELLOW)Linking $(NAME)...$(RESET)"
	@$(CC) $(OBJS) $(LIBS) -o $(NAME)
	@echo "$(GREEN)✅ $(NAME) compiled successfully!$(RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@echo "$(BLUE)Compiling $<...$(RESET)"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)
	@mkdir -p $(OBJDIR)/game
	@mkdir -p $(OBJDIR)/parsing
	@mkdir -p $(OBJDIR)/utils

$(LIBFT): $(LIBFT_SRCS)
	@echo "$(YELLOW)Building libft...$(RESET)"
	@$(MAKE) -C $(LIBFTDIR) --no-print-directory

$(MLX):
	@echo "$(YELLOW)Building minilibx...$(RESET)"
	@$(MAKE) -C $(MLXDIR) --no-print-directory

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -rf $(OBJDIR)
	@$(MAKE) -C $(LIBFTDIR) clean --no-print-directory
	@echo "$(GREEN)✅ Object files cleaned!$(RESET)"

fclean: clean
	@echo "$(RED)Cleaning executable...$(RESET)"
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFTDIR) fclean --no-print-directory
	@echo "$(GREEN)✅ Executable cleaned!$(RESET)"

re: fclean all