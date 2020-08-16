# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/13 14:56:19 by julnolle          #+#    #+#              #
#    Updated: 2020/08/16 15:47:21 by julnolle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philosophers

# ---------------- COL --------------- #

_END		= \033[0m
_BOLD		= \033[1m

# ------------ Directories ----------- #

PHILO_ONE_DIR = ./philo_one/
PHILO_TWO_DIR = ./philo_two/
PHILO_THREE_DIR = ./philo_three/

# --------- Compilation Rules -------- #

all: $(NAME)

fast:
	$(MAKE) re -j8

$(NAME):	
	$(MAKE) -C $(PHILO_ONE_DIR)
	$(MAKE) -C $(PHILO_TWO_DIR)
	$(MAKE) -C $(PHILO_THREE_DIR)
	echo "$(_BOLD)==> All three binaries ready$(_END)"

clean:
	$(MAKE) clean -C $(PHILO_ONE_DIR)
	$(MAKE) clean -C $(PHILO_TWO_DIR)
	$(MAKE) clean -C $(PHILO_THREE_DIR)

fclean:
	$(MAKE) fclean -C $(PHILO_ONE_DIR)
	$(MAKE) fclean -C $(PHILO_TWO_DIR)
	$(MAKE) fclean -C $(PHILO_THREE_DIR)

re: fclean
	$(MAKE)

.PHONY:		all fast clean fclean re
.SILENT:
