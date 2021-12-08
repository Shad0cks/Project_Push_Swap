LIBFT_PATH		=	libft
LIBFT			=	$(LIBFT_PATH)/libft.a

SOURCES_FILES	=	main.c \
					op1.c \
					op2.c \
					op3.c \
					debug.c \
					realloc.c \
					algo.c \
					binary_conv.c \
					sort_small.c

SOURCES_DIR		=	source

HEADER			=	include/header.h

SOURCES			=	$(addprefix $(SOURCES_DIR)/, $(SOURCES_FILES))

OBJECTS			= 	$(SOURCES:.c=.o)

NAME			=	push_swap

CC				=	clang
RM				=	rm -f

CFLAGS			=	-Wall -Wextra -Werror

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:			$(NAME)

$(NAME):		$(LIBFT) $(OBJECTS) $(HEADER)
				$(CC) $(CFLAGS) $(LIBFT) $(OBJECTS) -o $(NAME)

$(LIBFT):
				$(MAKE) -C $(LIBFT_PATH)

clean:
				$(MAKE) -C $(LIBFT_PATH) clean
				$(RM) $(OBJECTS)

fclean:			clean
				$(MAKE) -C $(LIBFT_PATH) fclean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re