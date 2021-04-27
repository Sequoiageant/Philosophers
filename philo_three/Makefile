# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/16 14:51:18 by julnolle          #+#    #+#              #
#    Updated: 2021/04/27 19:39:42 by julnolle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo_three

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

_END		= \033[0m
_BOLD		= \033[1m

_RED		= \033[31m
_GREEN		= \033[32m
_YELLOW		= \033[33m

# ---------------- SRC --------------- #

# Common Sources
SRCS += ft_utils.c
SRCS += ft_checks.c
SRCS += philo_utils.c

# Main Sources
SRCS += main.c
SRCS += philo_two_utils.c
SRCS += philo_two_states.c
SRCS += death_check.c
SRCS += philo_threads.c

vpath %.c ./
vpath %.c ../common_srcs/

# ---------------- INC --------------- #

INCLUDES 	=	../includes/
HEADER 		=	$(INCLUDES)philo.h
HEADER 		+=	$(INCLUDES)philo_two.h
ALL_INC		=	-I$(INCLUDES)
LIB_LINK	=	-lpthread

# ---------------- OBJ --------------- #

DIR_OBJS	= ./objs/
OBJS		= $(patsubst %.c, $(DIR_OBJS)%.o, $(SRCS))

# --------- Compilation Rules -------- #

all: $(NAME)

fast:
	$(MAKE) re -j8

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(ALL_INC) $(LIB_LINK) -o $@
			echo "$(_BOLD)$(_YELLOW)==> $@ linked$(_END)"

$(OBJS): 	$(DIR_OBJS)%.o: %.c $(HEADER) Makefile | $(DIR_OBJS)
			$(CC) $(CFLAGS) $(ENV) -c $< -o $@ $(ALL_INC)
			echo "$(_BOLD)$(_GREEN)--> $@ made$(_END)"

$(DIR_OBJS):
	mkdir -p $@

clean:
	$(RM) -R $(DIR_OBJS)
	echo "$(_BOLD)$(_RED)-> $@ $(NAME) made$(_END)"

fclean: clean
	$(RM) $(NAME)
	echo "$(_BOLD)$(_RED)-> $@ $(NAME) made$(_END)"

re: fclean
	$(MAKE)

.PHONY:		all fast clean fclean re
.SILENT:	$(NAME) $(OBJS) $(DIR_OBJS) clean fclean
