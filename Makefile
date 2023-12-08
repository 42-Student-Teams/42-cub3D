NAME	= cub3D

#------------------------------------------------#
#   INGREDIENTS                                  #
#------------------------------------------------#
# LIBS        libraries to be used
# LIBS_TARGET libraries to be built
#
# INCS        header file locations
#
# SRC_DIR     source directory
# SRCS        source files
#
# BUILD_DIR   build directory
# OBJS        object files
# DEPS        dependency files
#
# CC          compiler
# CFLAGS      compiler flags
# CPPFLAGS    preprocessor flags
# LDFLAGS     linker flags
# LDLIBS      libraries name

LIBS        := ft
LIBS_TARGET := 				\
	libft/libft.a

INCS        := include		\
	libft/include			\

SRC_DIR     := src
SRCS		:= \
	src/main.c							\
	src/message.c						\
	src/check/check.c					\
	src/check/check_utils.c				\
	src/movement/hook.c					\
	src/movement/move.c					\
	src/parse/parse_map.c				\
	src/parse/parse_texture.c			\
	src/parse/init.c					\
	src/parse/parse_utils.c				\
	src/game/init_game.c				\
	src/game/calculs.c					\
	src/game/draw.c						\
	src/parse/parse_texture_utils.c		\
	src/parse/parse_texture_utils2.c	\
	src/parse/parse_texture_utils3.c	\

BUILD_DIR   := .build
OBJS        := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

CC          := gcc
CFLAGS      := -Wall -Wextra -Werror -O3 -fsanitize=address -g3
CPPFLAGS    := $(addprefix -I,$(INCS))
LDFLAGS     := $(addprefix -L,$(dir $(LIBS_TARGET)))
LDLIBS      := $(addprefix -l,$(LIBS))


# Compile la MiniLibX suivant l'OS
ifeq (${shell uname}, Linux)
	DIR_MLX = mlx_linux/
	MLX_LNK	= -L $(DIR_MLX) -lmlx -lXext -lX11 -lbsd -lm
else
	DIR_MLX = mlx_macos/
	MLX_LNK	= -L $(DIR_MLX) -l mlx -framework OpenGL -framework AppKit
endif

MLX_INC = -I ${DIR_MLX}
MLX =	${DIR_MLX}libmlx.a
LIBMLX = ${LDFLAGS} ${MLX_LNK}

#------------------------------------------------#
#   UTENSILS                                     #
#------------------------------------------------#
# RM        force remove
# MAKEFLAGS make flags
# DIR_DUP   duplicate directory tree

RM          := rm -rf
#MAKEFLAGS   += --silent --no-print-directory
DIR_DUP     = mkdir -p $(@D)

#------------------------------------------------#
#   RECIPES                                      #
#------------------------------------------------#
# all       default goal
# $(NAME)   link .o -> archive
# $(LIBS)   build libraries
# %.o       compilation .c -> .o
# clean     remove .o
# fclean    remove .o + binary
# re        remake default goal
# run       run the program
# info      print the default goal recipe

all: $(NAME)

$(NAME): $(OBJS) $(MLX) $(LIBS_TARGET)
	$(CC) $(CFLAGS) $(LIBMLX) $(OBJS) $(LDLIBS) -o $(NAME)
	$(info CREATED $(NAME))

$(LIBS_TARGET):
	$(MAKE) -C $(@D)

$(MLX):
	$(MAKE) -C $(@D)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(MLX_INC) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)


clean:
	for f in $(dir $(LIBS_TARGET)); do $(MAKE) -C $$f clean; done
	$(RM) $(OBJS) $(BUILD_DIR)

libclean:
	$(MAKE) -C $(DIR_MLX) clean

fclean: clean libclean
	for f in $(dir $(LIBS_TARGET)); do $(MAKE) -C $$f fclean; done
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re
.SILENT:
