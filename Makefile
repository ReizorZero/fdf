NAME = fdf

SRCF = main.c read_file.c operate.c catch_err.c get_next_line.c drawer.c draw_proj.c free_all.c ft_arraydel.c readncheck.c

CC = gcc

CFLAG = -Wall -Wextra -Werror

LFLAG = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
	make -C libft/ fclean && make -C libft/
	$(CC) $(CFLAG) $(LFLAG) -o $(NAME) $(SRCF) libft/libft.a

clean:
	make -C libft/ clean
	/bin/rm -f *.o

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all