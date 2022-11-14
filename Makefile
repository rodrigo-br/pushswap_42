SRCS	=	main.c ft_atolli.c ft_n_in.c validators.c \
			libft_42/libft/bonus/ft_lstadd_back_int.c \
			libft_42/libft/bonus/ft_lstadd_front_int.c \
			libft_42/libft/bonus/ft_lstclear_int.c \
			libft_42/libft/bonus/ft_lstdelone_int.c \
			libft_42/libft/bonus/ft_lstiter_int.c \
			libft_42/libft/bonus/ft_lstiter_int.c \
			libft_42/libft/bonus/ft_lstlast_int.c \
			libft_42/libft/bonus/ft_lstmap_int.c \
			libft_42/libft/bonus/ft_lstnew_int.c \
			libft_42/libft/bonus/ft_lstsize_int.c \
			push.c rotate.c sort.c swap.c\
			ft_str_is_equal.c simplifier.c mappers.c \


OBJS	=	${SRCS:.c=.o}

NAME	=	push_swap.a

H_SRC	=	push_swap.h

FLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

.c.o:
			cc ${FLAGS} -c $< -o ${<:.c=.o} -I.

$(NAME):	${OBJS} ${H_SRC}
			make -C ./libft_42
			mv ./libft_42/libft.a ./$(NAME)
			ar -rcs $@ $^
			cc -g3 main.c push_swap.a -o push_swap

all: 		${NAME}

clean:
			${RM} ${OBJS}
			make clean -C ./libft_42

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
