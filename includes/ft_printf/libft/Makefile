# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wlanette <wlanette@student.21-school.      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/12 15:48:37 by wlanette          #+#    #+#              #
#    Updated: 2021/10/12 15:48:42 by wlanette         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_isalpha.c ft_isdigit.c ft_isalnum.c \
			  ft_isascii.c ft_isprint.c ft_strlen.c \
			  ft_memset.c ft_bzero.c ft_memcpy.c \
			  ft_memmove.c ft_strlcpy.c ft_strlcat.c \
			  ft_toupper.c ft_tolower.c ft_strchr.c \
			  ft_strrchr.c ft_strncmp.c ft_memchr.c \
			  ft_memcmp.c ft_strnstr.c ft_atoi.c \
			  ft_calloc.c ft_strdup.c ft_substr.c \
			  ft_strjoin.c ft_strtrim.c ft_split.c \
			  ft_itoa.c ft_strmapi.c ft_striteri.c \
			  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
			  ft_putnbr_fd.c

SRCS_BONUS	= ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
			  ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
			  ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJS		= $(patsubst %.c,%.o,$(SRCS))
OBJS_BONUS	= $(patsubst %.c,%.o,$(SRCS_BONUS))
D_FILES		= $(patsubst %.c,%.d,$(SRCS) $(SRCS_BONUS))
NAME		= libft.a
LIBC		= ar rcs
CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror
OPTFLAGS	= -O2

$(NAME):	${OBJS}
			${LIBC} ${NAME} $?

all:		${NAME}

%.o : %.c
			${CC} ${CFLAGS} ${OPTFLAGS} -c $< -o $@ -MD

include $(wildcard ${D_FILES})

clean:
			${RM} ${OBJS} ${OBJS_BONUS} ${D_FILES}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

bonus:
			@make all
			@make OBJS="$(OBJS_BONUS)" all

.PHONY:		all clean fclean re bonus
