# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wlanette <wlanette@student.21-school.      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/14 17:37:46 by wlanette          #+#    #+#              #
#   Updated: 2021/10/18 20:01:42 by                  ###   ########.fr       # #
#                                                                              #
# **************************************************************************** #

SRCS 	 = 	./srcs/ft_printf.c ./srcs/ft_utils.c ./srcs/ft_validators.c \
			./srcs/ft_char_treatment.c ./srcs/ft_string_treatment.c \
			./srcs/ft_putstr.c ./srcs/ft_pointer_treatment.c \
			./srcs/ft_integer_treatment.c ./srcs/ft_uint_treatment.c ./srcs/ft_uint_itoa.c \
			./srcs/ft_convert_to_base.c ./srcs/ft_hex_treatment.c
OBJS 	 = 	$(patsubst %.c,%.o,$(SRCS))
D_FILES  = 	$(patsubst %.c,%.d,$(SRCS))

NAME 	 =	libftprintf.a
LIBC 	 =	ar rcs
RM   	 =	rm -rf

CC		 = 	clang
CFLAGS   =	-Wall -Wextra -Werror
OPTFLAGS = 	-O2


$(NAME):	$(OBJS)
			$(MAKE) bonus -C ./libft
			cp libft/libft.a $(NAME)
			$(LIBC) $(NAME) $(OBJS)

all:		$(NAME)
			
%.o : %.c
			$(CC) $(CFLAGS) $(OPTFLAGS) -c $< -o $@ -MD

include $(wildcard $(D_FILES))

clean:
			$(MAKE) clean -C ./libft
			$(RM) $(OBJS) $(D_FILES)

fclean:		clean
			$(MAKE) fclean -C ./libft
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
