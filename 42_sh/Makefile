#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/18 16:09:20 by bboumend          #+#    #+#              #
#    Updated: 2014/06/21 16:05:31 by mlingels         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=		42sh

LIB_DIR		=		./libft

LIB_NAME	=		libft.a

INCLUDE_DIR	=		./includes

SRC_DIR		=		./srcs

SRC			=		main.c				\
					ft_minishell.c		\
					ft_pars.c			\
					ft_init_exec.c		\
					ft_path.c			\
					ft_error.c			\
					ft_exec.c			\
					ft_environ.c		\
					ft_cd.c				\
					ft_cd2.c			\
					ft_cd_ftab.c		\
					ft_cursor.c			\
					ft_echo.c			\
					ft_env.c			\
					ft_exit.c			\
					ft_hist.c			\
					ft_input.c			\
					ft_pid.c			\
					ft_prompt.c			\
					ft_setenv.c			\
					ft_unsetenv.c		\
					ft_builtin_error.c	\
					ft_builtin.c		\
					ft_pars_tools.c		\
					ft_term.c			\
					ft_tools.c			\
					ft_exec_tools.c

OBJ			=		$(SRC:.c=.o)

FLAG_LINK	=		-L$(LIB_DIR) -lft -L /usr/lib -ltermcap

FLAG_COMP	=		-Wall -Wextra -Werror -I$(INCLUDE_DIR)

all: $(LIB_DIR)/$(LIB_NAME) $(NAME)

$(LIB_DIR)/$(LIB_NAME):
	@(cd $(LIB_DIR) && $(MAKE))

$(NAME): $(OBJ)
	gcc -o $@ $^ $(FLAG_LINK)

%.o: $(SRC_DIR)/%.c
	gcc -c $(FLAG_COMP) $^

%.o: $(SRC_DIR)/builtin/%.c
	gcc -c $(FLAG_COMP) $^

clean:
	rm -f $(OBJ)

fcleanlib:
	@(cd $(LIB_DIR) && $(MAKE) fclean)

fclean: clean fcleanlib
	rm -f $(NAME)

re: fcleanlib fclean all
