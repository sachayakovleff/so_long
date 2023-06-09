# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/17 02:23:38 by syakovle          #+#    #+#              #
#    Updated: 2023/05/14 18:15:03 by syakovle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
LIBFT = libft/libft.a
PRINTF = printf/ft_printf.a
GNL = getnextline/getnextline.a
MINILIBX = minilibx-linux/libmlx.a

FILES	=	setdata/set			\
			setdata/setmap		\
			free/freesplit		\
			free/free			\
			setdata/checkmap	\
			display/display		\
			checklocation		\
			handledanger		\
			setdata/validchar	\
			checkwin/checkwin	\
			checkwin/setvent

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))


.c.o: $(SRCS)
	$(CC) -g $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(AR) $@ $(OBJS)
	@make all -C libft
	@make all -C printf
	@make all -C getnextline
	@make all -C minilibx-linux
	$(CC) -g $(CFLAGS) ./main.c  $(NAME) minilibx-linux/libmlx.a -lX11 -lXext $(GNL) $(PRINTF) $(LIBFT) -o so_long

all: $(NAME)

clean:
	$(RM) $(OBJS)
	@make clean -C libft
	@make clean -C printf
	@make clean -C getnextline
	@make clean -C minilibx-linux

fclean: clean
	$(RM) $(NAME) so_long
	@make fclean -C libft
	@make fclean -C printf
	@make fclean -C getnextline
	@make fclean -C minilibx-linux
	
re: clean all

.PHONY: all clean fclean re
