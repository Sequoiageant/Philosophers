# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/16 14:51:18 by julnolle          #+#    #+#              #
#    Updated: 2020/08/16 15:02:15 by julnolle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo_one

# ---------------- CC ---------------- #

CC	= clang

CFLAGS +=	-Wall
CFLAGS +=	-Wextra

ifneq ($(err), no)
	CFLAGS += -Werror
endif

ifeq ($(debug), 0)
	CFLAGS += -g3
else ifeq ($(debug), 1)
	CFLAGS += -fsanitize=address,undefined
	CFLAGS += -g3
else ifeq ($(debug), 2)
	CFLAGS += -fsanitize=address,undefined
	CFLAGS += -g3
	CFLAGS += -ansi
	CFLAGS += -pedantic
else ifeq ($(debug), 3)
	CFLAGS += -fsanitize=address,undefined
	CFLAGS += -g3
	CFLAGS += -ansi
	CFLAGS += -pedantic
	CFLAGS += -Wpadded
else ifeq ($(debug), 4)
	CFLAGS += -fsanitize=address,undefined
	CFLAGS += -g3
	CFLAGS += -ansi
	CFLAGS += -pedantic
	CFLAGS += -Wpadded
	CFLAGS += -Weverything
endif

# ---------------- COL --------------- #

_RED		= \033[1;31m
_GREEN		= \033[1;32m
_YELLOW		= \033[1;33m
_END		= \033[0m

# ---------------- SRC --------------- #

# Debug Sources
# SRCS += debug.c

# Main Sources
SRCS += main.c

vpath %.c ./

# ---------------- INC --------------- #

INCLUDES 	=	../includes/
HEAD 		= $(INCLUDES)philo.h
ALL_INC		=  -I$(INCLUDES)

# ---------------- OBJ --------------- #

DIR_OBJS	= ./objs/
OBJS		= $(patsubst %.c, $(DIR_OBJS)%.o, $(SRCS))

# --------- Compilation Rules -------- #

all: $(NAME)

fast:
	$(MAKE) re -j8

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(ALL_INC) -o $@
			@echo "$(_BOLD)$(_YELLOW)==> $@ linked$(_END)"

$(OBJS): 	$(DIR_OBJS)%.o: %.c $(HEAD) Makefile | $(DIR_OBJS)
			$(CC) $(CFLAGS) $(ENV) -c $< -o $@ $(ALL_INC)
			@echo "$(_BOLD)$(_GREEN)--> $@ made$(_END)"

$(DIR_OBJS):
	mkdir -p $@

clean:
	$(RM) -R $(DIR_OBJS)
	@echo "$(_BOLD)$(_RED)-> $@ made$(_END)"

fclean: clean
	$(RM) $(NAME)
	@echo "$(_BOLD)$(_RED)-> $@ made$(_END)"

re: fclean
	$(MAKE)

.PHONY:		all clean fclean re bonus
.SILENT:	$(OBJS) $(DIR_OBJS) $(NAME)
