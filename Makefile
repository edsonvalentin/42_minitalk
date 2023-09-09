# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evalenti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/09 12:29:19 by evalenti          #+#    #+#              #
#    Updated: 2023/09/09 12:29:36 by evalenti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME =  

SRCS = client.c server.c

BONUS = client_bonus.c server_bonus.c

OBJS = $(SRCS:.c=.o)

CC		= cc
RM		= /bin/rm -rf
CFLAGS	= -Wall -Wextra -Werror -I $(INC)

INC	= ./
CL = ar -rc
RL = ar -s

$(NAME):	$(OBJS)
	$(CL)	$(NAME)	$(OBJS)
	$(RL)	$(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM)	$(NAME)

re: fclean all

norm:
	norminette -R CheckForbiddenSourceHeader *.c
	norminette -R CheckDefine *.h

.PHONY: all clean fclean re
