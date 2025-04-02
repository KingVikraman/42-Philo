# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/02 18:42:29 by rvikrama          #+#    #+#              #
#    Updated: 2025/04/02 20:24:22 by rvikrama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Generics 
PHONY: all clean fclean re

# Compilers.

CC 				= clang
CFLAGS 			= $(COMP) $(DEBUGS) $(THREAD_DEBUG) -I$()
COMP			= -Wall -Werror -Wextra
DEBUGS			= -g3
THREAD_DEBUG	= -fsanitize=thread
MEMORY_DEBUG	= -fsanitize=memory
ADRESS_DEBUG	= -fsanitize=adress
RM				= rm -rf
THREAD_FLAGS	= -pthread


NAME 		= philo


INC_DIR		= includes/
OBJS_DIR	= bin/
SRCS_DIR	= Sources/


SRCS_FILES	=	Sources/error.c	\
				Sources/init.c	\
				Sources/main.c	\
				Sources/parsing_2.c\
				Sources/routines.c\

OBJS_FILES	=	$(patsubst %.c, $(OBJS_DIR)%.o %(SRC_FILES))
#patsubst → A Makefile function that does pattern substitution.

all: $(NAME)

$(NAME) : $(OBJS_FILES)
		$(CC) $(FLAGS) $(CFLAGS) $(OBJ_FILES) -o $(NAME)

$(OBJ_DIR)%.o: %.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)$(SRCS_DIR)

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean $(OBJS_DIR) all



