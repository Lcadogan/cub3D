# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcadogan <lcadogan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/04 16:45:47 by lcadogan          #+#    #+#              #
#    Updated: 2021/04/19 15:04:19 by lcadogan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= ft_memset.c ft_strlen.c ft_atoi.c ft_bzero.c ft_memcpy.c \
		  ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlcpy.c\
		  ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c\
		  ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
		  ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c\
		  ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c\
		  ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_split.c\
		  get_next_line.c ft_lstadd_back.c ft_lstnew.c ft_lstlast.c\
		  ft_lstsize.c\

.c.o:	
		$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

OBJ		= $(SRC:.c=.o)

CC		= gcc

AR		= ar rc

RM		= rm -f

FLAGS	= -Wall -Wextra -Werror

NAME	= libft.a

$(NAME):	$(OBJ)
		$(AR) $(NAME) $(OBJ)

all:	$(NAME)

clean:		
		$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re 
