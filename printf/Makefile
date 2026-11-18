# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/23 11:23:32 by vldryga           #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2026/11/17 17:07:32 by vldryga          ###   ########.fr        #
=======
#    Updated: 2026/11/16 11:45:13 by arbernad         ###   ########.fr        #
>>>>>>> bucket_opti
#                                                                              #
# **************************************************************************** #

CC := cc
CFLAGS := -Wall -Werror -Wextra -I. -g
NAME := libftprintf.a
SRCS := ft_printf.c \
		formating_chars.c \
		formating_nb.c \
		formating_hexa.c
OBJS := $(SRCS:.c=.o)
LIBFT := ../libft/libft.a
<<<<<<< HEAD
INCLUDES := libft/libft.h ft_printf.h
=======
INCLUDES := ../libft/libft.h ft_printf.h
>>>>>>> bucket_opti

all : $(NAME)

$(NAME): $(OBJS)
<<<<<<< HEAD
=======
	$(MAKE) -C ../libft
>>>>>>> bucket_opti
	cp $(LIBFT) $(NAME)
	ar -rcs $(NAME) $(OBJS)

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
<<<<<<< HEAD
	rm -rf $(OBJS)

fclean : clean
=======
	make clean -C ../libft
	rm -rf $(OBJS)

fclean : clean
	make fclean -C ../libft
>>>>>>> bucket_opti
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
