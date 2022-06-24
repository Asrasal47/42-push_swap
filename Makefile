# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/13 13:16:21 by arasal            #+#    #+#              #
#    Updated: 2022/06/22 23:22:35 by arasal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler Variables
CC 			= gcc
CFLAGS 		= -Wall -Werror -Wextra
LIB1 		= ar -rcs
RM 			= rm -f
INCLUDE 	= push_swap.h checker_bonus.h get_next_line_bonus.h
LIBFT   	= ./Libft/libft.a

# File Variables
NAME 	=	push_swap
SRCS	=	push_swap.c push_swap2.c push_swap3.c push_swap4.c push_swap5.c \
			push_swap6.c push_swap7.c utils.c utils2.c utils3.c main.c
OBJS 	=	$(SRCS:.c=.o)
B_NAME	=	checker
B_SRCS	=	checker_bonus.c checker2_bonus.c checker3_bonus.c checker4_bonus.c \
			checker5_bonus.c utils_bonus.c utils2_bonus.c utils3_bonus.c \
			checker_main_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c
B_OBJS 	=	$(B_SRCS:.c=.o)

all: $(NAME)

bonus: $(B_NAME)

.o: .c
	@$(CC) ${CFLAGS} ${INCLUDE} -c $< -o $@

$(NAME): $(OBJS) $(INCLUDE)
	@make -C ./libft --silent
	@echo "Libft is compiled"
	@$(CC) -o $(NAME) $(OBJS) $(LIBFT)
	@echo "\033[32mPUSH_SWAP Compiled! ༺ (\033[31m♥\033[32m_\033[31m♥\033[32m)༻\n"

$(B_NAME): $(B_OBJS) $(B_INCLUDE)
	@make -C ./libft --silent
	@$(CC) -o $(B_NAME) $(B_OBJS) $(LIBFT)
	@echo "\033[32mCHECKER Compiled! ༺ (\033[31m♥\033[32m_\033[31m♥\033[32m)༻\n"


clean:
	$(RM) ./libft/*.o
	$(RM) $(OBJS) $(B_OBJS)

fclean: clean
	$(RM) $(NAME) $(B_NAME) $(LIBFT)
	@echo "\033[32mEverything is fcleaned! ✓ (\033[31m>_<\033[32m)\n"

re: fclean all

.PHONY: all clean fclean re