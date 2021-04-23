NAME		=	libasm.a
SRCS		=	ft_strlen.s \
				ft_strcmp.s \
				ft_strcpy.s \
				ft_write.s \
				ft_read.s \
				ft_strdup.s
OBJS		=	$(SRCS:.s=.o)
ASM			=	nasm
FLAG		=	-f elf64

%.o: %.s
			$(ASM) $(FLAG) $< -o $@

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

all:	$(NAME)

clean:
		rm -f $(OBJS)

test:	all
		clang -Wall -Wextra -Werror main.c libasm.a -o test

fclean:	clean
		rm -f $(NAME)
		rm -f test
		rm -f *.txt

re:		fclean all


.PHONY: 	all clean fclean re test
