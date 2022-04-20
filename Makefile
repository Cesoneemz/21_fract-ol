# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 16:28:27 by wlanette          #+#    #+#              #
#    Updated: 2022/04/20 14:29:58 by wlanette         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= fractol
SRCS				= ./srcs/main.c ./srcs/ft_keys_treatment.c ./srcs/ft_fractol_initialization.c \
					  ./srcs/ft_generate_color.c ./srcs/ft_fractol_formula.c ./srcs/ft_fractol_mouse.c
OBJS				= $(SRCS:.c=.o)

LIBFT				= ./includes/libft/libft.a

FT_PRINTF			= ./includes/ft_printf/libftprintf.a

INCLUDE				= ./includes/
INCLUDES_HEADER		= ./includes/fractol.h

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I$(INCLUDE)
RM			= rm -rf

all:		$(NAME)

$(NAME):	$(OBJS) $(INCLUDES_HEADER) $(LIBFT) $(FT_PRINTF)
			$(CC) $(CFLAGS) $(OBJS) -L minilibx -lmlx -framework OpenGL $(LIBFT) $(FT_PRINTF) -framework AppKit -o $(NAME)

$(LIBFT):
			make bonus -C ./includes/libft/

$(FT_PRINTF):
			make -C ./includes/ft_printf/

clean:		
			make clean -C ./includes/libft/
			make clean -C ./includes/ft_printf/
			$(RM) $(OBJS)

fclean:		clean
			make fclean -C ./includes/libft/
			make fclean -C ./includes/ft_printf/
			$(RM) $(NAME)

re:			fclean all 

.PHONY:		all clean fclean re