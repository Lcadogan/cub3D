NAME	= cub3D

HEADER	= includes/cub3D.h

LIBFTS	=	Libft/ft_memset.c\
			Libft/ft_strlen.c\
			Libft/ft_atoi.c\
			Libft/ft_bzero.c\
			Libft/ft_memcpy.c\
			Libft/ft_memccpy.c\
			Libft/ft_memmove.c\
			Libft/ft_memchr.c\
			Libft/ft_memcmp.c\
			Libft/ft_strlcpy.c\
			Libft/ft_strlcat.c\
			Libft/ft_strchr.c\
			Libft/ft_strrchr.c\
			Libft/ft_strnstr.c\
			Libft/ft_strncmp.c\
			Libft/ft_isalpha.c\
			Libft/ft_isdigit.c\
			Libft/ft_isalnum.c\
			Libft/ft_isascii.c\
			Libft/ft_isprint.c\
			Libft/ft_toupper.c\
			Libft/ft_tolower.c\
			Libft/ft_calloc.c\
			Libft/ft_strdup.c\
			Libft/ft_substr.c\
			Libft/ft_strjoin.c\
			Libft/ft_strtrim.c\
			Libft/ft_itoa.c\
			Libft/ft_strmapi.c\
			Libft/ft_putchar_fd.c\
			Libft/ft_putstr_fd.c\
			Libft/ft_putendl_fd.c\
			Libft/ft_putnbr_fd.c\
			Libft/ft_split.c\
			Libft/get_next_line.c\
			Libft/ft_lstadd_back.c\
			Libft/ft_lstnew.c\
			Libft/ft_lstlast.c\
			Libft/ft_lstsize.c\

SRC		= src/main.c\
			src/bitmap.c\
			src/check_valid.c\
			src/check_valid2.c\
			src/key.c\
			src/key2.c\
			src/parcer_color.c\
			src/parcer_map.c\
			src/parcer_resol.c\
			src/parcer_text.c\
			src/raycaster.c\
			src/render_map.c\
			src/sprite.c\
			src/text.c\
			src/text2.c\
			src/tools.c\
			src/init_str.c

CC		= gcc

RM		= rm -f

MAKE	= make

LIBFT	= libft.a

LIBS	= -lmlx -framework OpenGL -framework AppKit

MLX		= libmlx.a

FLAGS	= -g -Wall -Wextra -Werror

all:	$(NAME)
 
$(NAME):	$(SRC) $(HEADER) $(LIBFTS)
			$(MAKE) -C mlx
			$(MAKE) -C Libft
			${CC} ${FLAGS} -o ${NAME} ${SRC} ${LIBS} Libft/libft.a mlx/libmlx.a

clean:
			$(MAKE) clean -C ./Libft
			$(MAKE) clean -C ./mlx
			$(RM) bitmap.bmp

fclean:		clean
			$(RM) $(NAME) $(MLX)
			$(RM) ./Libft/libft.a

re:			fclean all

.PHONY:		all clean fclean re
