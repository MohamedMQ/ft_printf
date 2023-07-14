# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/20 10:15:12 by mmaqbour          #+#    #+#              #
#    Updated: 2022/12/20 10:15:14 by mmaqbour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc

NAME	=	libftprintf.a

SRCS	=	ft_printf.c ft_printf_utils.c

BONUS	=	ft_printf_bonus.c ft_printf_utils_bonus.c ft_printf_utils2_bonus.c

OBJS	=	$(SRCS:.c=.o)

BOJS	=	$(BONUS:.c=.o)

CFLAGS	=	-Wall -Werror -Wextra

RM		=	rm -f

ARCH	=	ar rc

all:		$(NAME)

$(NAME):	
		$(CC) -c $(CFLAGS) $(SRCS)
		$(ARCH) $(NAME) $(OBJS)

bonus:		
		$(CC) -c $(CFLAGS) $(BONUS)
		$(ARCH) $(NAME) $(BOJS)

clean:
	$(RM) $(OBJS) $(BOJS)

fclean:		clean
	$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re bonus
