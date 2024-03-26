# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/23 00:12:17 by mapierre          #+#    #+#              #
#    Updated: 2023/05/16 20:12:42 by mapierre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAGS = -Wall -Werror -Wextra

SRC =		main.c		\
			parsing.c	\
			lst_utils.c	\
			ft_move.c \
			ft_sort.c\
			pretri.c\
			count_move.c\
			do_move.c\
			utils.c\

OBJS = $(SRC:.c=.o)

LIBF = make -C ./libft

.c.o :
		cc $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME) : $(OBJS)
			$(LIBF)
			cc $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)

lib :
		$(LIBF)

all : $(NAME)

clean :
		rm -f $(OBJS)
fclean : clean
		rm -f $(NAME)
		cd ./libft && make fclean

re: fclean all

.PHONY: all clean fclean re lib
