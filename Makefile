# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yfuentes <yfuentes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/18 11:46:10 by yfuentes          #+#    #+#              #
#    Updated: 2022/08/01 13:07:09 by yfuentes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= src/push_swap.c \
			src/init_stack.c \
			src/push_swap_aux.c \
			src/sort_stacks.c \
			src/radix.c \
			src/handle_double_list.c \
			src/check_args.c \
			src/print_error.c \
			src/operations/swap.c \
			src/operations/reverse_rotate.c \
			src/operations/push.c \
			src/operations/rotate.c

SRCS_BONUS	= bonus/checker.c \
			src/init_stack.c \
			src/push_swap_aux.c \
			src/handle_double_list.c \
			src/check_args.c \
			src/print_error.c \
			src/operations/swap.c \
			src/operations/reverse_rotate.c \
			src/operations/push.c \
			src/operations/rotate.c  \
			get_next_line/get_next_line_utils.c \
			get_next_line/get_next_line.c

NAME	= push_swap
NAME_BONUS	= checker
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
CC	= gcc
AR = ar rcs
INCLUDE = -I includes/
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

.c.o :
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $(<:.c=.o)

all:	$(NAME)

bonus:	$(NAME_BONUS)

$(NAME):	$(OBJS)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(INCLUDE) -o $(NAME) $(OBJS) -L libft -lft

$(NAME_BONUS):	$(OBJS_BONUS)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(INCLUDE) -o $(NAME_BONUS) $(OBJS_BONUS) -L libft -lft
		
clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean:		clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME) $(NAME_BONUS)
	
re:		fclean all bonus

.PHONY: all, clean, fclean, re, bonus