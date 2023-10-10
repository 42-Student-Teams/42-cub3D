# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/27 11:02:33 by lsaba-qu          #+#    #+#              #
#    Updated: 2023/03/28 23:54:25 by lsaba-qu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libft.a

#------------------------------------------------#
#   INGREDIENTS                                  #
#------------------------------------------------#
# SRC_DIR   source directory
# SRCS      source files
#
# BUILD_DIR object directory
# OBJS      object files
# DEPS      dependency files
#
# CC        compiler
# CFLAGS    compiler flags
# CPPFLAGS  preprocessor flags

SRC_DIR		:= src
SRCS	:= \
	ft_tolower.c				\
	ft_strlen.c					\
	ft_isascii.c				\
	ft_isalpha.c				\
	ft_isprint.c				\
	ft_isdigit.c				\
	ft_isalnum.c				\
	ft_bzero.c					\
	ft_memset.c					\
	ft_strncmp.c				\
	ft_memcpy.c					\
	ft_strchr.c					\
	ft_atoi.c					\
	ft_strrchr.c				\
	ft_strlcpy.c				\
	ft_strlcat.c				\
	ft_strnstr.c				\
	ft_memchr.c					\
	ft_memmove.c				\
	ft_memcmp.c					\
	ft_calloc.c					\
	ft_strdup.c					\
	ft_strjoin.c				\
	ft_itoa.c					\
	ft_substr.c					\
	ft_strtrim.c				\
	ft_split.c					\
	ft_putchar_fd.c				\
	ft_putstr_fd.c				\
	ft_putendl_fd.c				\
	ft_putnbr_fd.c				\
	ft_striteri.c				\
	ft_printbase.c				\
	ft_printf.c					\
	ft_printfutils.c			\
	ft_lstadd_front.c			\
	ft_lstnew.c					\
	ft_lstsize.c				\
	ft_lstlast.c				\
	ft_lstadd_back.c			\
	ft_lstdelone.c				\
	ft_lstclear.c				\
	ft_lstiter.c				\
	ft_lstmap.c					\
	ft_garbage_collector.c		\
	ft_allok.c					\
	ft_doublons_ia.c			\
	ft_all_are_num.c			\
	ft_isnum.c					\
	ft_atoilong.c				\
	ft_putchar.c				\
	ft_putstr.c					\
	ft_putendl.c				\
	ft_putnbrendl.c				\
	ft_putnbr.c					\
	ft_swap.c					\
	ft_strcmp.c					\
	ft_indexof_iarr.c			\
	ft_find_min.c				\
	ft_wordcount.c				\
	ft_find_max.c				\
	ft_find_pivot.c				\
	ft_free_pp.c				\
	ft_alloc.c					\
	ft_get_next_line_utils.c	\
	ft_get_next_line.c			\
	ft_putnbrendl_fd.c			
	
SRCS		:= $(SRCS:%=$(SRC_DIR)/%)

BUILD_DIR	:= .build
OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror
CPPFLAGS	:= -I include
AR			:= ar
ARFLAGS		:= -r -c -s

#------------------------------------------------#
#   UTENSILS                                     #
#------------------------------------------------#
# RM        force remove
# MAKEFLAGS make flags
# DIR_DUP   duplicate directory tree

RM          := rm -rf
MAKEFLAGS   += --no-print-directory
DIR_DUP     = mkdir -p $(@D)

#------------------------------------------------#
#   RECIPES                                      #
#------------------------------------------------#
# all       default goal
# $(NAME)   link .o -> library
# %.o       compilation .c -> .o
# clean     remove .o
# fclean    remove .o + binary
# re        remake default goal

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	$(info CREATED $(NAME))

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)

clean:
	$(RM) $(OBJS) $(BUILD_DIR)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all


.PHONY: clean fclean re
.SILENT: