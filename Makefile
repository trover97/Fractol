# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/25 18:03:20 by wquirrel          #+#    #+#              #
#    Updated: 2020/02/25 19:27:41 by wquirrel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC =	main.c \
		complex.c \
		contorl.c \
		draw.c \
		fractals.c \
		mandel_julia.c \
		mouse.c \
		multithreading.c \
		utils.c
OBJ = $(SRC:.c=.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror

LIB = ./libft/
LIB_INK = -I ./libft
LIBFT =	libft/libft.a

MLX_LNK = -L minilibx_macos -lmlx -framework OpenGL -framework AppKit

SRCDIR	= ./sources/
INKDIR	= ./includes/
OBJDIR	= ./obj/

all: $(NAME)